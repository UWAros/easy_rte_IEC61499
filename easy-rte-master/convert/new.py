import xml.etree.ElementTree as ET

# Create the root element
root = ET.Element('People')

# Create the first person element
person1 = ET.SubElement(root, 'Person')
name1 = ET.SubElement(person1, 'Name')
name1.text = 'John Doe'
age1 = ET.SubElement(person1, 'Age')
age1.text = '30'

# Create the second person element
person2 = ET.SubElement(root, 'Person')
name2 = ET.SubElement(person2, 'Name')
name2.text = 'Jane Smith'
age2 = ET.SubElement(person2, 'Age')
age2.text = '25'

# Create the XML tree
tree = ET.ElementTree(root)

# Write the XML tree to a file
tree.write('people.xml', encoding='utf-8', xml_declaration=True)
