def count(sequence, item):
    found = 0

    for i in range(0,len(sequence)):
        found = sequence.count(item)
    
    print found
    
