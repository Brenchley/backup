def censor(text, word):

	for x in text.split():
		if x == word:
			print ''.join('*' * len(word))

	
	print ''.join([('*' * len(word)) if x == word else x for x in text.split()]).




censor('i am a hacker who hacks hacker', 'hacker')