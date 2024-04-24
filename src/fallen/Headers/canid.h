//
// Canids -- 4 legs, pointy teeth, tails, meat eaters, usually pack hunters,
//           non-retractable claws, and other things we've come to expect from
//           man's best friends and worst enemies: dogs, coyotes, wolves, that
//           sort of thing.
//

#pragma once

extern StateFunction CANID_state_function[];

void CANID_init(Thing* canid);
void CANID_normal(Thing* canid);
void CANID_register();

