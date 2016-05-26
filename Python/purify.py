list=[4,5,5,4]

def remove_duplicates(list):
    new_list =[]

    for i in list:
       
        new_list.append(i)
        
        if new_list not in list:
    print new_list
            

remove_duplicates(list)