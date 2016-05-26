list=[4,5,5,4,5,6,7,8,9,3,5,4,5]

def remove_duplicates(list):
    new_list= []
    seen = set()
    for value in list:
        # If value has not been encountered yet,
        # ... add it to both list and set.
        if value not in seen:
            new_list.append(value)
            seen.add(value)
    print new_list

remove_duplicates(list)