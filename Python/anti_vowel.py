def anti_vowel(text):

	new= str(text)
	name=''

	for char in new:
		if char not in "aeiouAEIOU":
			
			name += char
	print name				


