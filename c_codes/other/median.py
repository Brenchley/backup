def median(list):
    size = len(list)
    median=0
    list.sort()
    mid= size/2
    mid1= size/2 +1
    
    if size % 2 != 0:
        median += (list[size/2])
    else:

    	median += float((list[size/2]) + (list[(size/2)-1]))/2
    print list
    print median

median([7,3,1,9,4])

