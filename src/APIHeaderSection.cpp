#include <pyOCCT_Common.hpp>

#include <IFSelect_Editor.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_EditForm.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_Type.hxx>
#include <APIHeaderSection_EditHeader.hxx>
#include <StepData_StepModel.hxx>
#include <Interface_Protocol.hxx>
#include <HeaderSection_FileName.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <HeaderSection_FileSchema.hxx>
#include <HeaderSection_FileDescription.hxx>
#include <APIHeaderSection_MakeHeader.hxx>

PYBIND11_MODULE(APIHeaderSection, mod) {

	// IMPORT
	py::module::import("OCCT.IFSelect");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.HeaderSection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\APIHeaderSection_EditHeader.hxx
	py::class_<APIHeaderSection_EditHeader, opencascade::handle<APIHeaderSection_EditHeader>, IFSelect_Editor> cls_APIHeaderSection_EditHeader(mod, "APIHeaderSection_EditHeader", "None");
	cls_APIHeaderSection_EditHeader.def(py::init<>());
	cls_APIHeaderSection_EditHeader.def("Label", (TCollection_AsciiString (APIHeaderSection_EditHeader::*)() const ) &APIHeaderSection_EditHeader::Label, "None");
	cls_APIHeaderSection_EditHeader.def("Recognize", (Standard_Boolean (APIHeaderSection_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &) const ) &APIHeaderSection_EditHeader::Recognize, "None", py::arg("form"));
	cls_APIHeaderSection_EditHeader.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const ) &APIHeaderSection_EditHeader::StringValue, "None", py::arg("form"), py::arg("num"));
	cls_APIHeaderSection_EditHeader.def("Apply", (Standard_Boolean (APIHeaderSection_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const ) &APIHeaderSection_EditHeader::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
	cls_APIHeaderSection_EditHeader.def("Load", (Standard_Boolean (APIHeaderSection_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const ) &APIHeaderSection_EditHeader::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
	cls_APIHeaderSection_EditHeader.def_static("get_type_name_", (const char * (*)()) &APIHeaderSection_EditHeader::get_type_name, "None");
	cls_APIHeaderSection_EditHeader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &APIHeaderSection_EditHeader::get_type_descriptor, "None");
	cls_APIHeaderSection_EditHeader.def("DynamicType", (const opencascade::handle<Standard_Type> & (APIHeaderSection_EditHeader::*)() const ) &APIHeaderSection_EditHeader::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\APIHeaderSection_MakeHeader.hxx
	py::class_<APIHeaderSection_MakeHeader, std::unique_ptr<APIHeaderSection_MakeHeader, Deleter<APIHeaderSection_MakeHeader>>> cls_APIHeaderSection_MakeHeader(mod, "APIHeaderSection_MakeHeader", "This class allows to consult and prepare/edit data stored in a Step Model Header");
	cls_APIHeaderSection_MakeHeader.def(py::init<>());
	cls_APIHeaderSection_MakeHeader.def(py::init<const Standard_Integer>(), py::arg("shapetype"));
	cls_APIHeaderSection_MakeHeader.def(py::init<const opencascade::handle<StepData_StepModel> &>(), py::arg("model"));
	cls_APIHeaderSection_MakeHeader.def("Init", (void (APIHeaderSection_MakeHeader::*)(const Standard_CString)) &APIHeaderSection_MakeHeader::Init, "Cancels the former definition and gives a FileName To be used when a Model has no well defined Header", py::arg("nameval"));
	cls_APIHeaderSection_MakeHeader.def("IsDone", (Standard_Boolean (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::IsDone, "Returns True if all data have been defined (see also HasFn, HasFs, HasFd)");
	cls_APIHeaderSection_MakeHeader.def("Apply", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<StepData_StepModel> &) const ) &APIHeaderSection_MakeHeader::Apply, "Creates an empty header for a new STEP model and allows the header fields to be completed.", py::arg("model"));
	cls_APIHeaderSection_MakeHeader.def("NewModel", (opencascade::handle<StepData_StepModel> (APIHeaderSection_MakeHeader::*)(const opencascade::handle<Interface_Protocol> &) const ) &APIHeaderSection_MakeHeader::NewModel, "Builds a Header, creates a new StepModel, then applies the Header to the StepModel The Schema Name is taken from the Protocol (if it inherits from StepData, else it is left in blanks)", py::arg("protocol"));
	cls_APIHeaderSection_MakeHeader.def("HasFn", (Standard_Boolean (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::HasFn, "Checks whether there is a file_name entity. Returns True if there is one.");
	cls_APIHeaderSection_MakeHeader.def("FnValue", (opencascade::handle<HeaderSection_FileName> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::FnValue, "Returns the file_name entity. Returns an empty entity if the file_name entity is not initialized.");
	cls_APIHeaderSection_MakeHeader.def("SetName", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetName, "None", py::arg("aName"));
	cls_APIHeaderSection_MakeHeader.def("Name", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::Name, "Returns the name attribute for the file_name entity.");
	cls_APIHeaderSection_MakeHeader.def("SetTimeStamp", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetTimeStamp, "None", py::arg("aTimeStamp"));
	cls_APIHeaderSection_MakeHeader.def("TimeStamp", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::TimeStamp, "Returns the value of the time_stamp attribute for the file_name entity.");
	cls_APIHeaderSection_MakeHeader.def("SetAuthor", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &APIHeaderSection_MakeHeader::SetAuthor, "None", py::arg("aAuthor"));
	cls_APIHeaderSection_MakeHeader.def("SetAuthorValue", (void (APIHeaderSection_MakeHeader::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetAuthorValue, "None", py::arg("num"), py::arg("aAuthor"));
	cls_APIHeaderSection_MakeHeader.def("Author", (opencascade::handle<Interface_HArray1OfHAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::Author, "None");
	cls_APIHeaderSection_MakeHeader.def("AuthorValue", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)(const Standard_Integer) const ) &APIHeaderSection_MakeHeader::AuthorValue, "Returns the value of the name attribute for the file_name entity.", py::arg("num"));
	cls_APIHeaderSection_MakeHeader.def("NbAuthor", (Standard_Integer (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::NbAuthor, "Returns the number of values for the author attribute in the file_name entity.");
	cls_APIHeaderSection_MakeHeader.def("SetOrganization", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &APIHeaderSection_MakeHeader::SetOrganization, "None", py::arg("aOrganization"));
	cls_APIHeaderSection_MakeHeader.def("SetOrganizationValue", (void (APIHeaderSection_MakeHeader::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetOrganizationValue, "None", py::arg("num"), py::arg("aOrganization"));
	cls_APIHeaderSection_MakeHeader.def("Organization", (opencascade::handle<Interface_HArray1OfHAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::Organization, "None");
	cls_APIHeaderSection_MakeHeader.def("OrganizationValue", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)(const Standard_Integer) const ) &APIHeaderSection_MakeHeader::OrganizationValue, "Returns the value of attribute organization for the file_name entity.", py::arg("num"));
	cls_APIHeaderSection_MakeHeader.def("NbOrganization", (Standard_Integer (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::NbOrganization, "Returns the number of values for the organization attribute in the file_name entity.");
	cls_APIHeaderSection_MakeHeader.def("SetPreprocessorVersion", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetPreprocessorVersion, "None", py::arg("aPreprocessorVersion"));
	cls_APIHeaderSection_MakeHeader.def("PreprocessorVersion", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::PreprocessorVersion, "Returns the name of the preprocessor_version for the file_name entity.");
	cls_APIHeaderSection_MakeHeader.def("SetOriginatingSystem", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetOriginatingSystem, "None", py::arg("aOriginatingSystem"));
	cls_APIHeaderSection_MakeHeader.def("OriginatingSystem", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::OriginatingSystem, "None");
	cls_APIHeaderSection_MakeHeader.def("SetAuthorisation", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetAuthorisation, "None", py::arg("aAuthorisation"));
	cls_APIHeaderSection_MakeHeader.def("Authorisation", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::Authorisation, "Returns the value of the authorization attribute for the file_name entity.");
	cls_APIHeaderSection_MakeHeader.def("HasFs", (Standard_Boolean (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::HasFs, "Checks whether there is a file_schema entity. Returns True if there is one.");
	cls_APIHeaderSection_MakeHeader.def("FsValue", (opencascade::handle<HeaderSection_FileSchema> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::FsValue, "Returns the file_schema entity. Returns an empty entity if the file_schema entity is not initialized.");
	cls_APIHeaderSection_MakeHeader.def("SetSchemaIdentifiers", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &APIHeaderSection_MakeHeader::SetSchemaIdentifiers, "None", py::arg("aSchemaIdentifiers"));
	cls_APIHeaderSection_MakeHeader.def("SetSchemaIdentifiersValue", (void (APIHeaderSection_MakeHeader::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetSchemaIdentifiersValue, "None", py::arg("num"), py::arg("aSchemaIdentifier"));
	cls_APIHeaderSection_MakeHeader.def("SchemaIdentifiers", (opencascade::handle<Interface_HArray1OfHAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::SchemaIdentifiers, "None");
	cls_APIHeaderSection_MakeHeader.def("SchemaIdentifiersValue", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)(const Standard_Integer) const ) &APIHeaderSection_MakeHeader::SchemaIdentifiersValue, "Returns the value of the schema_identifier attribute for the file_schema entity.", py::arg("num"));
	cls_APIHeaderSection_MakeHeader.def("NbSchemaIdentifiers", (Standard_Integer (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::NbSchemaIdentifiers, "Returns the number of values for the schema_identifier attribute in the file_schema entity.");
	cls_APIHeaderSection_MakeHeader.def("AddSchemaIdentifier", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::AddSchemaIdentifier, "Add a subname of schema (if not yet in the list)", py::arg("aSchemaIdentifier"));
	cls_APIHeaderSection_MakeHeader.def("HasFd", (Standard_Boolean (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::HasFd, "Checks whether there is a file_description entity. Returns True if there is one.");
	cls_APIHeaderSection_MakeHeader.def("FdValue", (opencascade::handle<HeaderSection_FileDescription> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::FdValue, "Returns the file_description entity. Returns an empty entity if the file_description entity is not initialized.");
	cls_APIHeaderSection_MakeHeader.def("SetDescription", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &APIHeaderSection_MakeHeader::SetDescription, "None", py::arg("aDescription"));
	cls_APIHeaderSection_MakeHeader.def("SetDescriptionValue", (void (APIHeaderSection_MakeHeader::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetDescriptionValue, "None", py::arg("num"), py::arg("aDescription"));
	cls_APIHeaderSection_MakeHeader.def("Description", (opencascade::handle<Interface_HArray1OfHAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::Description, "None");
	cls_APIHeaderSection_MakeHeader.def("DescriptionValue", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)(const Standard_Integer) const ) &APIHeaderSection_MakeHeader::DescriptionValue, "Returns the value of the description attribute for the file_description entity.", py::arg("num"));
	cls_APIHeaderSection_MakeHeader.def("NbDescription", (Standard_Integer (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::NbDescription, "Returns the number of values for the file_description entity in the STEP file header.");
	cls_APIHeaderSection_MakeHeader.def("SetImplementationLevel", (void (APIHeaderSection_MakeHeader::*)(const opencascade::handle<TCollection_HAsciiString> &)) &APIHeaderSection_MakeHeader::SetImplementationLevel, "None", py::arg("aImplementationLevel"));
	cls_APIHeaderSection_MakeHeader.def("ImplementationLevel", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_MakeHeader::*)() const ) &APIHeaderSection_MakeHeader::ImplementationLevel, "Returns the value of the implementation_level attribute for the file_description entity.");


}
