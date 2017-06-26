// (C) 2001-2014 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.



  
`timescale 1 ns / 1 ns

			 
module DE2_115_SOPC_tristate_conduit_pin_sharer_flash_pin_sharer (
 // ** Clock and Reset Connections
    input  logic clk
   ,input  logic reset

 // ** Arbiter Connections

 // *** Arbiter Grant Interface
   ,output logic ack
   ,input  logic [ 1 - 1 : 0 ] next_grant

// *** Arbiter Request Interface

    ,output logic arb_cfi_flash_tcm 
		
		     // ** Avalon TC Slave Interfaces




  // Slave Interface tcs0

    ,input  logic tcs0_request 
    ,output logic tcs0_grant   

  //cfi_flash.tcm signals
    ,input  logic[ 22 :0 ] tcs0_tcm_address_out
    ,input  logic[ 0 :0 ] tcs0_tcm_read_n_out
    ,input  logic[ 0 :0 ] tcs0_tcm_write_n_out
    ,output logic[ 7 :0 ]  tcs0_tcm_data_in
    ,input  logic[ 7 :0 ]  tcs0_tcm_data_out
    ,input  logic tcs0_tcm_data_outen
    ,input  logic[ 0 :0 ] tcs0_tcm_chipselect_n_out
		     
		     // ** Avalon TC Master Interface
    ,output logic request
    ,input  logic grant

		     // *** Passthrough Signals
		     
		     
                     // *** Shared Signals
		      	     
    ,output  logic[ 22 :0 ] address_to_the_cfi_flash
    ,output  logic[ 0 :0 ] write_n_to_the_cfi_flash
    ,input   logic[ 7  :0 ]  tri_state_bridge_flash_data_in
    ,output  logic[ 7  :0 ]  tri_state_bridge_flash_data
    ,output  logic tri_state_bridge_flash_data_outen
    ,output  logic[ 0 :0 ] select_n_to_the_cfi_flash
    ,output  logic[ 0 :0 ] read_n_to_the_cfi_flash

		     );

   function [1-1:0] getIndex;
      
      input [1-1:0] select;
      
      getIndex = 'h0;
      
      for(int i=0; i < 1; i = i + 1) begin
	 if( select[i] == 1'b1 )
           getIndex = i;
      end
      
   endfunction // getIndex

   logic[ 1 - 1 : 0 ] selected_grant;


   // Request Assignments

    assign arb_cfi_flash_tcm = tcs0_request;
   
   logic [ 1 - 1 : 0 ] concated_incoming_requests;
   
   
   assign 			      concated_incoming_requests = {						    
         tcs0_request 
				};
   
				       
   assign 			      request = | concated_incoming_requests;
  assign        tcs0_grant = selected_grant[0];

   
    // Perform Grant Selection						  
   always@(posedge clk, posedge reset) begin
     if(reset) begin
	selected_grant<=0;
	ack <= 0;
     end 
     else begin
       if(grant && (concated_incoming_requests[getIndex(selected_grant)] == 0 || selected_grant == 0 )) begin
	  if(~request)
	    selected_grant <= '0;
	  else
	    selected_grant <= next_grant;
	  
          ack<=1;
       end
       else begin
         ack<=0;
         selected_grant <= selected_grant;
       end
     end
   end // always@ (posedge clk, posedge reset)

// Passthrough Signals

  
// Renamed Signals
    assign address_to_the_cfi_flash = tcs0_tcm_address_out ;
    assign read_n_to_the_cfi_flash = tcs0_tcm_read_n_out ;
    assign write_n_to_the_cfi_flash = tcs0_tcm_write_n_out ;
    assign tcs0_tcm_data_in = tri_state_bridge_flash_data_in[7:0];
    assign tri_state_bridge_flash_data =  tcs0_tcm_data_out;
    assign tri_state_bridge_flash_data_outen = tcs0_tcm_data_outen;
    assign select_n_to_the_cfi_flash = tcs0_tcm_chipselect_n_out ;
  
// Shared Signals
  
endmodule   
					    



