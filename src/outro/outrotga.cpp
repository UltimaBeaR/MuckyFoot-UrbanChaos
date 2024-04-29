//
// Loads in 32-bit RGBA uncompressed TGAs.
//

#include "always.h"
#include "tga.h"

Outro_TGA_Info TGA_FileLoad_Error(Outro_TGA_Info& ans, FILE*& handle, const CBYTE*& file)
{

    TRACE("File error loading TGA file %s\n", *file);
    fclose(handle);
    ans.valid = FALSE;
    return ans;
}

Outro_TGA_Info Outro_TGA_load(
    const CBYTE* file,
    SLONG max_width,
    SLONG max_height,
    Outro_TGA_Pixel* data)
{
    SLONG i;

    UBYTE red;
    UBYTE green;
    UBYTE blue;

    SLONG tga_width;
    SLONG tga_height;
    SLONG tga_pixel_depth;
    SLONG tga_image_type;
    SLONG tga_id_length;

    UBYTE header[18];
    UBYTE rubbish;
    UBYTE no_alpha;

    FILE* handle;

    Outro_TGA_Info ans {};

    //
    // Open the file.
    //

    handle = fopen(file, "rb");

    if (handle == NULL) {
        TRACE("Could not open TGA file %s", file);
        ans.valid = FALSE;
        return ans;
    }

    //
    // Read the header.
    //

    if (fread(header, sizeof(UBYTE), 18, handle) != 18)
        return TGA_FileLoad_Error(ans, handle, file);

    //
    // Extract info from the header.
    //

    tga_id_length = header[0x0];
    tga_image_type = header[0x2];
    tga_width = header[0xc] + header[0xd] * 256;
    tga_height = header[0xe] + header[0xf] * 256;
    tga_pixel_depth = header[0x10];

    //
    // Is this a valid tga file?
    //

    ans.valid = FALSE;
    ans.width = tga_width;
    ans.height = tga_height;
    ans.flag = 0;

    if (tga_image_type != 2) {
        TRACE("Tga must be true colour and uncompressed.\n");
        fclose(handle);
        return ans;
    }

    if (tga_pixel_depth != 32 && tga_pixel_depth != 24) {
        TRACE("Tga must be 32-bit or 24-bit (24-bit + 8-bit alpha channel)\n");
        fclose(handle);
        return ans;
    }

    if (tga_width > max_width || tga_height > max_height) {
        TRACE("Invalid dimensions:\n\tWanted <= %d x %d\n\tGot       %d x %d\n", max_width, max_height, tga_width, tga_height);
        fclose(handle);
        return ans;
    }

    //
    // The tga file is valid...
    //

    ans.valid = TRUE;

    //
    // Skip past the image identification field.
    //

    for (i = 0; i < tga_id_length; i++) {
        if (fread(&rubbish, sizeof(UBYTE), 1, handle) != 1)
            return TGA_FileLoad_Error(ans, handle, file);
    }

    //
    // Load in the data.
    //

    if (tga_pixel_depth == 32) {
        if (fread(data, sizeof(Outro_TGA_Pixel), tga_width * tga_height, handle) != tga_width * tga_height)
            return TGA_FileLoad_Error(ans, handle, file);

        no_alpha = FALSE;
    } else {
        //
        // We have to load a pixel in at a time to add the NULL alpha channel.
        //

        for (i = 0; i < tga_width * tga_height; i++) {
            if (fread(&blue, sizeof(UBYTE), 1, handle) != 1)
                return TGA_FileLoad_Error(ans, handle, file);
            if (fread(&green, sizeof(UBYTE), 1, handle) != 1)
                return TGA_FileLoad_Error(ans, handle, file);
            if (fread(&red, sizeof(UBYTE), 1, handle) != 1)
                return TGA_FileLoad_Error(ans, handle, file);

            data[i].red = red;
            data[i].green = green;
            data[i].blue = blue;
            data[i].alpha = 255;
        }

        no_alpha = TRUE;
    }

    fclose(handle);

    //
    // Loaded in the tga. Sets the flags- is it grayscale?
    //

    if (!no_alpha) {
        ans.flag |= TGA_FLAG_ONE_BIT_ALPHA;

        for (i = 0; i < tga_width * tga_height; i++) {
            if (data[i].alpha != 255) {
                //
                // Found alpha channel data.
                //

                ans.flag |= TGA_FLAG_CONTAINS_ALPHA;

                if (ans.flag != 0) {
                    ans.flag &= ~TGA_FLAG_ONE_BIT_ALPHA;

                    break;
                }
            }
        }

        if (!(ans.flag & TGA_FLAG_CONTAINS_ALPHA)) {
            ans.flag &= ~TGA_FLAG_ONE_BIT_ALPHA;
        }
    }

    //
    // Is it grayscale?
    //

    ans.flag |= TGA_FLAG_GRAYSCALE;

    for (i = 0; i < tga_width * tga_height; i++) {
        if (data[i].red != data[i].green || data[i].red != data[i].blue || data[i].green != data[i].blue) {
            ans.flag &= ~TGA_FLAG_GRAYSCALE;

            break;
        }
    }

    return ans;
}
