#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <HeaderSection_FileName.hxx>
#include <HeaderSection_FileSchema.hxx>
#include <HeaderSection_FileDescription.hxx>
#include <StepData_Protocol.hxx>
#include <HeaderSection_Protocol.hxx>
#include <StepData_FileRecognizer.hxx>
#include <HeaderSection_HeaderRecognizer.hxx>
#include <HeaderSection.hxx>

PYBIND11_MODULE(HeaderSection, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepData");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\HeaderSection_FileName.hxx
	py::class_<HeaderSection_FileName, opencascade::handle<HeaderSection_FileName>, Standard_Transient> cls_HeaderSection_FileName(mod, "HeaderSection_FileName", "None");
	cls_HeaderSection_FileName.def(py::init<>());
	cls_HeaderSection_FileName.def("Init", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::Init, "None", py::arg("aName"), py::arg("aTimeStamp"), py::arg("aAuthor"), py::arg("aOrganization"), py::arg("aPreprocessorVersion"), py::arg("aOriginatingSystem"), py::arg("aAuthorisation"));
	cls_HeaderSection_FileName.def("SetName", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetName, "None", py::arg("aName"));
	cls_HeaderSection_FileName.def("Name", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::Name, "None");
	cls_HeaderSection_FileName.def("SetTimeStamp", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetTimeStamp, "None", py::arg("aTimeStamp"));
	cls_HeaderSection_FileName.def("TimeStamp", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::TimeStamp, "None");
	cls_HeaderSection_FileName.def("SetAuthor", (void (HeaderSection_FileName::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &HeaderSection_FileName::SetAuthor, "None", py::arg("aAuthor"));
	cls_HeaderSection_FileName.def("Author", (opencascade::handle<Interface_HArray1OfHAsciiString> (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::Author, "None");
	cls_HeaderSection_FileName.def("AuthorValue", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)(const Standard_Integer) const ) &HeaderSection_FileName::AuthorValue, "None", py::arg("num"));
	cls_HeaderSection_FileName.def("NbAuthor", (Standard_Integer (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::NbAuthor, "None");
	cls_HeaderSection_FileName.def("SetOrganization", (void (HeaderSection_FileName::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &HeaderSection_FileName::SetOrganization, "None", py::arg("aOrganization"));
	cls_HeaderSection_FileName.def("Organization", (opencascade::handle<Interface_HArray1OfHAsciiString> (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::Organization, "None");
	cls_HeaderSection_FileName.def("OrganizationValue", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)(const Standard_Integer) const ) &HeaderSection_FileName::OrganizationValue, "None", py::arg("num"));
	cls_HeaderSection_FileName.def("NbOrganization", (Standard_Integer (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::NbOrganization, "None");
	cls_HeaderSection_FileName.def("SetPreprocessorVersion", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetPreprocessorVersion, "None", py::arg("aPreprocessorVersion"));
	cls_HeaderSection_FileName.def("PreprocessorVersion", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::PreprocessorVersion, "None");
	cls_HeaderSection_FileName.def("SetOriginatingSystem", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetOriginatingSystem, "None", py::arg("aOriginatingSystem"));
	cls_HeaderSection_FileName.def("OriginatingSystem", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::OriginatingSystem, "None");
	cls_HeaderSection_FileName.def("SetAuthorisation", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetAuthorisation, "None", py::arg("aAuthorisation"));
	cls_HeaderSection_FileName.def("Authorisation", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::Authorisation, "None");
	cls_HeaderSection_FileName.def_static("get_type_name_", (const char * (*)()) &HeaderSection_FileName::get_type_name, "None");
	cls_HeaderSection_FileName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HeaderSection_FileName::get_type_descriptor, "None");
	cls_HeaderSection_FileName.def("DynamicType", (const opencascade::handle<Standard_Type> & (HeaderSection_FileName::*)() const ) &HeaderSection_FileName::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HeaderSection_FileSchema.hxx
	py::class_<HeaderSection_FileSchema, opencascade::handle<HeaderSection_FileSchema>, Standard_Transient> cls_HeaderSection_FileSchema(mod, "HeaderSection_FileSchema", "None");
	cls_HeaderSection_FileSchema.def(py::init<>());
	cls_HeaderSection_FileSchema.def("Init", (void (HeaderSection_FileSchema::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &HeaderSection_FileSchema::Init, "None", py::arg("aSchemaIdentifiers"));
	cls_HeaderSection_FileSchema.def("SetSchemaIdentifiers", (void (HeaderSection_FileSchema::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &HeaderSection_FileSchema::SetSchemaIdentifiers, "None", py::arg("aSchemaIdentifiers"));
	cls_HeaderSection_FileSchema.def("SchemaIdentifiers", (opencascade::handle<Interface_HArray1OfHAsciiString> (HeaderSection_FileSchema::*)() const ) &HeaderSection_FileSchema::SchemaIdentifiers, "None");
	cls_HeaderSection_FileSchema.def("SchemaIdentifiersValue", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileSchema::*)(const Standard_Integer) const ) &HeaderSection_FileSchema::SchemaIdentifiersValue, "None", py::arg("num"));
	cls_HeaderSection_FileSchema.def("NbSchemaIdentifiers", (Standard_Integer (HeaderSection_FileSchema::*)() const ) &HeaderSection_FileSchema::NbSchemaIdentifiers, "None");
	cls_HeaderSection_FileSchema.def_static("get_type_name_", (const char * (*)()) &HeaderSection_FileSchema::get_type_name, "None");
	cls_HeaderSection_FileSchema.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HeaderSection_FileSchema::get_type_descriptor, "None");
	cls_HeaderSection_FileSchema.def("DynamicType", (const opencascade::handle<Standard_Type> & (HeaderSection_FileSchema::*)() const ) &HeaderSection_FileSchema::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HeaderSection_FileDescription.hxx
	py::class_<HeaderSection_FileDescription, opencascade::handle<HeaderSection_FileDescription>, Standard_Transient> cls_HeaderSection_FileDescription(mod, "HeaderSection_FileDescription", "None");
	cls_HeaderSection_FileDescription.def(py::init<>());
	cls_HeaderSection_FileDescription.def("Init", (void (HeaderSection_FileDescription::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileDescription::Init, "None", py::arg("aDescription"), py::arg("aImplementationLevel"));
	cls_HeaderSection_FileDescription.def("SetDescription", (void (HeaderSection_FileDescription::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &HeaderSection_FileDescription::SetDescription, "None", py::arg("aDescription"));
	cls_HeaderSection_FileDescription.def("Description", (opencascade::handle<Interface_HArray1OfHAsciiString> (HeaderSection_FileDescription::*)() const ) &HeaderSection_FileDescription::Description, "None");
	cls_HeaderSection_FileDescription.def("DescriptionValue", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileDescription::*)(const Standard_Integer) const ) &HeaderSection_FileDescription::DescriptionValue, "None", py::arg("num"));
	cls_HeaderSection_FileDescription.def("NbDescription", (Standard_Integer (HeaderSection_FileDescription::*)() const ) &HeaderSection_FileDescription::NbDescription, "None");
	cls_HeaderSection_FileDescription.def("SetImplementationLevel", (void (HeaderSection_FileDescription::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileDescription::SetImplementationLevel, "None", py::arg("aImplementationLevel"));
	cls_HeaderSection_FileDescription.def("ImplementationLevel", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileDescription::*)() const ) &HeaderSection_FileDescription::ImplementationLevel, "None");
	cls_HeaderSection_FileDescription.def_static("get_type_name_", (const char * (*)()) &HeaderSection_FileDescription::get_type_name, "None");
	cls_HeaderSection_FileDescription.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HeaderSection_FileDescription::get_type_descriptor, "None");
	cls_HeaderSection_FileDescription.def("DynamicType", (const opencascade::handle<Standard_Type> & (HeaderSection_FileDescription::*)() const ) &HeaderSection_FileDescription::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HeaderSection_Protocol.hxx
	py::class_<HeaderSection_Protocol, opencascade::handle<HeaderSection_Protocol>, StepData_Protocol> cls_HeaderSection_Protocol(mod, "HeaderSection_Protocol", "Protocol for HeaderSection Entities It requires HeaderSection as a Resource");
	cls_HeaderSection_Protocol.def(py::init<>());
	cls_HeaderSection_Protocol.def("TypeNumber", (Standard_Integer (HeaderSection_Protocol::*)(const opencascade::handle<Standard_Type> &) const ) &HeaderSection_Protocol::TypeNumber, "Returns a Case Number for each of the HeaderSection Entities", py::arg("atype"));
	cls_HeaderSection_Protocol.def("SchemaName", (Standard_CString (HeaderSection_Protocol::*)() const ) &HeaderSection_Protocol::SchemaName, "None");
	cls_HeaderSection_Protocol.def_static("get_type_name_", (const char * (*)()) &HeaderSection_Protocol::get_type_name, "None");
	cls_HeaderSection_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HeaderSection_Protocol::get_type_descriptor, "None");
	cls_HeaderSection_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (HeaderSection_Protocol::*)() const ) &HeaderSection_Protocol::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HeaderSection_HeaderRecognizer.hxx
	py::class_<HeaderSection_HeaderRecognizer, opencascade::handle<HeaderSection_HeaderRecognizer>, StepData_FileRecognizer> cls_HeaderSection_HeaderRecognizer(mod, "HeaderSection_HeaderRecognizer", "Recognizes STEP Standard Header Entities (FileName, FileDescription, FileSchema)");
	cls_HeaderSection_HeaderRecognizer.def(py::init<>());
	cls_HeaderSection_HeaderRecognizer.def_static("get_type_name_", (const char * (*)()) &HeaderSection_HeaderRecognizer::get_type_name, "None");
	cls_HeaderSection_HeaderRecognizer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HeaderSection_HeaderRecognizer::get_type_descriptor, "None");
	cls_HeaderSection_HeaderRecognizer.def("DynamicType", (const opencascade::handle<Standard_Type> & (HeaderSection_HeaderRecognizer::*)() const ) &HeaderSection_HeaderRecognizer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HeaderSection.hxx
	py::class_<HeaderSection, std::unique_ptr<HeaderSection, Deleter<HeaderSection>>> cls_HeaderSection(mod, "HeaderSection", "None");
	cls_HeaderSection.def(py::init<>());
	cls_HeaderSection.def_static("Protocol_", (opencascade::handle<HeaderSection_Protocol> (*)()) &HeaderSection::Protocol, "creates a Protocol");


}
