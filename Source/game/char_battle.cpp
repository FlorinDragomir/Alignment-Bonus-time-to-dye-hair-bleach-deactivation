//search
void CHARACTER::UpdateAlignment(int iAmount)
{
	bool bShow = false;

	if (m_iAlignment == m_iRealAlignment)
		bShow = true;

	int i = m_iAlignment / 10;

	m_iRealAlignment = MINMAX(-200000, m_iRealAlignment + iAmount, 200000);

	if (bShow)
	{
		m_iAlignment = m_iRealAlignment;

		if (i != m_iAlignment / 10)
			UpdatePacket();
	}

//add
	if (FindAffect(ALIGNMENT_BONUS_1))
	{
		if (GetRealAlignment() != NAME_ALIGNMENT_1)
			RemoveAffect(ALIGNMENT_BONUS_1);
	}
	
	if (FindAffect(ALIGNMENT_BONUS_4))
	{
		if (GetRealAlignment() != NAME_ALIGNMENT_2)
			RemoveAffect(ALIGNMENT_BONUS_4);
	}
	
	if (FindAffect(ALIGNMENT_BONUS_3))
	{
		if (GetRealAlignment() != NAME_ALIGNMENT_1)
			RemoveAffect(ALIGNMENT_BONUS_3);
	}
	
	if (FindAffect(ALIGNMENT_BONUS_2))
	{
		if (GetRealAlignment() != NAME_ALIGNMENT_2)
			RemoveAffect(ALIGNMENT_BONUS_2);
	}
	
	if (FindAffect(ALIGNMENT_BONUS_5))
	{
		if (GetRealAlignment() != NAME_ALIGNMENT_3)
			RemoveAffect(ALIGNMENT_BONUS_5);
	}
	
	if (FindAffect(ALIGNMENT_BONUS_6))
	{
		if (GetRealAlignment() != NAME_ALIGNMENT_3)
			RemoveAffect(ALIGNMENT_BONUS_6);
	}
	
	if (FindAffect(ALIGNMENT_BONUS_7))
	{
		if (GetRealAlignment() < NAME_ALIGNMENT_4)
			RemoveAffect(ALIGNMENT_BONUS_7);
	}
	
	if (FindAffect(ALIGNMENT_BONUS_8))
	{
		if (GetRealAlignment() < NAME_ALIGNMENT_4)
			RemoveAffect(ALIGNMENT_BONUS_8);
	}

	if (GetRealAlignment() >= NAME_ALIGNMENT_1 && GetRealAlignment() < NAME_ALIGNMENT_2)
	{
		AddAffect(ALIGNMENT_BONUS_1, POINT_ATTBONUS_HUMAN, 3, 0, ALIGNMENT_TIME, 0, true);
		AddAffect(ALIGNMENT_BONUS_3, POINT_MAX_HP, 500, 0, ALIGNMENT_TIME, 0, true);
	}
	
	if (GetRealAlignment() >= NAME_ALIGNMENT_2 && GetRealAlignment() < NAME_ALIGNMENT_3)
	{
		AddAffect(ALIGNMENT_BONUS_2, POINT_ATTBONUS_HUMAN, 6, 0, ALIGNMENT_TIME, 0, true);
		AddAffect(ALIGNMENT_BONUS_4, POINT_MAX_HP, 1000, 0, ALIGNMENT_TIME, 0, true);
	}
	
	if (GetRealAlignment() >= NAME_ALIGNMENT_3 && GetRealAlignment() < NAME_ALIGNMENT_4)
	{
		AddAffect(ALIGNMENT_BONUS_5, POINT_ATTBONUS_HUMAN, 9, 0, ALIGNMENT_TIME, 0, true);
		AddAffect(ALIGNMENT_BONUS_6, POINT_MAX_HP, 1500, 0, ALIGNMENT_TIME, 0, true);
	}
	
	if (GetRealAlignment() >= NAME_ALIGNMENT_4)
	{
		AddAffect(ALIGNMENT_BONUS_7, POINT_ATTBONUS_HUMAN, 12, 0, ALIGNMENT_TIME, 0, true);
		AddAffect(ALIGNMENT_BONUS_8, POINT_MAX_HP, 2000, 0, ALIGNMENT_TIME, 0, true);
	}
	
