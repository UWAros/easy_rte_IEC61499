
//This file should be called F_ab5.c
//This is autogenerated code. Edit by hand at your peril!
#include "F_ab5.h"

void ab5_init_all_vars(enforcervars_ab5_t* me, inputs_ab5_t* inputs, outputs_ab5_t* outputs) {
	//set any input vars with default values
	
	//set any output vars with default values
	

	
	me->_policy_AB5_state = POLICY_STATE_ab5_AB5_s0;
	//input policy internal vars
	
	me->v = 0;
	
	
}

void ab5_run_via_enforcer(enforcervars_ab5_t* me, inputs_ab5_t* inputs, outputs_ab5_t* outputs) {
	//run the policies in reverse order for the inputs (last policies have highest priority)
	
	 ab5_run_input_enforcer_AB5(me, inputs);
	

	ab5_run(inputs, outputs);

	//run policies in specified order for outputs
	ab5_run_output_enforcer_AB5(me, inputs,outputs);
	
}


//input policies

//INPUT POLICY AB5 BEGIN
//This will run the input enforcer for ab5's policy AB5
void ab5_run_input_enforcer_AB5(enforcervars_ab5_t* me, inputs_ab5_t* inputs) {
	switch(me->_policy_AB5_state) {
		case POLICY_STATE_ab5_AB5_s0:
			
			if( !(inputs->A) || inputs->A) {
				//transition s0 -> violation on not (A) or A
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				
			} 
			
			break;

		case POLICY_STATE_ab5_AB5_s1:
			
			if(me->v >= 5) {
				//transition s1 -> violation on v >= 5
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				
			} 
			if(inputs->A) {
				//transition s1 -> violation on A
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				inputs->A = 0;
				
			} 
			
			break;

		
	}
}

//INPUT POLICY AB5 END



//output policies

//OUTPUT POLICY AB5 BEGIN
//This will run the input enforcer for ab5's policy AB5
void ab5_run_output_enforcer_AB5(enforcervars_ab5_t* me, inputs_ab5_t* inputs, outputs_ab5_t* outputs) {
	//advance timers
	
	me->v++;
	
	//run enforcer
	switch(me->_policy_AB5_state) {
		case POLICY_STATE_ab5_AB5_s0:
			
			if(( !(inputs->A) && outputs->B) || (inputs->A && outputs->B)) {
				//transition s0 -> violation on ( ( !A and B ) or ( A and B ) )
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				outputs->B = 0;
				
			} 

			break;

		case POLICY_STATE_ab5_AB5_s1:
			
			if(me->v >= 5) {
				//transition s1 -> violation on v >= 5
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				outputs->B = 1;
				
			} 
			if(inputs->A) {
				//transition s1 -> violation on A
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				
			} 

			break;

		
	}

	//select transition to advance state
	switch(me->_policy_AB5_state) {
		case POLICY_STATE_ab5_AB5_s0:
			
			if( !(inputs->A) && !(outputs->B)) {
				//transition s0 -> s0 on ( !A and !B )
				me->_policy_AB5_state = POLICY_STATE_ab5_AB5_s0;
				//set expressions
				
				me->v = 0;
				break;
			} 
			if(inputs->A && !(outputs->B)) {
				//transition s0 -> s1 on ( A and !B )
				me->_policy_AB5_state = POLICY_STATE_ab5_AB5_s1;
				//set expressions
				
				me->v = 0;
				break;
			} 
			if(( !(inputs->A) && outputs->B) || (inputs->A && outputs->B)) {
				//transition s0 -> violation on ( ( !A and B ) or ( A and B ) )
				me->_policy_AB5_state = POLICY_STATE_ab5_AB5_violation;
				//set expressions
				
				break;
			} 
			
			//ensure a transition was taken in this state
			assert(false && "ab5_AB5_s0 must take a transition"); //if we are still here, then no transition was taken and we are no longer satisfying liveness

			break;

		case POLICY_STATE_ab5_AB5_s1:
			
			if(( !(inputs->A) && !(outputs->B)) && me->v < 5) {
				//transition s1 -> s1 on ( !A and !B and v < 5 )
				me->_policy_AB5_state = POLICY_STATE_ab5_AB5_s1;
				//set expressions
				
				break;
			} 
			if( !(inputs->A) && outputs->B) {
				//transition s1 -> s0 on ( !A and B )
				me->_policy_AB5_state = POLICY_STATE_ab5_AB5_s0;
				//set expressions
				
				break;
			} 
			if(me->v >= 5) {
				//transition s1 -> violation on v >= 5
				me->_policy_AB5_state = POLICY_STATE_ab5_AB5_violation;
				//set expressions
				
				break;
			} 
			if(inputs->A) {
				//transition s1 -> violation on A
				me->_policy_AB5_state = POLICY_STATE_ab5_AB5_violation;
				//set expressions
				
				break;
			} 
			
			//ensure a transition was taken in this state
			assert(false && "ab5_AB5_s1 must take a transition"); //if we are still here, then no transition was taken and we are no longer satisfying liveness

			break;

		
	}

	//ensure we did not violate (i.e. we did not enter violation state)
	assert(me->_policy_AB5_state != POLICY_STATE_ab5_AB5_violation);
}

//OUTPUT POLICY AB5 END



//This function is provided in "F_ab5.c"
//It will check the state of the enforcer monitor code
//It returns one of the following:
//0: currently true (safe)
//1: always true (safe)
//-1: currently false (unsafe)
//-2: always false (unsafe)
//It will need to do some reachability analysis to achieve this

