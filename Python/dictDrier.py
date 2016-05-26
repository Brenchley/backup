from NewDictionary import SimpleDictionary

# creat and print SimpleDictionary object
simple = SimpleDictionary()

print "The empty dictionary:", simple

# add values to simple (invokes simple.__setitem__)
simple[1]= "Apple"
simple[2]= "two"
simple[3]= "Five"

print "The dictionary after adding values:", simple

del simple[1] # remove a value
print "The dictionary after removing a value", simple

#use mapping methods
print "\nDictionary keys:", simple.keys()
print "Dictionary values:",simple.values()
print "Dictionary items:",simple.item()

print "\nDictionary after coping it:", simple.copy()
print "\nDictionary after executing method get:", simple.get(2)
print "\nDictionary after executing method has_key:", simple.has_key(3)

simple2 = SimpleDictionary()
simple2[1]= "Mercedes"
simple2[4]= "Range rover"
simple2[5]= "BMW"
print "\nDictionary after executing method update:", simple.update(simple2)
print simple
print "\nDictionary after executing method clear:", simple.clear()
print "Dictionary:",simple