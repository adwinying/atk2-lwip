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


// $Id: //acds/rel/13.1up/ip/merlin/altera_tristate_conduit_bridge/altera_tristate_conduit_bridge.sv.terp#1 $
// $Revision: #1 $
// $Date: 2013/11/05 $
// $Author: swbranch $

//Defined Terp Parameters


			    

`timescale 1 ns / 1 ns
  				      
module DE2_115_SOPC_tristate_conduit_bridge_flash (
     input  logic clk
    ,input  logic reset
    ,input  logic request
    ,output logic grant
    ,input  logic[ 22 :0 ] tcs_address_to_the_cfi_flash
    ,output  wire [ 22 :0 ] address_to_the_cfi_flash
    ,output logic[ 7 :0 ] tcs_tri_state_bridge_flash_data_in
    ,input  logic[ 7 :0 ] tcs_tri_state_bridge_flash_data
    ,input  logic tcs_tri_state_bridge_flash_data_outen
    ,inout  wire [ 7 :0 ]  tri_state_bridge_flash_data
    ,input  logic[ 0 :0 ] tcs_write_n_to_the_cfi_flash
    ,output  wire [ 0 :0 ] write_n_to_the_cfi_flash
    ,input  logic[ 0 :0 ] tcs_select_n_to_the_cfi_flash
    ,output  wire [ 0 :0 ] select_n_to_the_cfi_flash
    ,input  logic[ 0 :0 ] tcs_read_n_to_the_cfi_flash
    ,output  wire [ 0 :0 ] read_n_to_the_cfi_flash
		     
   );
   reg grant_reg;
   assign grant = grant_reg;
   
   always@(posedge clk) begin
      if(reset)
	grant_reg <= 0;
      else
	grant_reg <= request;      
   end
   


 // ** Output Pin address_to_the_cfi_flash 
 
    reg                       address_to_the_cfi_flashen_reg;     
  
    always@(posedge clk) begin
	 if( reset ) begin
	   address_to_the_cfi_flashen_reg <= 'b0;
	 end
	 else begin
	   address_to_the_cfi_flashen_reg <= 'b1;
	 end
     end		     
   
 
    reg [ 22 : 0 ] address_to_the_cfi_flash_reg;   

     always@(posedge clk) begin
	 address_to_the_cfi_flash_reg   <= tcs_address_to_the_cfi_flash[ 22 : 0 ];
      end
          
 
    assign 	address_to_the_cfi_flash[ 22 : 0 ] = address_to_the_cfi_flashen_reg ? address_to_the_cfi_flash_reg : 'z ;
        


 // ** Bidirectional Pin tri_state_bridge_flash_data 
   
    reg                       tri_state_bridge_flash_data_outen_reg;
  
    always@(posedge clk) begin
	 tri_state_bridge_flash_data_outen_reg <= tcs_tri_state_bridge_flash_data_outen;
     end
  
  
    reg [ 7 : 0 ] tri_state_bridge_flash_data_reg;   

     always@(posedge clk) begin
	 tri_state_bridge_flash_data_reg   <= tcs_tri_state_bridge_flash_data[ 7 : 0 ];
      end
         
  
    assign 	tri_state_bridge_flash_data[ 7 : 0 ] = tri_state_bridge_flash_data_outen_reg ? tri_state_bridge_flash_data_reg : 'z ;
       
  
    reg [ 7 : 0 ] 	tri_state_bridge_flash_data_in_reg;
								    
    always@(posedge clk) begin
	 tri_state_bridge_flash_data_in_reg <= tri_state_bridge_flash_data[ 7 : 0 ];
    end
    
  
    assign      tcs_tri_state_bridge_flash_data_in[ 7 : 0 ] = tri_state_bridge_flash_data_in_reg[ 7 : 0 ];
        


 // ** Output Pin write_n_to_the_cfi_flash 
 
    reg                       write_n_to_the_cfi_flashen_reg;     
  
    always@(posedge clk) begin
	 if( reset ) begin
	   write_n_to_the_cfi_flashen_reg <= 'b0;
	 end
	 else begin
	   write_n_to_the_cfi_flashen_reg <= 'b1;
	 end
     end		     
   
 
    reg [ 0 : 0 ] write_n_to_the_cfi_flash_reg;   

     always@(posedge clk) begin
	 write_n_to_the_cfi_flash_reg   <= tcs_write_n_to_the_cfi_flash[ 0 : 0 ];
      end
          
 
    assign 	write_n_to_the_cfi_flash[ 0 : 0 ] = write_n_to_the_cfi_flashen_reg ? write_n_to_the_cfi_flash_reg : 'z ;
        


 // ** Output Pin select_n_to_the_cfi_flash 
 
    reg                       select_n_to_the_cfi_flashen_reg;     
  
    always@(posedge clk) begin
	 if( reset ) begin
	   select_n_to_the_cfi_flashen_reg <= 'b0;
	 end
	 else begin
	   select_n_to_the_cfi_flashen_reg <= 'b1;
	 end
     end		     
   
 
    reg [ 0 : 0 ] select_n_to_the_cfi_flash_reg;   

     always@(posedge clk) begin
	 select_n_to_the_cfi_flash_reg   <= tcs_select_n_to_the_cfi_flash[ 0 : 0 ];
      end
          
 
    assign 	select_n_to_the_cfi_flash[ 0 : 0 ] = select_n_to_the_cfi_flashen_reg ? select_n_to_the_cfi_flash_reg : 'z ;
        


 // ** Output Pin read_n_to_the_cfi_flash 
 
    reg                       read_n_to_the_cfi_flashen_reg;     
  
    always@(posedge clk) begin
	 if( reset ) begin
	   read_n_to_the_cfi_flashen_reg <= 'b0;
	 end
	 else begin
	   read_n_to_the_cfi_flashen_reg <= 'b1;
	 end
     end		     
   
 
    reg [ 0 : 0 ] read_n_to_the_cfi_flash_reg;   

     always@(posedge clk) begin
	 read_n_to_the_cfi_flash_reg   <= tcs_read_n_to_the_cfi_flash[ 0 : 0 ];
      end
          
 
    assign 	read_n_to_the_cfi_flash[ 0 : 0 ] = read_n_to_the_cfi_flashen_reg ? read_n_to_the_cfi_flash_reg : 'z ;
        

endmodule


