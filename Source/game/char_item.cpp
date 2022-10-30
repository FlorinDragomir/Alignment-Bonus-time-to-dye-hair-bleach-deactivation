//search
							case 70201:   // 탈색제
							case 70202:   // 염색약(흰색)
							case 70203:   // 염색약(금색)
							case 70204:   // 염색약(빨간색)
							case 70205:   // 염색약(갈색)
							case 70206:   // 염색약(검은색)
								{
									// NEW_HAIR_STYLE_ADD
									if (GetPart(PART_HAIR) >= 1001)
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("현재 헤어스타일에서는 염색과 탈색이 불가능합니다."));
									}
									// END_NEW_HAIR_STYLE_ADD
									else
									{
										quest::CQuestManager& q = quest::CQuestManager::instance();
										quest::PC* pPC = q.GetPC(GetPlayerID());

										if (pPC)
										{
											int last_dye_level = pPC->GetFlag("dyeing_hair.last_dye_level");

											if (last_dye_level == 0 ||
													last_dye_level+3 <= GetLevel() ||
													item->GetVnum() == 70201)
											{
												SetPart(PART_HAIR, item->GetVnum() - 70201);

												if (item->GetVnum() == 70201)
													pPC->SetFlag("dyeing_hair.last_dye_level", 0);
												else
													pPC->SetFlag("dyeing_hair.last_dye_level", GetLevel());

												item->SetCount(item->GetCount() - 1);
												UpdatePacket();
											}
											else
											{
												ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%d 레벨이 되어야 다시 염색하실 수 있습니다."), last_dye_level+3);
											}
										}
									}
								}
								break;

//change
							case 70201:
							case 70202:
							case 70203:
							case 70204:
							case 70205:
							case 70206:
								{
									int flag = GetQuestFlag("fix_bug.colorante");
									
									if (get_global_time() - flag < 3)
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You have to wait 3 seconds to use this item again."));
										return false;
									}

									if (GetPart(PART_HAIR) >= 1001)
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You cannot dye or bleach your current Hairstyle."));
									else
									{
										quest::CQuestManager& q = quest::CQuestManager::instance();
										quest::PC* pPC = q.GetPC(GetPlayerID());

										if (pPC)
										{
											SetPart(PART_HAIR, item->GetVnum() - 70201);
											// item->SetCount(item->GetCount() - 1);
											UpdatePacket();
											SetQuestFlag("fix_bug.colorante", get_global_time());
										}
									}
								}
								break;
								
