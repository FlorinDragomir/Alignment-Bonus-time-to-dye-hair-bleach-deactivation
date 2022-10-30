#search
		self.toolTipAlignment.AutoAppendTextLine(localeInfo.ALIGNMENT_NAME + str(point))

#add
		if point >= 1000 and point <= 3999:
			self.toolTipAlignment.AutoAppendTextLine("Max. HP +500", NORMAL_COLOR)
			self.toolTipAlignment.AutoAppendTextLine("Strong against Half Humans +3%", NORMAL_COLOR)
		elif point >= 4000 and point <= 7999:
			self.toolTipAlignment.AutoAppendTextLine("Max. HP +1000", NORMAL_COLOR)
			self.toolTipAlignment.AutoAppendTextLine("Strong against Half Humans +6%", NORMAL_COLOR)
		elif point >= 8000 and point <= 11999:
			self.toolTipAlignment.AutoAppendTextLine("Max. HP +1500", NORMAL_COLOR)
			self.toolTipAlignment.AutoAppendTextLine("Strong against Half Humans +9%", NORMAL_COLOR)	
		elif point >= 12000:
			self.toolTipAlignment.AutoAppendTextLine("Max. HP +2000", NORMAL_COLOR)
			self.toolTipAlignment.AutoAppendTextLine("Strong against Half Humans +12%", NORMAL_COLOR)
		else:
			self.toolTipAlignment.AutoAppendTextLine("You can increase your rank for special bonuses", NORMAL_COLOR)