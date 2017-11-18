#include <pyOCCT_Common.hpp>

#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_Type.hxx>
#include <IGESDefs_TabularData.hxx>
#include <NCollection_Array1.hxx>
#include <IGESDefs_Array1OfTabularData.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IGESDefs_HArray1OfTabularData.hxx>
#include <IGESData_Protocol.hxx>
#include <Interface_Protocol.hxx>
#include <IGESDefs_Protocol.hxx>
#include <IGESBasic_HArray1OfHArray1OfInteger.hxx>
#include <IGESDefs_AssociativityDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <IGESDefs_MacroDef.hxx>
#include <IGESDefs_UnitsData.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.hxx>
#include <IGESGraph_TextDisplayTemplate.hxx>
#include <IGESDefs_AttributeDef.hxx>
#include <IGESDefs_GenericData.hxx>
#include <TColStd_HArray2OfTransient.hxx>
#include <IGESDefs_AttributeTable.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESDefs_ToolAssociativityDef.hxx>
#include <IGESDefs_ToolMacroDef.hxx>
#include <IGESDefs_ToolUnitsData.hxx>
#include <IGESDefs_ToolAttributeDef.hxx>
#include <IGESDefs_ToolTabularData.hxx>
#include <IGESDefs_ToolGenericData.hxx>
#include <IGESDefs_ToolAttributeTable.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <IGESDefs_ReadWriteModule.hxx>
#include <IGESData_GeneralModule.hxx>
#include <IGESDefs_GeneralModule.hxx>
#include <IGESData_SpecificModule.hxx>
#include <IGESDefs_SpecificModule.hxx>
#include <IGESGraph_HArray1OfTextDisplayTemplate.hxx>
#include <IGESDefs.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(IGESDefs, mod) {

	// IMPORT
	py::module::import("OCCT.IGESData");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.IGESBasic");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.IGESGraph");
	py::module::import("OCCT.Message");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_TabularData.hxx
	py::class_<IGESDefs_TabularData, opencascade::handle<IGESDefs_TabularData>, IGESData_IGESEntity> cls_IGESDefs_TabularData(mod, "IGESDefs_TabularData", "Defines IGES Tabular Data, Type <406> Form <11>, in package IGESDefs This Class is used to provide a Structure to accomodate point form data.");
	cls_IGESDefs_TabularData.def(py::init<>());
	cls_IGESDefs_TabularData.def("Init", (void (IGESDefs_TabularData::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfReal> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfReal> &)) &IGESDefs_TabularData::Init, "This method is used to set the fields of the class TabularData - nbProps : Number of property values - propType : Property Type - typesInd : Type of independent variables - nbValuesInd : Number of values of independent variables - valuesInd : Values of independent variables - valuesDep : Values of dependent variables raises exception if lengths of typeInd and nbValuesInd are not same", py::arg("nbProps"), py::arg("propType"), py::arg("typesInd"), py::arg("nbValuesInd"), py::arg("valuesInd"), py::arg("valuesDep"));
	cls_IGESDefs_TabularData.def("NbPropertyValues", (Standard_Integer (IGESDefs_TabularData::*)() const ) &IGESDefs_TabularData::NbPropertyValues, "returns the number of property values (recorded)");
	cls_IGESDefs_TabularData.def("ComputedNbPropertyValues", (Standard_Integer (IGESDefs_TabularData::*)() const ) &IGESDefs_TabularData::ComputedNbPropertyValues, "determines the number of property values required");
	cls_IGESDefs_TabularData.def("OwnCorrect", (Standard_Boolean (IGESDefs_TabularData::*)()) &IGESDefs_TabularData::OwnCorrect, "checks, and correct as necessary, the number of property values. Returns True if corrected, False if already OK");
	cls_IGESDefs_TabularData.def("PropertyType", (Standard_Integer (IGESDefs_TabularData::*)() const ) &IGESDefs_TabularData::PropertyType, "returns the property type");
	cls_IGESDefs_TabularData.def("NbDependents", (Standard_Integer (IGESDefs_TabularData::*)() const ) &IGESDefs_TabularData::NbDependents, "returns the number of dependent variables");
	cls_IGESDefs_TabularData.def("NbIndependents", (Standard_Integer (IGESDefs_TabularData::*)() const ) &IGESDefs_TabularData::NbIndependents, "returns the number of independent variables");
	cls_IGESDefs_TabularData.def("TypeOfIndependents", (Standard_Integer (IGESDefs_TabularData::*)(const Standard_Integer) const ) &IGESDefs_TabularData::TypeOfIndependents, "returns the type of the num'th independent variable raises exception if num <= 0 or num > NbIndependents()", py::arg("num"));
	cls_IGESDefs_TabularData.def("NbValues", (Standard_Integer (IGESDefs_TabularData::*)(const Standard_Integer) const ) &IGESDefs_TabularData::NbValues, "returns the number of different values of the num'th indep. variable raises exception if num <= 0 or num > NbIndependents()", py::arg("num"));
	cls_IGESDefs_TabularData.def("IndependentValue", (Standard_Real (IGESDefs_TabularData::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_TabularData::IndependentValue, "None", py::arg("variablenum"), py::arg("valuenum"));
	cls_IGESDefs_TabularData.def("DependentValues", (opencascade::handle<TColStd_HArray1OfReal> (IGESDefs_TabularData::*)(const Standard_Integer) const ) &IGESDefs_TabularData::DependentValues, "None", py::arg("num"));
	cls_IGESDefs_TabularData.def("DependentValue", (Standard_Real (IGESDefs_TabularData::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_TabularData::DependentValue, "None", py::arg("variablenum"), py::arg("valuenum"));
	cls_IGESDefs_TabularData.def_static("get_type_name_", (const char * (*)()) &IGESDefs_TabularData::get_type_name, "None");
	cls_IGESDefs_TabularData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_TabularData::get_type_descriptor, "None");
	cls_IGESDefs_TabularData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_TabularData::*)() const ) &IGESDefs_TabularData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_Array1OfTabularData.hxx
	bind_NCollection_Array1<opencascade::handle<IGESDefs_TabularData> >(mod, "IGESDefs_Array1OfTabularData");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_Protocol.hxx
	py::class_<IGESDefs_Protocol, opencascade::handle<IGESDefs_Protocol>, IGESData_Protocol> cls_IGESDefs_Protocol(mod, "IGESDefs_Protocol", "Description of Protocol for IGESDefs");
	cls_IGESDefs_Protocol.def(py::init<>());
	cls_IGESDefs_Protocol.def("NbResources", (Standard_Integer (IGESDefs_Protocol::*)() const ) &IGESDefs_Protocol::NbResources, "Gives the count of Resource Protocol. Here, one (Protocol from IGESGraph)");
	cls_IGESDefs_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESDefs_Protocol::*)(const Standard_Integer) const ) &IGESDefs_Protocol::Resource, "Returns a Resource, given a rank.", py::arg("num"));
	cls_IGESDefs_Protocol.def("TypeNumber", (Standard_Integer (IGESDefs_Protocol::*)(const opencascade::handle<Standard_Type> &) const ) &IGESDefs_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type This Case Number is then used in Libraries : the various Modules attached to this class of Protocol must use them in accordance (for a given value of TypeNumber, they must consider the same Type as the Protocol defines)", py::arg("atype"));
	cls_IGESDefs_Protocol.def_static("get_type_name_", (const char * (*)()) &IGESDefs_Protocol::get_type_name, "None");
	cls_IGESDefs_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_Protocol::get_type_descriptor, "None");
	cls_IGESDefs_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_Protocol::*)() const ) &IGESDefs_Protocol::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_AssociativityDef.hxx
	py::class_<IGESDefs_AssociativityDef, opencascade::handle<IGESDefs_AssociativityDef>, IGESData_IGESEntity> cls_IGESDefs_AssociativityDef(mod, "IGESDefs_AssociativityDef", "defines IGES Associativity Definition Entity, Type <302> Form <5001 - 9999> in package IGESDefs. This class permits the preprocessor to define an associativity schema. i.e., by using it preprocessor defines the type of relationship.");
	cls_IGESDefs_AssociativityDef.def(py::init<>());
	cls_IGESDefs_AssociativityDef.def("Init", (void (IGESDefs_AssociativityDef::*)(const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &)) &IGESDefs_AssociativityDef::Init, "This method is used to set the fields of the class AssociativityDef - requirements : Back Pointers requirements - orders : Class Orders - numItems : Number of Items per Class - items : Items in each class raises exception if lengths of the arrays are not the same.", py::arg("requirements"), py::arg("orders"), py::arg("numItems"), py::arg("items"));
	cls_IGESDefs_AssociativityDef.def("SetFormNumber", (void (IGESDefs_AssociativityDef::*)(const Standard_Integer)) &IGESDefs_AssociativityDef::SetFormNumber, "None", py::arg("form"));
	cls_IGESDefs_AssociativityDef.def("NbClassDefs", (Standard_Integer (IGESDefs_AssociativityDef::*)() const ) &IGESDefs_AssociativityDef::NbClassDefs, "returns the Number of class definitions");
	cls_IGESDefs_AssociativityDef.def("IsBackPointerReq", (Standard_Boolean (IGESDefs_AssociativityDef::*)(const Standard_Integer) const ) &IGESDefs_AssociativityDef::IsBackPointerReq, "returns 1 if the theBackPointerReqs(ClassNum) = 1 returns 0 if the theBackPointerReqs(ClassNum) = 2 raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
	cls_IGESDefs_AssociativityDef.def("BackPointerReq", (Standard_Integer (IGESDefs_AssociativityDef::*)(const Standard_Integer) const ) &IGESDefs_AssociativityDef::BackPointerReq, "returns 1 or 2 raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
	cls_IGESDefs_AssociativityDef.def("IsOrdered", (Standard_Boolean (IGESDefs_AssociativityDef::*)(const Standard_Integer) const ) &IGESDefs_AssociativityDef::IsOrdered, "returns 1 if theClassOrders(ClassNum) = 1 (ordered class) returns 0 if theClassOrders(ClassNum) = 2 (unordered class) raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
	cls_IGESDefs_AssociativityDef.def("ClassOrder", (Standard_Integer (IGESDefs_AssociativityDef::*)(const Standard_Integer) const ) &IGESDefs_AssociativityDef::ClassOrder, "returns 1 or 2 raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
	cls_IGESDefs_AssociativityDef.def("NbItemsPerClass", (Standard_Integer (IGESDefs_AssociativityDef::*)(const Standard_Integer) const ) &IGESDefs_AssociativityDef::NbItemsPerClass, "returns no. of items per class entry raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
	cls_IGESDefs_AssociativityDef.def("Item", (Standard_Integer (IGESDefs_AssociativityDef::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AssociativityDef::Item, "returns ItemNum'th Item of ClassNum'th Class raises exception if ClassNum <= 0 or ClassNum > NbClassDefs() ItemNum <= 0 or ItemNum > NbItemsPerClass(ClassNum)", py::arg("ClassNum"), py::arg("ItemNum"));
	cls_IGESDefs_AssociativityDef.def_static("get_type_name_", (const char * (*)()) &IGESDefs_AssociativityDef::get_type_name, "None");
	cls_IGESDefs_AssociativityDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_AssociativityDef::get_type_descriptor, "None");
	cls_IGESDefs_AssociativityDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_AssociativityDef::*)() const ) &IGESDefs_AssociativityDef::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_MacroDef.hxx
	py::class_<IGESDefs_MacroDef, opencascade::handle<IGESDefs_MacroDef>, IGESData_IGESEntity> cls_IGESDefs_MacroDef(mod, "IGESDefs_MacroDef", "defines IGES Macro Definition Entity, Type <306> Form <0> in package IGESDefs This Class specifies the action of a specific MACRO. After specification MACRO can be used as necessary by means of MACRO class instance entity.");
	cls_IGESDefs_MacroDef.def(py::init<>());
	cls_IGESDefs_MacroDef.def("Init", (void (IGESDefs_MacroDef::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESDefs_MacroDef::Init, "This method is used to set the fields of the class MacroDef - macro : MACRO - entityTypeID : Entity Type ID - langStatements : Language Statements - endMacro : END MACRO", py::arg("macro"), py::arg("entityTypeID"), py::arg("langStatements"), py::arg("endMacro"));
	cls_IGESDefs_MacroDef.def("NbStatements", (Standard_Integer (IGESDefs_MacroDef::*)() const ) &IGESDefs_MacroDef::NbStatements, "returns the number of language statements");
	cls_IGESDefs_MacroDef.def("MACRO", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_MacroDef::*)() const ) &IGESDefs_MacroDef::MACRO, "returns the MACRO(Literal)");
	cls_IGESDefs_MacroDef.def("EntityTypeID", (Standard_Integer (IGESDefs_MacroDef::*)() const ) &IGESDefs_MacroDef::EntityTypeID, "returns the Entity Type ID");
	cls_IGESDefs_MacroDef.def("LanguageStatement", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_MacroDef::*)(const Standard_Integer) const ) &IGESDefs_MacroDef::LanguageStatement, "None", py::arg("StatNum"));
	cls_IGESDefs_MacroDef.def("ENDMACRO", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_MacroDef::*)() const ) &IGESDefs_MacroDef::ENDMACRO, "returns the ENDM(Literal)");
	cls_IGESDefs_MacroDef.def_static("get_type_name_", (const char * (*)()) &IGESDefs_MacroDef::get_type_name, "None");
	cls_IGESDefs_MacroDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_MacroDef::get_type_descriptor, "None");
	cls_IGESDefs_MacroDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_MacroDef::*)() const ) &IGESDefs_MacroDef::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_UnitsData.hxx
	py::class_<IGESDefs_UnitsData, opencascade::handle<IGESDefs_UnitsData>, IGESData_IGESEntity> cls_IGESDefs_UnitsData(mod, "IGESDefs_UnitsData", "defines IGES UnitsData Entity, Type <316> Form <0> in package IGESDefs This class stores data about a model's fundamental units.");
	cls_IGESDefs_UnitsData.def(py::init<>());
	cls_IGESDefs_UnitsData.def("Init", (void (IGESDefs_UnitsData::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &IGESDefs_UnitsData::Init, "This method is used to set the fields of the class UnitsData - unitTypes : Types of the units being defined - unitValues : Unit Values of the units - unitScales : Multiplicative Scale Factors raises exception if lengths of unitTypes, unitValues and unitScale are not same", py::arg("unitTypes"), py::arg("unitValues"), py::arg("unitScales"));
	cls_IGESDefs_UnitsData.def("NbUnits", (Standard_Integer (IGESDefs_UnitsData::*)() const ) &IGESDefs_UnitsData::NbUnits, "returns the Number of units defined by this entity");
	cls_IGESDefs_UnitsData.def("UnitType", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_UnitsData::*)(const Standard_Integer) const ) &IGESDefs_UnitsData::UnitType, "returns the Type of the UnitNum'th unit being defined raises exception if UnitNum <= 0 or UnitNum > NbUnits()", py::arg("UnitNum"));
	cls_IGESDefs_UnitsData.def("UnitValue", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_UnitsData::*)(const Standard_Integer) const ) &IGESDefs_UnitsData::UnitValue, "returns the Units of the UnitNum'th unit being defined raises exception if UnitNum <= 0 or UnitNum > NbUnits()", py::arg("UnitNum"));
	cls_IGESDefs_UnitsData.def("ScaleFactor", (Standard_Real (IGESDefs_UnitsData::*)(const Standard_Integer) const ) &IGESDefs_UnitsData::ScaleFactor, "returns the multiplicative scale factor to be apllied to the UnitNum'th unit being defined raises exception if UnitNum <= 0 or UnitNum > NbUnits()", py::arg("UnitNum"));
	cls_IGESDefs_UnitsData.def_static("get_type_name_", (const char * (*)()) &IGESDefs_UnitsData::get_type_name, "None");
	cls_IGESDefs_UnitsData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_UnitsData::get_type_descriptor, "None");
	cls_IGESDefs_UnitsData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_UnitsData::*)() const ) &IGESDefs_UnitsData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_AttributeDef.hxx
	py::class_<IGESDefs_AttributeDef, opencascade::handle<IGESDefs_AttributeDef>, IGESData_IGESEntity> cls_IGESDefs_AttributeDef(mod, "IGESDefs_AttributeDef", "defines IGES Attribute Table Definition Entity, Type <322> Form [0, 1, 2] in package IGESDefs. This is class is used to support the concept of well defined collection of attributes, whether it is a table or a single row of attributes.");
	cls_IGESDefs_AttributeDef.def(py::init<>());
	cls_IGESDefs_AttributeDef.def("Init", (void (IGESDefs_AttributeDef::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfTransient> &, const opencascade::handle<IGESDefs_HArray1OfHArray1OfTextDisplayTemplate> &)) &IGESDefs_AttributeDef::Init, "None", py::arg("aName"), py::arg("aListType"), py::arg("attrTypes"), py::arg("attrValueDataTypes"), py::arg("attrValueCounts"), py::arg("attrValues"), py::arg("attrValuePointers"));
	cls_IGESDefs_AttributeDef.def("HasTableName", (Standard_Boolean (IGESDefs_AttributeDef::*)() const ) &IGESDefs_AttributeDef::HasTableName, "Returns True if a Table Name is defined");
	cls_IGESDefs_AttributeDef.def("TableName", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_AttributeDef::*)() const ) &IGESDefs_AttributeDef::TableName, "returns the Attribute Table name, or comment (default = null, no name : seeHasTableName)");
	cls_IGESDefs_AttributeDef.def("ListType", (Standard_Integer (IGESDefs_AttributeDef::*)() const ) &IGESDefs_AttributeDef::ListType, "returns the Attribute List Type");
	cls_IGESDefs_AttributeDef.def("NbAttributes", (Standard_Integer (IGESDefs_AttributeDef::*)() const ) &IGESDefs_AttributeDef::NbAttributes, "returns the Number of Attributes");
	cls_IGESDefs_AttributeDef.def("AttributeType", (Standard_Integer (IGESDefs_AttributeDef::*)(const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeType, "returns the num'th Attribute Type raises exception if num <= 0 or num > NbAttributes()", py::arg("num"));
	cls_IGESDefs_AttributeDef.def("AttributeValueDataType", (Standard_Integer (IGESDefs_AttributeDef::*)(const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeValueDataType, "returns the num'th Attribute value data type raises exception if num <= 0 or num > NbAttributes()", py::arg("num"));
	cls_IGESDefs_AttributeDef.def("AttributeValueCount", (Standard_Integer (IGESDefs_AttributeDef::*)(const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeValueCount, "returns the num'th Attribute value count raises exception if num <= 0 or num > NbAttributes()", py::arg("num"));
	cls_IGESDefs_AttributeDef.def("HasValues", (Standard_Boolean (IGESDefs_AttributeDef::*)() const ) &IGESDefs_AttributeDef::HasValues, "returns false if Values are defined (i.e. for Form = 1 or 2)");
	cls_IGESDefs_AttributeDef.def("HasTextDisplay", (Standard_Boolean (IGESDefs_AttributeDef::*)() const ) &IGESDefs_AttributeDef::HasTextDisplay, "returns false if TextDisplays are defined (i.e. for Form = 2)");
	cls_IGESDefs_AttributeDef.def("AttributeTextDisplay", (opencascade::handle<IGESGraph_TextDisplayTemplate> (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeTextDisplay, "None", py::arg("AttrNum"), py::arg("PointerNum"));
	cls_IGESDefs_AttributeDef.def("AttributeList", (opencascade::handle<Standard_Transient> (IGESDefs_AttributeDef::*)(const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeList, "Returns the List of Attributes <AttrNum>, as a Transient. Its effective Type depends of the Type of Attribute : HArray1OfInteger for Integer, Logical(0-1), HArray1OfReal for Real, HArray1OfHSaciiString for String, HArray1OfIGESEntity for Entity (Pointer) See methods AttributeAs... for an accurate access", py::arg("AttrNum"));
	cls_IGESDefs_AttributeDef.def("AttributeAsInteger", (Standard_Integer (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeAsInteger, "Returns Attribute Value <AttrNum, rank ValueNum> as an Integer Error if Indices out of Range, or no Value defined, or not an Integer", py::arg("AttrNum"), py::arg("ValueNum"));
	cls_IGESDefs_AttributeDef.def("AttributeAsReal", (Standard_Real (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeAsReal, "Returns Attribute Value <AttrNum, rank ValueNum> as a Real Error if Indices out of Range, or no Value defined, or not a Real", py::arg("AttrNum"), py::arg("ValueNum"));
	cls_IGESDefs_AttributeDef.def("AttributeAsString", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeAsString, "Returns Attribute Value <AttrNum, rank ValueNum> as an Integer", py::arg("AttrNum"), py::arg("ValueNum"));
	cls_IGESDefs_AttributeDef.def("AttributeAsEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeAsEntity, "Returns Attribute Value <AttrNum, rank ValueNum> as an Entity Error if Indices out of Range, or no Value defined, or not a Entity", py::arg("AttrNum"), py::arg("ValueNum"));
	cls_IGESDefs_AttributeDef.def("AttributeAsLogical", (Standard_Boolean (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeDef::AttributeAsLogical, "Returns Attribute Value <AttrNum, rank ValueNum> as a Boolean Error if Indices out of Range, or no Value defined, or not a Logical", py::arg("AttrNum"), py::arg("ValueNum"));
	cls_IGESDefs_AttributeDef.def_static("get_type_name_", (const char * (*)()) &IGESDefs_AttributeDef::get_type_name, "None");
	cls_IGESDefs_AttributeDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_AttributeDef::get_type_descriptor, "None");
	cls_IGESDefs_AttributeDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_AttributeDef::*)() const ) &IGESDefs_AttributeDef::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_GenericData.hxx
	py::class_<IGESDefs_GenericData, opencascade::handle<IGESDefs_GenericData>, IGESData_IGESEntity> cls_IGESDefs_GenericData(mod, "IGESDefs_GenericData", "defines IGES Generic Data, Type <406> Form <27> in package IGESDefs Used to communicate information defined by the system operator while creating the model. The information is system specific and does not map into one of the predefined properties or associativities. Properties and property values can be defined by multiple instances of this property.");
	cls_IGESDefs_GenericData.def(py::init<>());
	cls_IGESDefs_GenericData.def("Init", (void (IGESDefs_GenericData::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfTransient> &)) &IGESDefs_GenericData::Init, "This method is used to set the fields of the class GenericData - nbPropVal : Number of property values - aName : Property Name - allTypes : Property Types - allValues : Property Values", py::arg("nbPropVal"), py::arg("aName"), py::arg("allTypes"), py::arg("allValues"));
	cls_IGESDefs_GenericData.def("NbPropertyValues", (Standard_Integer (IGESDefs_GenericData::*)() const ) &IGESDefs_GenericData::NbPropertyValues, "returns the number of property values");
	cls_IGESDefs_GenericData.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_GenericData::*)() const ) &IGESDefs_GenericData::Name, "returns property name");
	cls_IGESDefs_GenericData.def("NbTypeValuePairs", (Standard_Integer (IGESDefs_GenericData::*)() const ) &IGESDefs_GenericData::NbTypeValuePairs, "returns the number of TYPE/VALUE pairs");
	cls_IGESDefs_GenericData.def("Type", (Standard_Integer (IGESDefs_GenericData::*)(const Standard_Integer) const ) &IGESDefs_GenericData::Type, "returns the Index'th property value data type raises exception if Index <= 0 or Index > NbTypeValuePairs()", py::arg("Index"));
	cls_IGESDefs_GenericData.def("Value", (opencascade::handle<Standard_Transient> (IGESDefs_GenericData::*)(const Standard_Integer) const ) &IGESDefs_GenericData::Value, "HArray1OfInteger (length 1), HArray1OfReal (length 1) for Integer, Real, Boolean (= Integer 0/1), HAsciiString for String (the value itself), IGESEntity for Entity (the value itself)", py::arg("Index"));
	cls_IGESDefs_GenericData.def("ValueAsInteger", (Standard_Integer (IGESDefs_GenericData::*)(const Standard_Integer) const ) &IGESDefs_GenericData::ValueAsInteger, "Returns Attribute Value <AttrNum, rank ValueNum> as an Integer Error if Index out of Range, or not an Integer", py::arg("ValueNum"));
	cls_IGESDefs_GenericData.def("ValueAsReal", (Standard_Real (IGESDefs_GenericData::*)(const Standard_Integer) const ) &IGESDefs_GenericData::ValueAsReal, "Returns Attribute Value <AttrNum, rank ValueNum> as a Real Error if Index out of Range, or not a Real", py::arg("ValueNum"));
	cls_IGESDefs_GenericData.def("ValueAsString", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_GenericData::*)(const Standard_Integer) const ) &IGESDefs_GenericData::ValueAsString, "Returns Attribute Value <AttrNum, rank ValueNum> as an Integer", py::arg("ValueNum"));
	cls_IGESDefs_GenericData.def("ValueAsEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDefs_GenericData::*)(const Standard_Integer) const ) &IGESDefs_GenericData::ValueAsEntity, "Returns Attribute Value <AttrNum, rank ValueNum> as an Entity Error if Index out of Range, or not a Entity", py::arg("ValueNum"));
	cls_IGESDefs_GenericData.def("ValueAsLogical", (Standard_Boolean (IGESDefs_GenericData::*)(const Standard_Integer) const ) &IGESDefs_GenericData::ValueAsLogical, "Returns Attribute Value <AttrNum, rank ValueNum> as a Boolean Error if Index out of Range, or not a Logical", py::arg("ValueNum"));
	cls_IGESDefs_GenericData.def_static("get_type_name_", (const char * (*)()) &IGESDefs_GenericData::get_type_name, "None");
	cls_IGESDefs_GenericData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_GenericData::get_type_descriptor, "None");
	cls_IGESDefs_GenericData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_GenericData::*)() const ) &IGESDefs_GenericData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_AttributeTable.hxx
	py::class_<IGESDefs_AttributeTable, opencascade::handle<IGESDefs_AttributeTable>, IGESData_IGESEntity> cls_IGESDefs_AttributeTable(mod, "IGESDefs_AttributeTable", "defines IGES Attribute Table, Type <422> Form <0, 1> in package IGESDefs This class is used to represent an occurence of Attribute Table. This Class may be independent or dependent or pointed at by other Entities.");
	cls_IGESDefs_AttributeTable.def(py::init<>());
	cls_IGESDefs_AttributeTable.def("Init", (void (IGESDefs_AttributeTable::*)(const opencascade::handle<TColStd_HArray2OfTransient> &)) &IGESDefs_AttributeTable::Init, "This method is used to set the fields of the class AttributeTable - attributes : Attribute instances, created as (1,NbAttributes,1,NbRows) - NbRows = 1 is a particular case (Form 0)", py::arg("attributes"));
	cls_IGESDefs_AttributeTable.def("SetDefinition", (void (IGESDefs_AttributeTable::*)(const opencascade::handle<IGESDefs_AttributeDef> &)) &IGESDefs_AttributeTable::SetDefinition, "Sets a Definition as Structure information (works by calling InitMisc)", py::arg("def"));
	cls_IGESDefs_AttributeTable.def("Definition", (opencascade::handle<IGESDefs_AttributeDef> (IGESDefs_AttributeTable::*)() const ) &IGESDefs_AttributeTable::Definition, "Return the Structure information in Directory Entry, casted as an AttributeDef");
	cls_IGESDefs_AttributeTable.def("NbRows", (Standard_Integer (IGESDefs_AttributeTable::*)() const ) &IGESDefs_AttributeTable::NbRows, "returns Number of Rows. Remark that it is always 1 if Form = 0 It means that the list of Attributes (by their number, and for each one its type and ValueCount) is repeated <NbRows> times");
	cls_IGESDefs_AttributeTable.def("NbAttributes", (Standard_Integer (IGESDefs_AttributeTable::*)() const ) &IGESDefs_AttributeTable::NbAttributes, "returns Number of Attributes");
	cls_IGESDefs_AttributeTable.def("DataType", (Standard_Integer (IGESDefs_AttributeTable::*)(const Standard_Integer) const ) &IGESDefs_AttributeTable::DataType, "returns the Type of an Attribute, given its No. : it is read in the Definition. (1 : Integer, 2 : Real, 3 : String, 4 : Entity, 6 : Logical)", py::arg("Atnum"));
	cls_IGESDefs_AttributeTable.def("ValueCount", (Standard_Integer (IGESDefs_AttributeTable::*)(const Standard_Integer) const ) &IGESDefs_AttributeTable::ValueCount, "returns the Count of Value for an Attribute, given its No. : it is read in the Definition.", py::arg("Atnum"));
	cls_IGESDefs_AttributeTable.def("AttributeList", (opencascade::handle<Standard_Transient> (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeTable::AttributeList, "None", py::arg("Attribnum"), py::arg("Rownum"));
	cls_IGESDefs_AttributeTable.def("AttributeAsInteger", (Standard_Integer (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeTable::AttributeAsInteger, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as an Integer Error if Indices out of Range, or no Value defined, or not an Integer", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
	cls_IGESDefs_AttributeTable.def("AttributeAsReal", (Standard_Real (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeTable::AttributeAsReal, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as a Real Error if Indices out of Range, or no Value defined, or not a Real", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
	cls_IGESDefs_AttributeTable.def("AttributeAsString", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeTable::AttributeAsString, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as an Integer", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
	cls_IGESDefs_AttributeTable.def("AttributeAsEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeTable::AttributeAsEntity, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as an Entity Error if Indices out of Range, or no Value defined, or not an Entity", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
	cls_IGESDefs_AttributeTable.def("AttributeAsLogical", (Standard_Boolean (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &IGESDefs_AttributeTable::AttributeAsLogical, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as a Boolean Error if Indices out of Range, or no Value defined, or not a Logical", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
	cls_IGESDefs_AttributeTable.def_static("get_type_name_", (const char * (*)()) &IGESDefs_AttributeTable::get_type_name, "None");
	cls_IGESDefs_AttributeTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_AttributeTable::get_type_descriptor, "None");
	cls_IGESDefs_AttributeTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_AttributeTable::*)() const ) &IGESDefs_AttributeTable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_ToolAssociativityDef.hxx
	py::class_<IGESDefs_ToolAssociativityDef, std::unique_ptr<IGESDefs_ToolAssociativityDef, Deleter<IGESDefs_ToolAssociativityDef>>> cls_IGESDefs_ToolAssociativityDef(mod, "IGESDefs_ToolAssociativityDef", "Tool to work on a AssociativityDef. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESDefs_ToolAssociativityDef.def(py::init<>());
	cls_IGESDefs_ToolAssociativityDef.def("ReadOwnParams", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESDefs_ToolAssociativityDef::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESDefs_ToolAssociativityDef.def("WriteOwnParams", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, IGESData_IGESWriter &) const ) &IGESDefs_ToolAssociativityDef::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESDefs_ToolAssociativityDef.def("OwnShared", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, Interface_EntityIterator &) const ) &IGESDefs_ToolAssociativityDef::OwnShared, "Lists the Entities shared by a AssociativityDef <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESDefs_ToolAssociativityDef.def("DirChecker", (IGESData_DirChecker (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &) const ) &IGESDefs_ToolAssociativityDef::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESDefs_ToolAssociativityDef.def("OwnCheck", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESDefs_ToolAssociativityDef::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESDefs_ToolAssociativityDef.def("OwnCopy", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, const opencascade::handle<IGESDefs_AssociativityDef> &, Interface_CopyTool &) const ) &IGESDefs_ToolAssociativityDef::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESDefs_ToolAssociativityDef.def("OwnDump", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESDefs_ToolAssociativityDef::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_ToolMacroDef.hxx
	py::class_<IGESDefs_ToolMacroDef, std::unique_ptr<IGESDefs_ToolMacroDef, Deleter<IGESDefs_ToolMacroDef>>> cls_IGESDefs_ToolMacroDef(mod, "IGESDefs_ToolMacroDef", "Tool to work on a MacroDef. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESDefs_ToolMacroDef.def(py::init<>());
	cls_IGESDefs_ToolMacroDef.def("ReadOwnParams", (void (IGESDefs_ToolMacroDef::*)(const opencascade::handle<IGESDefs_MacroDef> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESDefs_ToolMacroDef::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESDefs_ToolMacroDef.def("WriteOwnParams", (void (IGESDefs_ToolMacroDef::*)(const opencascade::handle<IGESDefs_MacroDef> &, IGESData_IGESWriter &) const ) &IGESDefs_ToolMacroDef::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESDefs_ToolMacroDef.def("OwnShared", (void (IGESDefs_ToolMacroDef::*)(const opencascade::handle<IGESDefs_MacroDef> &, Interface_EntityIterator &) const ) &IGESDefs_ToolMacroDef::OwnShared, "Lists the Entities shared by a MacroDef <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESDefs_ToolMacroDef.def("DirChecker", (IGESData_DirChecker (IGESDefs_ToolMacroDef::*)(const opencascade::handle<IGESDefs_MacroDef> &) const ) &IGESDefs_ToolMacroDef::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESDefs_ToolMacroDef.def("OwnCheck", (void (IGESDefs_ToolMacroDef::*)(const opencascade::handle<IGESDefs_MacroDef> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESDefs_ToolMacroDef::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESDefs_ToolMacroDef.def("OwnCopy", (void (IGESDefs_ToolMacroDef::*)(const opencascade::handle<IGESDefs_MacroDef> &, const opencascade::handle<IGESDefs_MacroDef> &, Interface_CopyTool &) const ) &IGESDefs_ToolMacroDef::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESDefs_ToolMacroDef.def("OwnDump", (void (IGESDefs_ToolMacroDef::*)(const opencascade::handle<IGESDefs_MacroDef> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESDefs_ToolMacroDef::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_ToolUnitsData.hxx
	py::class_<IGESDefs_ToolUnitsData, std::unique_ptr<IGESDefs_ToolUnitsData, Deleter<IGESDefs_ToolUnitsData>>> cls_IGESDefs_ToolUnitsData(mod, "IGESDefs_ToolUnitsData", "Tool to work on a UnitsData. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESDefs_ToolUnitsData.def(py::init<>());
	cls_IGESDefs_ToolUnitsData.def("ReadOwnParams", (void (IGESDefs_ToolUnitsData::*)(const opencascade::handle<IGESDefs_UnitsData> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESDefs_ToolUnitsData::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESDefs_ToolUnitsData.def("WriteOwnParams", (void (IGESDefs_ToolUnitsData::*)(const opencascade::handle<IGESDefs_UnitsData> &, IGESData_IGESWriter &) const ) &IGESDefs_ToolUnitsData::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESDefs_ToolUnitsData.def("OwnShared", (void (IGESDefs_ToolUnitsData::*)(const opencascade::handle<IGESDefs_UnitsData> &, Interface_EntityIterator &) const ) &IGESDefs_ToolUnitsData::OwnShared, "Lists the Entities shared by a UnitsData <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESDefs_ToolUnitsData.def("DirChecker", (IGESData_DirChecker (IGESDefs_ToolUnitsData::*)(const opencascade::handle<IGESDefs_UnitsData> &) const ) &IGESDefs_ToolUnitsData::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESDefs_ToolUnitsData.def("OwnCheck", (void (IGESDefs_ToolUnitsData::*)(const opencascade::handle<IGESDefs_UnitsData> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESDefs_ToolUnitsData::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESDefs_ToolUnitsData.def("OwnCopy", (void (IGESDefs_ToolUnitsData::*)(const opencascade::handle<IGESDefs_UnitsData> &, const opencascade::handle<IGESDefs_UnitsData> &, Interface_CopyTool &) const ) &IGESDefs_ToolUnitsData::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESDefs_ToolUnitsData.def("OwnDump", (void (IGESDefs_ToolUnitsData::*)(const opencascade::handle<IGESDefs_UnitsData> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESDefs_ToolUnitsData::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_ToolAttributeDef.hxx
	py::class_<IGESDefs_ToolAttributeDef, std::unique_ptr<IGESDefs_ToolAttributeDef, Deleter<IGESDefs_ToolAttributeDef>>> cls_IGESDefs_ToolAttributeDef(mod, "IGESDefs_ToolAttributeDef", "Tool to work on a AttributeDef. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESDefs_ToolAttributeDef.def(py::init<>());
	cls_IGESDefs_ToolAttributeDef.def("ReadOwnParams", (void (IGESDefs_ToolAttributeDef::*)(const opencascade::handle<IGESDefs_AttributeDef> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESDefs_ToolAttributeDef::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESDefs_ToolAttributeDef.def("WriteOwnParams", (void (IGESDefs_ToolAttributeDef::*)(const opencascade::handle<IGESDefs_AttributeDef> &, IGESData_IGESWriter &) const ) &IGESDefs_ToolAttributeDef::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESDefs_ToolAttributeDef.def("OwnShared", (void (IGESDefs_ToolAttributeDef::*)(const opencascade::handle<IGESDefs_AttributeDef> &, Interface_EntityIterator &) const ) &IGESDefs_ToolAttributeDef::OwnShared, "Lists the Entities shared by a AttributeDef <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESDefs_ToolAttributeDef.def("DirChecker", (IGESData_DirChecker (IGESDefs_ToolAttributeDef::*)(const opencascade::handle<IGESDefs_AttributeDef> &) const ) &IGESDefs_ToolAttributeDef::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESDefs_ToolAttributeDef.def("OwnCheck", (void (IGESDefs_ToolAttributeDef::*)(const opencascade::handle<IGESDefs_AttributeDef> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESDefs_ToolAttributeDef::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESDefs_ToolAttributeDef.def("OwnCopy", (void (IGESDefs_ToolAttributeDef::*)(const opencascade::handle<IGESDefs_AttributeDef> &, const opencascade::handle<IGESDefs_AttributeDef> &, Interface_CopyTool &) const ) &IGESDefs_ToolAttributeDef::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESDefs_ToolAttributeDef.def("OwnDump", (void (IGESDefs_ToolAttributeDef::*)(const opencascade::handle<IGESDefs_AttributeDef> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESDefs_ToolAttributeDef::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_ToolTabularData.hxx
	py::class_<IGESDefs_ToolTabularData, std::unique_ptr<IGESDefs_ToolTabularData, Deleter<IGESDefs_ToolTabularData>>> cls_IGESDefs_ToolTabularData(mod, "IGESDefs_ToolTabularData", "Tool to work on a TabularData. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESDefs_ToolTabularData.def(py::init<>());
	cls_IGESDefs_ToolTabularData.def("ReadOwnParams", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESDefs_ToolTabularData::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESDefs_ToolTabularData.def("WriteOwnParams", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, IGESData_IGESWriter &) const ) &IGESDefs_ToolTabularData::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESDefs_ToolTabularData.def("OwnShared", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, Interface_EntityIterator &) const ) &IGESDefs_ToolTabularData::OwnShared, "Lists the Entities shared by a TabularData <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESDefs_ToolTabularData.def("DirChecker", (IGESData_DirChecker (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &) const ) &IGESDefs_ToolTabularData::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESDefs_ToolTabularData.def("OwnCheck", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESDefs_ToolTabularData::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESDefs_ToolTabularData.def("OwnCopy", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, const opencascade::handle<IGESDefs_TabularData> &, Interface_CopyTool &) const ) &IGESDefs_ToolTabularData::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESDefs_ToolTabularData.def("OwnDump", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESDefs_ToolTabularData::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_ToolGenericData.hxx
	py::class_<IGESDefs_ToolGenericData, std::unique_ptr<IGESDefs_ToolGenericData, Deleter<IGESDefs_ToolGenericData>>> cls_IGESDefs_ToolGenericData(mod, "IGESDefs_ToolGenericData", "Tool to work on a GenericData. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESDefs_ToolGenericData.def(py::init<>());
	cls_IGESDefs_ToolGenericData.def("ReadOwnParams", (void (IGESDefs_ToolGenericData::*)(const opencascade::handle<IGESDefs_GenericData> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESDefs_ToolGenericData::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESDefs_ToolGenericData.def("WriteOwnParams", (void (IGESDefs_ToolGenericData::*)(const opencascade::handle<IGESDefs_GenericData> &, IGESData_IGESWriter &) const ) &IGESDefs_ToolGenericData::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESDefs_ToolGenericData.def("OwnShared", (void (IGESDefs_ToolGenericData::*)(const opencascade::handle<IGESDefs_GenericData> &, Interface_EntityIterator &) const ) &IGESDefs_ToolGenericData::OwnShared, "Lists the Entities shared by a GenericData <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESDefs_ToolGenericData.def("DirChecker", (IGESData_DirChecker (IGESDefs_ToolGenericData::*)(const opencascade::handle<IGESDefs_GenericData> &) const ) &IGESDefs_ToolGenericData::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESDefs_ToolGenericData.def("OwnCheck", (void (IGESDefs_ToolGenericData::*)(const opencascade::handle<IGESDefs_GenericData> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESDefs_ToolGenericData::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESDefs_ToolGenericData.def("OwnCopy", (void (IGESDefs_ToolGenericData::*)(const opencascade::handle<IGESDefs_GenericData> &, const opencascade::handle<IGESDefs_GenericData> &, Interface_CopyTool &) const ) &IGESDefs_ToolGenericData::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESDefs_ToolGenericData.def("OwnDump", (void (IGESDefs_ToolGenericData::*)(const opencascade::handle<IGESDefs_GenericData> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESDefs_ToolGenericData::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_ToolAttributeTable.hxx
	py::class_<IGESDefs_ToolAttributeTable, std::unique_ptr<IGESDefs_ToolAttributeTable, Deleter<IGESDefs_ToolAttributeTable>>> cls_IGESDefs_ToolAttributeTable(mod, "IGESDefs_ToolAttributeTable", "Tool to work on a AttributeTable. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESDefs_ToolAttributeTable.def(py::init<>());
	cls_IGESDefs_ToolAttributeTable.def("ReadOwnParams", (void (IGESDefs_ToolAttributeTable::*)(const opencascade::handle<IGESDefs_AttributeTable> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESDefs_ToolAttributeTable::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESDefs_ToolAttributeTable.def("WriteOwnParams", (void (IGESDefs_ToolAttributeTable::*)(const opencascade::handle<IGESDefs_AttributeTable> &, IGESData_IGESWriter &) const ) &IGESDefs_ToolAttributeTable::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESDefs_ToolAttributeTable.def("OwnShared", (void (IGESDefs_ToolAttributeTable::*)(const opencascade::handle<IGESDefs_AttributeTable> &, Interface_EntityIterator &) const ) &IGESDefs_ToolAttributeTable::OwnShared, "Lists the Entities shared by a AttributeTable <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESDefs_ToolAttributeTable.def("DirChecker", (IGESData_DirChecker (IGESDefs_ToolAttributeTable::*)(const opencascade::handle<IGESDefs_AttributeTable> &) const ) &IGESDefs_ToolAttributeTable::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESDefs_ToolAttributeTable.def("OwnCheck", (void (IGESDefs_ToolAttributeTable::*)(const opencascade::handle<IGESDefs_AttributeTable> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESDefs_ToolAttributeTable::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESDefs_ToolAttributeTable.def("OwnCopy", (void (IGESDefs_ToolAttributeTable::*)(const opencascade::handle<IGESDefs_AttributeTable> &, const opencascade::handle<IGESDefs_AttributeTable> &, Interface_CopyTool &) const ) &IGESDefs_ToolAttributeTable::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESDefs_ToolAttributeTable.def("OwnDump", (void (IGESDefs_ToolAttributeTable::*)(const opencascade::handle<IGESDefs_AttributeTable> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESDefs_ToolAttributeTable::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_ReadWriteModule.hxx
	py::class_<IGESDefs_ReadWriteModule, opencascade::handle<IGESDefs_ReadWriteModule>, IGESData_ReadWriteModule> cls_IGESDefs_ReadWriteModule(mod, "IGESDefs_ReadWriteModule", "Defines Defs File Access Module for IGESDefs (specific parts) Specific actions concern : Read and Write Own Parameters of an IGESEntity.");
	cls_IGESDefs_ReadWriteModule.def(py::init<>());
	cls_IGESDefs_ReadWriteModule.def("CaseIGES", (Standard_Integer (IGESDefs_ReadWriteModule::*)(const Standard_Integer, const Standard_Integer) const ) &IGESDefs_ReadWriteModule::CaseIGES, "Defines Case Numbers for Entities of IGESDefs", py::arg("typenum"), py::arg("formnum"));
	cls_IGESDefs_ReadWriteModule.def("ReadOwnParams", (void (IGESDefs_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESDefs_ReadWriteModule::ReadOwnParams, "Reads own parameters from file for an Entity of IGESDefs", py::arg("CN"), py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESDefs_ReadWriteModule.def("WriteOwnParams", (void (IGESDefs_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, IGESData_IGESWriter &) const ) &IGESDefs_ReadWriteModule::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("CN"), py::arg("ent"), py::arg("IW"));
	cls_IGESDefs_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &IGESDefs_ReadWriteModule::get_type_name, "None");
	cls_IGESDefs_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_ReadWriteModule::get_type_descriptor, "None");
	cls_IGESDefs_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_ReadWriteModule::*)() const ) &IGESDefs_ReadWriteModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_GeneralModule.hxx
	py::class_<IGESDefs_GeneralModule, opencascade::handle<IGESDefs_GeneralModule>, IGESData_GeneralModule> cls_IGESDefs_GeneralModule(mod, "IGESDefs_GeneralModule", "Definition of General Services for IGESDefs (specific part) This Services comprise : Shared & Implied Lists, Copy, Check");
	cls_IGESDefs_GeneralModule.def(py::init<>());
	cls_IGESDefs_GeneralModule.def("OwnSharedCase", (void (IGESDefs_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const ) &IGESDefs_GeneralModule::OwnSharedCase, "Lists the Entities shared by a given IGESEntity <ent>, from its specific parameters : specific for each type", py::arg("CN"), py::arg("ent"), py::arg("iter"));
	cls_IGESDefs_GeneralModule.def("DirChecker", (IGESData_DirChecker (IGESDefs_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const ) &IGESDefs_GeneralModule::DirChecker, "Returns a DirChecker, specific for each type of Entity (identified by its Case Number) : this DirChecker defines constraints which must be respected by the DirectoryPart", py::arg("CN"), py::arg("ent"));
	cls_IGESDefs_GeneralModule.def("OwnCheckCase", (void (IGESDefs_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESDefs_GeneralModule::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESDefs_GeneralModule.def("NewVoid", (Standard_Boolean (IGESDefs_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const ) &IGESDefs_GeneralModule::NewVoid, "Specific creation of a new void entity", py::arg("CN"), py::arg("entto"));
	cls_IGESDefs_GeneralModule.def("OwnCopyCase", (void (IGESDefs_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const ) &IGESDefs_GeneralModule::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESDefs_GeneralModule.def("CategoryNumber", (Standard_Integer (IGESDefs_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const ) &IGESDefs_GeneralModule::CategoryNumber, "Returns a category number which characterizes an entity Auxiliary for all", py::arg("CN"), py::arg("ent"), py::arg("shares"));
	cls_IGESDefs_GeneralModule.def_static("get_type_name_", (const char * (*)()) &IGESDefs_GeneralModule::get_type_name, "None");
	cls_IGESDefs_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_GeneralModule::get_type_descriptor, "None");
	cls_IGESDefs_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_GeneralModule::*)() const ) &IGESDefs_GeneralModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_SpecificModule.hxx
	py::class_<IGESDefs_SpecificModule, opencascade::handle<IGESDefs_SpecificModule>, IGESData_SpecificModule> cls_IGESDefs_SpecificModule(mod, "IGESDefs_SpecificModule", "Defines Services attached to IGES Entities : Dump, for IGESDefs");
	cls_IGESDefs_SpecificModule.def(py::init<>());
	cls_IGESDefs_SpecificModule.def("OwnDump", (void (IGESDefs_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESDefs_SpecificModule::OwnDump, "Specific Dump (own parameters) for IGESDefs", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
	cls_IGESDefs_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESDefs_SpecificModule::get_type_name, "None");
	cls_IGESDefs_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_SpecificModule::get_type_descriptor, "None");
	cls_IGESDefs_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_SpecificModule::*)() const ) &IGESDefs_SpecificModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.hxx
	py::class_<IGESDefs_HArray1OfHArray1OfTextDisplayTemplate, opencascade::handle<IGESDefs_HArray1OfHArray1OfTextDisplayTemplate>, Standard_Transient> cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate(mod, "IGESDefs_HArray1OfHArray1OfTextDisplayTemplate", "None");
	cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("low"), py::arg("up"));
	cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("Lower", (Standard_Integer (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)() const ) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::Lower, "None");
	cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("Upper", (Standard_Integer (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)() const ) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::Upper, "None");
	cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("Length", (Standard_Integer (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)() const ) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::Length, "None");
	cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("SetValue", (void (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)(const Standard_Integer, const opencascade::handle<IGESGraph_HArray1OfTextDisplayTemplate> &)) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::SetValue, "None", py::arg("num"), py::arg("val"));
	cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("Value", (opencascade::handle<IGESGraph_HArray1OfTextDisplayTemplate> (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)(const Standard_Integer) const ) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::Value, "None", py::arg("num"));
	cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def_static("get_type_name_", (const char * (*)()) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::get_type_name, "None");
	cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::get_type_descriptor, "None");
	cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)() const ) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs.hxx
	py::class_<IGESDefs, std::unique_ptr<IGESDefs, Deleter<IGESDefs>>> cls_IGESDefs(mod, "IGESDefs", "To embody general definitions of Entities (Parameters, Tables ...)");
	cls_IGESDefs.def(py::init<>());
	cls_IGESDefs.def_static("Init_", (void (*)()) &IGESDefs::Init, "Prepares dynamic data (Protocol, Modules) for this package");
	cls_IGESDefs.def_static("Protocol_", (opencascade::handle<IGESDefs_Protocol> (*)()) &IGESDefs::Protocol, "Returns the Protocol for this Package");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESDefs_HArray1OfTabularData.hxx
	py::class_<IGESDefs_HArray1OfTabularData, opencascade::handle<IGESDefs_HArray1OfTabularData>, IGESDefs_Array1OfTabularData, Standard_Transient> cls_IGESDefs_HArray1OfTabularData(mod, "IGESDefs_HArray1OfTabularData", "None");
	cls_IGESDefs_HArray1OfTabularData.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESDefs_HArray1OfTabularData.def(py::init<const Standard_Integer, const Standard_Integer, const IGESDefs_Array1OfTabularData::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_IGESDefs_HArray1OfTabularData.def(py::init<const IGESDefs_Array1OfTabularData &>(), py::arg("theOther"));
	cls_IGESDefs_HArray1OfTabularData.def("Array1", (const IGESDefs_Array1OfTabularData & (IGESDefs_HArray1OfTabularData::*)() const ) &IGESDefs_HArray1OfTabularData::Array1, "None");
	cls_IGESDefs_HArray1OfTabularData.def("ChangeArray1", (IGESDefs_Array1OfTabularData & (IGESDefs_HArray1OfTabularData::*)()) &IGESDefs_HArray1OfTabularData::ChangeArray1, "None");
	cls_IGESDefs_HArray1OfTabularData.def_static("get_type_name_", (const char * (*)()) &IGESDefs_HArray1OfTabularData::get_type_name, "None");
	cls_IGESDefs_HArray1OfTabularData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_HArray1OfTabularData::get_type_descriptor, "None");
	cls_IGESDefs_HArray1OfTabularData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_HArray1OfTabularData::*)() const ) &IGESDefs_HArray1OfTabularData::DynamicType, "None");


}
