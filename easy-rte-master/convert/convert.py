from jinja2 import Template
import xml.etree.ElementTree as ET


# Read the XML file
tree = ET.parse("out.xml")  # Replace "your_file.xml" with the path to your XML file
root = tree.getroot()

# Create a list to store the element information
inputs = []
inputtype = []
inputconstant = []
inputcomment = []

outputs = []
outputtype = []
outputconstant = []
outputcomment = []

internal_variables = []
variable_type = []
variable_constant = []
variable_comment = []


interface = root.find("Interface")

Allinput = interface.findall("Input")

for Input_elem in Allinput:
    input = Input_elem.get("Name")
    typ = Input_elem.get("Type")
    constant = Input_elem.get("Constant")
    comment = Input_elem.get("Comment")
   
    inputs.append(input)
    inputtype.append(typ)
    inputconstant.append(constant)
    inputcomment.append(comment)
   
Alloutput = interface.findall("Output")

for output_elem in Alloutput:
    output = output_elem.get("Name")
    out_typ = output_elem.get("Type")
    out_constant = output_elem.get("Constant")
    out_comment = output_elem.get("Comment")
   
    outputs.append(output)
    outputtype.append(out_typ)
    outputconstant.append(out_constant)
    outputcomment.append(out_comment)

Policy = root.find("Policy")

InternalVars = Policy.find("InternalVars")

Allinternal_variables = InternalVars.findall("VarDeclaration")

for varia_elem in Allinternal_variables:
    variable = varia_elem.get("Name")
    var_typ = varia_elem.get("Type")
    var_constant = varia_elem.get("Constant")
    var_comment = varia_elem.get("Comment")

    internal_variables.append(variable)
    variable_type.append(var_typ)
    variable_constant.append(var_constant)
    variable_comment.append(var_comment)


# Iterate over the elements using a for loop
#for Interface_elem in interface.findall('*'):
#    input = Interface_elem.get("Name")
 #   output = Interface_elem.text
  #  inputs.append(input)
   # outputs.append(output)
    
print(inputs)
print(inputtype)
print(inputconstant)
print(inputcomment)

print(outputs)
print(outputtype)
print(outputconstant)
print(outputcomment)

print(internal_variables)
print(variable_type)
print(variable_constant)
print(variable_comment)

# Print the element list
#for element in element_list:
    #print("Tag:", element["Tag"])
    #print("Attributes:", element["Attributes"])
    #print("Text:", element["Text"])
    #print("----------")

template = Template( '''
<?xml version="1.0" encoding="UTF-8"?>
<FBType Name=ABC Comment="Ab5example">
	<Identification Standard="61499-2">
	</Identification>
	<VersionInfo Version="1.0" Author="steph" Date="2023-05-29">
	</VersionInfo>
	<InterfaceList>
        <EventInputs>
			{%- for index in range(inputs|length) %}
    
        	<Event Name = "{{ inputs[index] }}" Type= "{{ inputtype[index] }}" Comment="{{ inputcomment[index] }}"> </Event>
        	
    
    		{%- endfor %}

	</EventInputs>

        <EventOutputs>
            {%- for index in range(outputs|length) %}

		    <Event Name= "{{ outputs[index] }}" Type= "{{ outputtype[index] }} Comment="{{ outputcomment[index] }}"> </Event>

            {%- endfor %}

	</EventOutputs>

        <InputVars>
			
        
	</InputVars>

        <OutputVars>
			
        
	</OutputVars>



</InterfaceList>

    <BasicFB>
        <InternalVars>
        {%- for index in range(internal_variables|length) %}
			<VarDeclaration Name="{{ internal_variables[index] }}" Type="{{ variable_type[index] }}" Comment="{{ variable_comment[index] }}" InitialValue="{{ variable_constant[index] }}"/>
        {%- endfor %}
	</InternalVars>


    <ECC>


    </ECC>


''')

xml_content = template.render(inputs=inputs, outputs = outputs, inputtype = inputtype, outputtype = outputtype, inputcomment = inputcomment, outputcomment = outputcomment,internal_variables = internal_variables,variable_type = variable_type, variable_comment = variable_comment, variable_constant = variable_constant )

# Print the generated XML content
print(xml_content)