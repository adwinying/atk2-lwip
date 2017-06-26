----------------------------------------------------------------------
-- Copyright (c) 2009 Shinya Honda (honda@ertl.jp)
--
-- sysver.vhd
--
-- @(#) $Id: LoadLStoreCHw.vhd 1465 2009-08-27 05:39:47Z honda $
----------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity sysver is
	generic (
		VER1_ROM_REG_VALUE : std_logic_vector(31 downto 0) := X"0000_0000";
		VER2_ROM_REG_VALUE : std_logic_vector(31 downto 0) := X"0000_0000";
		VER3_ROM_REG_VALUE : std_logic_vector(31 downto 0) := X"0000_0000";
		VER4_ROM_REG_VALUE : std_logic_vector(31 downto 0) := X"0000_0000";
		VER5_RAM_REG_VALUE : std_logic_vector(31 downto 0) := X"0000_0000";
		VER6_RAM_REG_VALUE : std_logic_vector(31 downto 0) := X"0000_0000";
		VER7_RAM_REG_VALUE : std_logic_vector(31 downto 0) := X"0000_0000";
		VER8_RAM_REG_VALUE : std_logic_vector(31 downto 0) := X"0000_0000"
	);  
	port(
		clk         : in  std_logic;
		reset_n     : in  std_logic;
		chipselect  : in  std_logic;
		address     : in  std_logic_vector(2 downto 0);
		write       : in  std_logic;
		writedata   : in  std_logic_vector(31 downto 0);
		read        : in  std_logic;
		readdata    : out std_logic_vector(31 downto 0);
		byteenable  : in  std_logic_vector(3 downto 0);
		waitrequest : out std_logic
	);
end sysver;


----------------------------------------------------------------------
-- Architecture section
----------------------------------------------------------------------
architecture rtl of sysver is
	signal ver1_select   : std_logic;
	signal ver2_select   : std_logic;
	signal ver3_select   : std_logic;
	signal ver4_select   : std_logic;
	signal ver5_select   : std_logic;
	signal ver6_select   : std_logic;
	signal ver7_select   : std_logic;
	signal ver8_select   : std_logic;

	signal ver5_reg : std_logic_vector(31 downto 0);
	signal ver6_reg : std_logic_vector(31 downto 0);
	signal ver7_reg : std_logic_vector(31 downto 0);
	signal ver8_reg : std_logic_vector(31 downto 0);

begin

	-- 未使用信号
	waitrequest <= '0';

	-- セレクタ
	process(address, chipselect)
	begin
		ver1_select   <= '0';
		ver2_select   <= '0';
		ver3_select   <= '0';
		ver4_select   <= '0';
		ver5_select   <= '0';
		ver6_select   <= '0';
		ver7_select   <= '0';
		ver8_select   <= '0';

		if chipselect = '1' then
			case  address is 
				when "000" => ver1_select <= '1'; -- 0x00
				when "001" => ver2_select <= '1'; -- 0x04
				when "010" => ver3_select <= '1'; -- 0x08
				when "011" => ver4_select <= '1'; -- 0x0C
				when "100" => ver5_select <= '1'; -- 0x10
				when "101" => ver6_select <= '1'; -- 0x14
				when "110" => ver7_select <= '1'; -- 0x18
				when "111" => ver8_select <= '1'; -- 0x1C
				when others => null;
			end case;
		end if;
	end process;

	-- リードマルチプレクサ
	process(ver1_select,ver2_select,ver3_select,ver4_select,
			ver5_select,ver6_select,ver7_select,ver8_select)
	begin
		readdata <= (others=>'0');
		if ver1_select = '1' then
			readdata <= VER1_ROM_REG_VALUE;
		elsif ver2_select = '1' then
			readdata <= VER2_ROM_REG_VALUE;
		elsif ver3_select = '1' then
			readdata <= VER3_ROM_REG_VALUE;
		elsif ver4_select = '1' then
			readdata <= VER4_ROM_REG_VALUE;
		elsif ver5_select = '1' then
			readdata <= ver5_reg;
		elsif ver6_select = '1' then
			readdata <= ver6_reg;
		elsif ver7_select = '1' then
			readdata <= ver7_reg;
		elsif ver8_select = '1' then
			readdata <= ver8_reg;
		end if;
	end process;

	process(clk, reset_n)
	begin
		if ( reset_n = '0' ) then
			ver5_reg <= VER5_RAM_REG_VALUE;
		elsif( clk = '1' and clk'event ) then
			if (write = '1' and ver5_select = '1') then
				ver5_reg <= writedata;
			end if; 
		end if;
	end process;

	process(clk, reset_n)
	begin
		if ( reset_n = '0' ) then
			ver6_reg <= VER6_RAM_REG_VALUE;
		elsif( clk = '1' and clk'event ) then
			if (write = '1' and ver6_select = '1') then
				ver6_reg <= writedata;
			end if; 
		end if;
	end process;

	process(clk, reset_n)
	begin
		if ( reset_n = '0' ) then
			ver7_reg <= VER7_RAM_REG_VALUE;
		elsif( clk = '1' and clk'event ) then
			if (write = '1' and ver7_select = '1') then
				ver7_reg <= writedata;
			end if; 
		end if;
	end process;

	process(clk, reset_n)
	begin
		if ( reset_n = '0' ) then
			ver8_reg <= VER8_RAM_REG_VALUE;
		elsif( clk = '1' and clk'event ) then
			if (write = '1' and ver8_select = '1') then
				ver8_reg <= writedata;
			end if; 
		end if;
	end process;


end rtl;
