from jinja2 import Template
import xml.etree.ElementTree as ET

# Read the variables from the XML file
tree = ET.parse('people.xml')
root = tree.getroot()

names = []
ages = []

for person_elem in root.findall('Person'):
    name = person_elem.find('Name').text
    age = person_elem.find('Age').text
    names.append(name)
    ages.append(age)

# XML template with a for loop
template = Template('''
<People>
    {%- for index in range(names|length) %}
    <Person>
        <Name>{{ names[index] }}</Name>
        <Age>{{ ages[index] }}</Age>
    </Person>
    {%- endfor %}
</People>
''')

# Render the template with the variables
xml_content = template.render(names=names, ages=ages)

# Print the generated XML content
print(xml_content)
