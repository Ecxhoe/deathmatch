void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer

{
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
		Class.CastTo(m_player, playerEnt);
		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
		}

		player.SetQuickBarEntityShortcut(mag, 1, true);
	}

	EntityAI srsClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_SRSA2");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "Rev_Mag_SRSA2_10rnd", 5);

		return gun;
	}

	EntityAI m2010Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_M2010_Blue");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "Rev_Mag_M2010_10rnd", 5);

		return gun;
	}

	EntityAI m10sakoClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_SAKOTRG");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "BO_Mag_SAKOTRG_5rnd", 5);

		return gun;
	}

	EntityAI delta5Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_Delta5_Camo9");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "BO_Mag_Delta5_10rnd", 5);

		return gun;
	}

	EntityAI m200Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_M200_Black");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "BO_Mag_M200_7rnd", 5);

		return gun;
	}

	EntityAI m300Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_M300");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "BO_Mag_M300_7rnd", 5);

		return gun;
	}

	EntityAI m96Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_M96");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "Rev_Mag_M96_5rnd", 5);

		return gun;
	}

	EntityAI cdx50Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_CDX50");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "Rev_Mag_CDX50_5rnd", 5);

		return gun;
	}

	EntityAI ax50Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("CPB_AX50_Black");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "CPB_AX50_Magazine", 5);

		return gun;
	}

	EntityAI vsskClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("JebsGuns_VSSK");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "JebsGuns_Mag_VSSK_5rnd", 5);

		return gun;
	}

	EntityAI osv96Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_OSV");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "BO_Mag_OSV_5rnd", 5);

		return gun;
	}

	EntityAI gm6lynxClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_GM6Lynx");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "BO_Mag_GM6Lynx_5rnd", 5);

		return gun;
	}

	EntityAI m82Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("CPB_Barret");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "CPB_Barret_Magazine", 5);

		return gun;
	}

	EntityAI m107Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("A2M107");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "A2M107_Magazine", 5);

		return gun;
	}

	EntityAI as50Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("A2AS50");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "A2AS50_Magazine", 5);

		return gun;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		
		player.GetInventory().CreateInInventory("DryBag_Black");
		player.GetInventory().CreateInInventory("TrackSuitPants_Black");
		player.GetInventory().CreateInInventory("TrackSuitJacket_Black");
		player.GetInventory().CreateInInventory("AthleticShoes_Black");
		player.GetInventory().CreateInInventory("BandageDressing");

		EntityAI primary;
		EntityAI axe = player.GetInventory().CreateInInventory("FirefighterAxe");

		switch (Math.RandomInt(0, 15)) {
			case 0: primary = srsClass(player); break;
			case 1: primary = m2010Class(player); break;
			case 2: primary = m10sakoClass(player); break;
			case 3: primary = delta5Class(player); break;
			case 4: primary = m200Class(player); break;
			case 5: primary = m300Class(player); break;
			case 6: primary = m96Class(player); break;
			case 7: primary = cdx50Class(player); break;
			case 8: primary = ax50Class(player); break;
			case 9: primary = vsskClass(player); break;
			case 10: primary = osv96Class(player); break;
			case 11: primary = gm6lynxClass(player); break;
			case 12: primary = m82Class(player); break;
			case 13: primary = m82a1Class(player); break;
			case 14: primary = m107Class(player); break;
			case 15: primary = as50Class(player); break;
		}

		player.LocalTakeEntityToHands(primary);
		player.SetQuickBarEntityShortcut(primary, 0, true);
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
