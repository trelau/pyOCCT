#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TObj_Common.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TDocStd_Application.hxx>
#include <TObj_Application.hxx>
#include <Message_Messenger.hxx>
#include <TDocStd_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Message_Gravity.hxx>
#include <Standard_Type.hxx>
#include <Standard_Transient.hxx>
#include <TObj_Model.hxx>
#include <TDF_Label.hxx>
#include <TObj_ObjectIterator.hxx>
#include <TObj_Object.hxx>
#include <TObj_TNameContainer.hxx>
#include <TObj_CheckModel.hxx>
#include <TObj_Partition.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <TObj_Assistant.hxx>
#include <TObj_DeletingMode.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TObj_SequenceOfObject.hxx>
#include <Standard_OStream.hxx>
#include <TObj_Persistence.hxx>
#include <TDF_Attribute.hxx>
#include <TObj_Container.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <Message_Algorithm.hxx>
#include <TObj_HiddenPartition.hxx>
#include <TObj_LabelIterator.hxx>
#include <TObj_SequenceOfIterator.hxx>
#include <TObj_ModelIterator.hxx>
#include <TObj_OcafObjectIterator.hxx>
#include <TObj_ReferenceIterator.hxx>
#include <TObj_SequenceIterator.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <NCollection_SparseArray.hxx>
#include <TObj_TIntSparseArray.hxx>
#include <TDF_DeltaOnModification.hxx>
#include <TDF_AttributeDelta.hxx>
#include <TObj_TModel.hxx>
#include <TObj_TObject.hxx>
#include <TObj_TReference.hxx>
#include <TObj_TXYZ.hxx>
#include <gp_XYZ.hxx>

PYBIND11_MODULE(TObj, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_DeletingMode.hxx
	mod.attr("TObj_FreeOnly") = py::cast(int(TObj_FreeOnly));
	mod.attr("TObj_KeepDepending") = py::cast(int(TObj_KeepDepending));
	mod.attr("TObj_Forced") = py::cast(int(TObj_Forced));


	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_Common.hxx
	mod.def("HashCode", (Standard_Integer (*)(const opencascade::handle<TCollection_HExtendedString> &, const Standard_Integer)) &HashCode, "Methods inline implimentation for HExtendedString", py::arg("theStr"), py::arg("theBnd"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_Common.hxx
	mod.def("IsEqual", (Standard_Boolean (*)(const opencascade::handle<TCollection_HExtendedString> &, const opencascade::handle<TCollection_HExtendedString> &)) &IsEqual, "None", py::arg("theStr1"), py::arg("theStr2"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_Application.hxx
	py::class_<TObj_Application, opencascade::handle<TObj_Application>, TDocStd_Application> cls_TObj_Application(mod, "TObj_Application", "This is a base class for OCAF based TObj models with declared virtual methods");
	cls_TObj_Application.def_static("GetInstance_", (opencascade::handle<TObj_Application> (*)()) &TObj_Application::GetInstance, "Returns static instance of the application");
	cls_TObj_Application.def("Messenger", (opencascade::handle<Message_Messenger> & (TObj_Application::*)()) &TObj_Application::Messenger, "Returns reference to associated messenger handle");
	cls_TObj_Application.def("SaveDocument", (Standard_Boolean (TObj_Application::*)(const opencascade::handle<TDocStd_Document> &, const TCollection_ExtendedString &)) &TObj_Application::SaveDocument, "Saving the OCAF document to a file", py::arg("theSourceDoc"), py::arg("theTargetFile"));
	cls_TObj_Application.def("LoadDocument", (Standard_Boolean (TObj_Application::*)(const TCollection_ExtendedString &, opencascade::handle<TDocStd_Document> &)) &TObj_Application::LoadDocument, "Loading the OCAF document from a file", py::arg("theSourceFile"), py::arg("theTargetDoc"));
	cls_TObj_Application.def("CreateNewDocument", (Standard_Boolean (TObj_Application::*)(opencascade::handle<TDocStd_Document> &, const TCollection_ExtendedString &)) &TObj_Application::CreateNewDocument, "Create the OCAF document from scratch", py::arg("theDoc"), py::arg("theFormat"));
	cls_TObj_Application.def("ErrorMessage", (void (TObj_Application::*)(const TCollection_ExtendedString &, const Message_Gravity)) &TObj_Application::ErrorMessage, "Signal error during Load or Save Default imiplementation is empty", py::arg("theMsg"), py::arg("theLevel"));
	cls_TObj_Application.def("ErrorMessage", (void (TObj_Application::*)(const TCollection_ExtendedString &)) &TObj_Application::ErrorMessage, "Signal error during Load or Save Default imiplementation invoke previous declaration with 0", py::arg("theMsg"));
	cls_TObj_Application.def("SetVerbose", (void (TObj_Application::*)(const Standard_Boolean)) &TObj_Application::SetVerbose, "Sets the verbose flag, meaning that load/save models should show CPU and elapsed times", py::arg("isVerbose"));
	cls_TObj_Application.def("IsVerbose", (Standard_Boolean (TObj_Application::*)() const ) &TObj_Application::IsVerbose, "Returns the verbose flag");
	cls_TObj_Application.def("ResourcesName", (Standard_CString (TObj_Application::*)()) &TObj_Application::ResourcesName, "Return name of resource (i.e. 'TObj')");
	cls_TObj_Application.def_static("get_type_name_", (const char * (*)()) &TObj_Application::get_type_name, "None");
	cls_TObj_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_Application::get_type_descriptor, "None");
	cls_TObj_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_Application::*)() const ) &TObj_Application::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_Model.hxx
	py::class_<TObj_Model, opencascade::handle<TObj_Model>, Standard_Transient> cls_TObj_Model(mod, "TObj_Model", "Base class for OCAF based models. Defines common behaviour for all models based on TObject classes, basic services to access model objects and common operations with the model. Provides default implementation for many methods.");
	cls_TObj_Model.def("SetMessenger", (void (TObj_Model::*)(const opencascade::handle<Message_Messenger> &)) &TObj_Model::SetMessenger, "Set messenger to use for messages output", py::arg("theMsgr"));
	cls_TObj_Model.def("Messenger", (opencascade::handle<Message_Messenger> (TObj_Model::*)() const ) &TObj_Model::Messenger, "Get messenger used for messages output (by default, the messenger from application is used)");
	cls_TObj_Model.def("Load", (Standard_Boolean (TObj_Model::*)(const TCollection_ExtendedString &)) &TObj_Model::Load, "Load the OCAF model from a file. If the filename is empty or file does not exists, it just initializes model by empty data.", py::arg("theFile"));
	cls_TObj_Model.def("SaveAs", (Standard_Boolean (TObj_Model::*)(const TCollection_ExtendedString &)) &TObj_Model::SaveAs, "Save the model to a file", py::arg("theFile"));
	cls_TObj_Model.def("Save", (Standard_Boolean (TObj_Model::*)()) &TObj_Model::Save, "Save the model to the same file");
	cls_TObj_Model.def("Close", (Standard_Boolean (TObj_Model::*)()) &TObj_Model::Close, "Close the model");
	cls_TObj_Model.def("CloseDocument", (void (TObj_Model::*)(const opencascade::handle<TDocStd_Document> &)) &TObj_Model::CloseDocument, "Close Free OCAF document", py::arg("theDoc"));
	cls_TObj_Model.def_static("GetDocumentModel_", (opencascade::handle<TObj_Model> (*)(const TDF_Label &)) &TObj_Model::GetDocumentModel, "Returns model which contains a document with the label, or NULL handle if label is NULL", py::arg("theLabel"));
	cls_TObj_Model.def("GetFile", (opencascade::handle<TCollection_HExtendedString> (TObj_Model::*)() const ) &TObj_Model::GetFile, "Returns the full file name this model is to be saved to, or null if the model was not saved yet");
	cls_TObj_Model.def("GetObjects", (opencascade::handle<TObj_ObjectIterator> (TObj_Model::*)() const ) &TObj_Model::GetObjects, "Returns an Iterator on all objects in the Model");
	cls_TObj_Model.def("GetChildren", (opencascade::handle<TObj_ObjectIterator> (TObj_Model::*)() const ) &TObj_Model::GetChildren, "Returns an Iterator on objects in the main partition");
	cls_TObj_Model.def("FindObject", (opencascade::handle<TObj_Object> (TObj_Model::*)(const opencascade::handle<TCollection_HExtendedString> &, const opencascade::handle<TObj_TNameContainer> &) const ) &TObj_Model::FindObject, "Returns an Object by given Name (or Null if not found).", py::arg("theName"), py::arg("theDictionary"));
	cls_TObj_Model.def("GetChecker", (opencascade::handle<TObj_CheckModel> (TObj_Model::*)() const ) &TObj_Model::GetChecker, "Returns the tool checking model consistency. Descendant may redefine it to return its own tool.");
	cls_TObj_Model.def("GetRoot", (opencascade::handle<TObj_Object> (TObj_Model::*)() const ) &TObj_Model::GetRoot, "Returns root object of model");
	cls_TObj_Model.def("GetMainPartition", (opencascade::handle<TObj_Partition> (TObj_Model::*)() const ) &TObj_Model::GetMainPartition, "Returns root object of model");
	cls_TObj_Model.def("GetLabel", (TDF_Label (TObj_Model::*)() const ) &TObj_Model::GetLabel, "Returns OCAF label on which model data are stored.");
	cls_TObj_Model.def("GetModelName", (opencascade::handle<TCollection_HExtendedString> (TObj_Model::*)() const ) &TObj_Model::GetModelName, "Returns the name of the model");
	cls_TObj_Model.def_static("SetNewName_", (void (*)(const opencascade::handle<TObj_Object> &)) &TObj_Model::SetNewName, "Sets new unique name for the object", py::arg("theObject"));
	cls_TObj_Model.def("IsRegisteredName", (Standard_Boolean (TObj_Model::*)(const opencascade::handle<TCollection_HExtendedString> &, const opencascade::handle<TObj_TNameContainer> &) const ) &TObj_Model::IsRegisteredName, "Returns True is name is registered in the names map The input argument may be NULL handle, then model check in own global container", py::arg("theName"), py::arg("theDictionary"));
	cls_TObj_Model.def("RegisterName", (void (TObj_Model::*)(const opencascade::handle<TCollection_HExtendedString> &, const TDF_Label &, const opencascade::handle<TObj_TNameContainer> &) const ) &TObj_Model::RegisterName, "Register name in the map The input argument may be NULL handle, then model check in own global container", py::arg("theName"), py::arg("theLabel"), py::arg("theDictionary"));
	cls_TObj_Model.def("UnRegisterName", (void (TObj_Model::*)(const opencascade::handle<TCollection_HExtendedString> &, const opencascade::handle<TObj_TNameContainer> &) const ) &TObj_Model::UnRegisterName, "Unregisters name from the map The input argument may be NULL handle, then model check in own global container", py::arg("theName"), py::arg("theDictionary"));
	cls_TObj_Model.def("HasOpenCommand", (Standard_Boolean (TObj_Model::*)() const ) &TObj_Model::HasOpenCommand, "Returns True if a Command transaction is open Starting, finishing the transaction");
	cls_TObj_Model.def("OpenCommand", (void (TObj_Model::*)() const ) &TObj_Model::OpenCommand, "Open a new command transaction.");
	cls_TObj_Model.def("CommitCommand", (void (TObj_Model::*)() const ) &TObj_Model::CommitCommand, "Commit the Command transaction. Do nothing If there is no Command transaction open.");
	cls_TObj_Model.def("AbortCommand", (void (TObj_Model::*)() const ) &TObj_Model::AbortCommand, "Abort the Command transaction. Do nothing If there is no Command transaction open.");
	cls_TObj_Model.def("IsModified", (Standard_Boolean (TObj_Model::*)() const ) &TObj_Model::IsModified, "Modification status");
	cls_TObj_Model.def("SetModified", (void (TObj_Model::*)(const Standard_Boolean)) &TObj_Model::SetModified, "Sets modification status", py::arg("theModified"));
	cls_TObj_Model.def("GetApplication", (const opencascade::handle<TObj_Application> (TObj_Model::*)()) &TObj_Model::GetApplication, "Returns handle to static instance of the relevant application class");
	cls_TObj_Model.def("GetFormat", (TCollection_ExtendedString (TObj_Model::*)() const ) &TObj_Model::GetFormat, "Returns the format for save/restore. This implementation returns 'BinOcaf'. The method should be redefined for those models that should use another format.");
	cls_TObj_Model.def("GetFormatVersion", (Standard_Integer (TObj_Model::*)() const ) &TObj_Model::GetFormatVersion, "Returns the version of format stored in TObj file");
	cls_TObj_Model.def("Update", (Standard_Boolean (TObj_Model::*)()) &TObj_Model::Update, "this method is called before activating this model");
	cls_TObj_Model.def("GetGUID", (Standard_GUID (TObj_Model::*)() const ) &TObj_Model::GetGUID, "Defines interface GUID for TObj_Model");
	cls_TObj_Model.def("GetDictionary", (opencascade::handle<TObj_TNameContainer> (TObj_Model::*)() const ) &TObj_Model::GetDictionary, "Returns the map of names of the objects");
	cls_TObj_Model.def("GetDocument", (opencascade::handle<TDocStd_Document> (TObj_Model::*)() const ) &TObj_Model::GetDocument, "Returns OCAF document of Model");
	cls_TObj_Model.def("SetLabel", (void (TObj_Model::*)(const TDF_Label &)) &TObj_Model::SetLabel, "Sets OCAF label on which model data are stored. Used by persistence mechanism.", py::arg("theLabel"));
	cls_TObj_Model.def("Paste", [](TObj_Model &self, opencascade::handle<TObj_Model> a0) -> Standard_Boolean { return self.Paste(a0); }, py::arg("theModel"));
	cls_TObj_Model.def("Paste", (Standard_Boolean (TObj_Model::*)(opencascade::handle<TObj_Model>, opencascade::handle<TDF_RelocationTable>)) &TObj_Model::Paste, "Pastes me to the new model references will not be copied if theRelocTable is not 0 if theRelocTable is not NULL theRelocTable is filled by objects", py::arg("theModel"), py::arg("theRelocTable"));
	cls_TObj_Model.def("NewEmpty", (opencascade::handle<TObj_Model> (TObj_Model::*)()) &TObj_Model::NewEmpty, "This function have to create a new model with type like me");
	cls_TObj_Model.def("CopyReferences", (void (TObj_Model::*)(const opencascade::handle<TObj_Model> &, const opencascade::handle<TDF_RelocationTable> &)) &TObj_Model::CopyReferences, "Copy references from me to the other", py::arg("theTarget"), py::arg("theRelocTable"));
	cls_TObj_Model.def_static("get_type_name_", (const char * (*)()) &TObj_Model::get_type_name, "None");
	cls_TObj_Model.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_Model::get_type_descriptor, "None");
	cls_TObj_Model.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_Model::*)() const ) &TObj_Model::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_Assistant.hxx
	py::class_<TObj_Assistant, std::unique_ptr<TObj_Assistant, Deleter<TObj_Assistant>>> cls_TObj_Assistant(mod, "TObj_Assistant", "This class provides interface to the static data to be used during save or load models.");
	cls_TObj_Assistant.def(py::init<>());
	cls_TObj_Assistant.def_static("FindModel_", (opencascade::handle<TObj_Model> (*)(const Standard_CString)) &TObj_Assistant::FindModel, "Finds model by name", py::arg("theName"));
	cls_TObj_Assistant.def_static("BindModel_", (void (*)(const opencascade::handle<TObj_Model>)) &TObj_Assistant::BindModel, "Binds model to the map", py::arg("theModel"));
	cls_TObj_Assistant.def_static("ClearModelMap_", (void (*)()) &TObj_Assistant::ClearModelMap, "Clears all records from the model map");
	cls_TObj_Assistant.def_static("FindType_", (opencascade::handle<Standard_Type> (*)(const Standard_Integer)) &TObj_Assistant::FindType, "Finds Standard_Type by index; returns NULL handle if not found", py::arg("theTypeIndex"));
	cls_TObj_Assistant.def_static("FindTypeIndex_", (Standard_Integer (*)(const opencascade::handle<Standard_Type> &)) &TObj_Assistant::FindTypeIndex, "Rinds index by Standard_Type; returns 0 if not found", py::arg("theType"));
	cls_TObj_Assistant.def_static("BindType_", (Standard_Integer (*)(const opencascade::handle<Standard_Type> &)) &TObj_Assistant::BindType, "Binds Standard_Type to the map; returns index of bound type", py::arg("theType"));
	cls_TObj_Assistant.def_static("ClearTypeMap_", (void (*)()) &TObj_Assistant::ClearTypeMap, "Clears map of types");
	cls_TObj_Assistant.def_static("SetCurrentModel_", (void (*)(const opencascade::handle<TObj_Model> &)) &TObj_Assistant::SetCurrentModel, "Sets current model", py::arg("theModel"));
	cls_TObj_Assistant.def_static("GetCurrentModel_", (opencascade::handle<TObj_Model> (*)()) &TObj_Assistant::GetCurrentModel, "Returns current model");
	cls_TObj_Assistant.def_static("UnSetCurrentModel_", (void (*)()) &TObj_Assistant::UnSetCurrentModel, "Unsets current model");
	cls_TObj_Assistant.def_static("GetAppVersion_", (Standard_Integer (*)()) &TObj_Assistant::GetAppVersion, "Returns the version of application which wrote the currently read document. Returns 0 if it has not been set yet for the current document.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_Object.hxx
	py::class_<TObj_Object, opencascade::handle<TObj_Object>, Standard_Transient> cls_TObj_Object(mod, "TObj_Object", "Basis class for transient objects in OCAF-based models");
	cls_TObj_Object.def("GetModel", (opencascade::handle<TObj_Model> (TObj_Object::*)() const ) &TObj_Object::GetModel, "Returns the model to which the object belongs");
	cls_TObj_Object.def("GetChildren", [](TObj_Object &self) -> opencascade::handle<TObj_ObjectIterator> { return self.GetChildren(); });
	cls_TObj_Object.def("GetChildren", (opencascade::handle<TObj_ObjectIterator> (TObj_Object::*)(const opencascade::handle<Standard_Type> &) const ) &TObj_Object::GetChildren, "Returns iterator for the child objects. This method provides tree-like view of the objects hierarchy. The references to other objects are not considered as children. theType narrows a variety of iterated objects The default implementation search for children on 1 sublavel of the children sub label", py::arg("theType"));
	cls_TObj_Object.def("GetChildLabel", (TDF_Label (TObj_Object::*)() const ) &TObj_Object::GetChildLabel, "Returns the label under which children are stored");
	cls_TObj_Object.def("getChildLabel", (TDF_Label (TObj_Object::*)(const Standard_Integer) const ) &TObj_Object::getChildLabel, "Returns the label for child with rank", py::arg("theRank"));
	cls_TObj_Object.def("GetLabel", (TDF_Label (TObj_Object::*)() const ) &TObj_Object::GetLabel, "Returns the OCAF label on which object`s data are stored");
	cls_TObj_Object.def("GetDataLabel", (TDF_Label (TObj_Object::*)() const ) &TObj_Object::GetDataLabel, "Returns the label which is the root for data OCAF sub-tree");
	cls_TObj_Object.def("GetReferenceLabel", (TDF_Label (TObj_Object::*)() const ) &TObj_Object::GetReferenceLabel, "Returns the label which is the root for reference OCAF sub-tree");
	cls_TObj_Object.def("GetDictionary", (opencascade::handle<TObj_TNameContainer> (TObj_Object::*)() const ) &TObj_Object::GetDictionary, "Returns the map of names of the objects Default implementation returns global Dictionary of the model");
	cls_TObj_Object.def("GetName", (opencascade::handle<TCollection_HExtendedString> (TObj_Object::*)() const ) &TObj_Object::GetName, "Returns the name of the object (empty string if object has no name)");
	cls_TObj_Object.def("GetName", (Standard_Boolean (TObj_Object::*)(TCollection_ExtendedString &) const ) &TObj_Object::GetName, "Returns the Standard_True is object has name and returns name to theName", py::arg("theName"));
	cls_TObj_Object.def("GetName", (Standard_Boolean (TObj_Object::*)(TCollection_AsciiString &) const ) &TObj_Object::GetName, "Returns the Standard_True is object has name and returns name to theName", py::arg("theName"));
	cls_TObj_Object.def("SetName", (Standard_Boolean (TObj_Object::*)(const opencascade::handle<TCollection_HExtendedString> &) const ) &TObj_Object::SetName, "Sets name of the object. Returns False if theName is not unique.", py::arg("theName"));
	cls_TObj_Object.def("SetName", (Standard_Boolean (TObj_Object::*)(const opencascade::handle<TCollection_HAsciiString> &) const ) &TObj_Object::SetName, "Sets name of the object. Returns False if theName is not unique.", py::arg("theName"));
	cls_TObj_Object.def("SetName", (Standard_Boolean (TObj_Object::*)(const Standard_CString) const ) &TObj_Object::SetName, "Sets name of the object. Returns False if theName is not unique.", py::arg("name"));
	cls_TObj_Object.def("GetNameForClone", (opencascade::handle<TCollection_HExtendedString> (TObj_Object::*)(const opencascade::handle<TObj_Object> &) const ) &TObj_Object::GetNameForClone, "Returns name for copy default implementation returns the same name", py::arg(""));
	cls_TObj_Object.def("HasReference", (Standard_Boolean (TObj_Object::*)(const opencascade::handle<TObj_Object> &) const ) &TObj_Object::HasReference, "Returns True if object has reference to indicated object", py::arg("theObject"));
	cls_TObj_Object.def("GetReferences", [](TObj_Object &self) -> opencascade::handle<TObj_ObjectIterator> { return self.GetReferences(); });
	cls_TObj_Object.def("GetReferences", (opencascade::handle<TObj_ObjectIterator> (TObj_Object::*)(const opencascade::handle<Standard_Type> &) const ) &TObj_Object::GetReferences, "Returns an Iterator containing objects that compose the this one theType narrows a variety of iterated objects", py::arg("theType"));
	cls_TObj_Object.def("RemoveAllReferences", (void (TObj_Object::*)()) &TObj_Object::RemoveAllReferences, "Remove all references to other objects, by removing all reference attributes");
	cls_TObj_Object.def("GetBackReferences", [](TObj_Object &self) -> opencascade::handle<TObj_ObjectIterator> { return self.GetBackReferences(); });
	cls_TObj_Object.def("GetBackReferences", (opencascade::handle<TObj_ObjectIterator> (TObj_Object::*)(const opencascade::handle<Standard_Type> &) const ) &TObj_Object::GetBackReferences, "Returns iterator for the objects which depend on this one. These reffering objects may belong to other models. theType narrows a variety of iterated objects", py::arg("theType"));
	cls_TObj_Object.def("AddBackReference", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &)) &TObj_Object::AddBackReference, "Registers another object as being dependent on this one. Stores back references under sublabel 2 (purely transient data, not subject to persistency).", py::arg("theObject"));
	cls_TObj_Object.def("RemoveBackReference", [](TObj_Object &self, const opencascade::handle<TObj_Object> & a0) -> void { return self.RemoveBackReference(a0); }, py::arg("theObject"));
	cls_TObj_Object.def("RemoveBackReference", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &, const Standard_Boolean)) &TObj_Object::RemoveBackReference, "Removes information on dependent object (back reference). If theSingleOnly is true only the first back reference is removed in the case of duplicate items.", py::arg("theObject"), py::arg("theSingleOnly"));
	cls_TObj_Object.def("RemoveBackReferences", [](TObj_Object &self) -> Standard_Boolean { return self.RemoveBackReferences(); });
	cls_TObj_Object.def("RemoveBackReferences", (Standard_Boolean (TObj_Object::*)(const TObj_DeletingMode)) &TObj_Object::RemoveBackReferences, "Removes all back reference by removing references from other to me.", py::arg("theMode"));
	cls_TObj_Object.def("ClearBackReferences", (void (TObj_Object::*)()) &TObj_Object::ClearBackReferences, "The default implementation just clear the back references container");
	cls_TObj_Object.def("HasBackReferences", (Standard_Boolean (TObj_Object::*)() const ) &TObj_Object::HasBackReferences, "Returns TRUE if obejct has 1 or more back references");
	cls_TObj_Object.def("ReplaceReference", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &, const opencascade::handle<TObj_Object> &)) &TObj_Object::ReplaceReference, "Replace reference from old object to new object. If it is not possible, may raise exception. If new object is null then simple remove reference to old object.", py::arg("theOldObject"), py::arg("theNewObject"));
	cls_TObj_Object.def("GetBadReference", (Standard_Boolean (TObj_Object::*)(const TDF_Label &, TDF_Label &) const ) &TObj_Object::GetBadReference, "Return True if this refers to the model theRoot belongs to and a referred label is not a descendant of theRoot. In this case theBadReference returns the currently referred label.", py::arg("theRoot"), py::arg("theBadReference"));
	cls_TObj_Object.def("RelocateReferences", [](TObj_Object &self, const TDF_Label & a0, const TDF_Label & a1) -> Standard_Boolean { return self.RelocateReferences(a0, a1); }, py::arg("theFromRoot"), py::arg("theToRoot"));
	cls_TObj_Object.def("RelocateReferences", (Standard_Boolean (TObj_Object::*)(const TDF_Label &, const TDF_Label &, const Standard_Boolean)) &TObj_Object::RelocateReferences, "Make that each reference pointing to a descendant label of theFromRoot to point to an equivalent label under theToRoot. Return False if a resulting reference does not point to an TObj_Object Example: a referred object label = 0:3:24:7:2:7 theFromRoot = 0:3:24 theToRoot = 0:2 a new referred label = 0:2:7:2:7", py::arg("theFromRoot"), py::arg("theToRoot"), py::arg("theUpdateBackRefs"));
	cls_TObj_Object.def("CanRemoveReference", (Standard_Boolean (TObj_Object::*)(const opencascade::handle<TObj_Object> &) const ) &TObj_Object::CanRemoveReference, "Returns True if the referred object theObject can be deleted without deletion of this object. Default implementation does nothing and returns False.", py::arg("theObject"));
	cls_TObj_Object.def("RemoveReference", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &)) &TObj_Object::RemoveReference, "Removes reference to the object by replace reference to NULL object", py::arg("theObject"));
	cls_TObj_Object.def("BeforeForgetReference", (void (TObj_Object::*)(const TDF_Label &)) &TObj_Object::BeforeForgetReference, "Invokes from TObj_TReference::BeforeForget(). theLabel - label on that reference become removed Default implementation is empty", py::arg(""));
	cls_TObj_Object.def("CanDetach", [](TObj_Object &self) -> Standard_Boolean { return self.CanDetach(); });
	cls_TObj_Object.def("CanDetach", (Standard_Boolean (TObj_Object::*)(const TObj_DeletingMode)) &TObj_Object::CanDetach, "Checks if object can be detached with specified mode", py::arg("theMode"));
	cls_TObj_Object.def("Detach", [](TObj_Object &self) -> Standard_Boolean { return self.Detach(); });
	cls_TObj_Object.def("Detach", (Standard_Boolean (TObj_Object::*)(const TObj_DeletingMode)) &TObj_Object::Detach, "Deletes the object from the model. The dependent objects are either deleted or modified when possible (see description of TObj_DeletingMode enumeration for more details) Returns True if deletion was successful. Checks if object can be deleted. Should be redefined for each specific kind of object", py::arg("theMode"));
	cls_TObj_Object.def_static("Detach_", [](const TDF_Label & a0) -> Standard_Boolean { return TObj_Object::Detach(a0); }, py::arg("theLabel"));
	cls_TObj_Object.def_static("Detach_", (Standard_Boolean (*)(const TDF_Label &, const TObj_DeletingMode)) &TObj_Object::Detach, "Deletes the object from the label. Checks if object can be deleted. Finds object on the label and detaches it by calling previos method. Returns true if there is no object on the label after detaching", py::arg("theLabel"), py::arg("theMode"));
	cls_TObj_Object.def_static("GetObj_", [](const TDF_Label & a0, opencascade::handle<TObj_Object> & a1) -> Standard_Boolean { return TObj_Object::GetObj(a0, a1); }, py::arg("theLabel"), py::arg("theResult"));
	cls_TObj_Object.def_static("GetObj_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TObj_Object> &, const Standard_Boolean)) &TObj_Object::GetObj, "Returns the Object attached to a given label. Returns False if no object of type TObj_Object is stored on the specified label. If isSuper is true tries to find on the super labels.", py::arg("theLabel"), py::arg("theResult"), py::arg("isSuper"));
	cls_TObj_Object.def("GetFatherObject", [](TObj_Object &self) -> opencascade::handle<TObj_Object> { return self.GetFatherObject(); });
	cls_TObj_Object.def("GetFatherObject", (opencascade::handle<TObj_Object> (TObj_Object::*)(const opencascade::handle<Standard_Type> &) const ) &TObj_Object::GetFatherObject, "Returns the father object, which may be NULL theType gives type of father object to search", py::arg("theType"));
	cls_TObj_Object.def("IsAlive", (Standard_Boolean (TObj_Object::*)() const ) &TObj_Object::IsAlive, "Checks that object alive in model Default implementation checks that object has TObject attribute at own label.");
	cls_TObj_Object.def("Clone", [](TObj_Object &self, const TDF_Label & a0) -> opencascade::handle<TObj_Object> { return self.Clone(a0); }, py::arg("theTargetLabel"));
	cls_TObj_Object.def("Clone", (opencascade::handle<TObj_Object> (TObj_Object::*)(const TDF_Label &, opencascade::handle<TDF_RelocationTable>)) &TObj_Object::Clone, "Copy me to other label theTargetLabel New object will not have all the reference that has me. Coping object with data and childs, but change name by adding string '_copy' As result return handle of new object (null handle is something wrong) NOTE: BackReferences not coping. After clonning all objects it is neccessary to call copy references with the same relocation table", py::arg("theTargetLabel"), py::arg("theRelocTable"));
	cls_TObj_Object.def("CopyReferences", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &, const opencascade::handle<TDF_RelocationTable> &)) &TObj_Object::CopyReferences, "Coping the references. return Standard_False is Target object is different type", py::arg("theTargetObject"), py::arg("theRelocTable"));
	cls_TObj_Object.def("CopyChildren", (void (TObj_Object::*)(TDF_Label &, const opencascade::handle<TDF_RelocationTable> &)) &TObj_Object::CopyChildren, "Coping the children from source label to the target.", py::arg("theTargetLabel"), py::arg("theRelocTable"));
	cls_TObj_Object.def("GetOrder", (Standard_Integer (TObj_Object::*)() const ) &TObj_Object::GetOrder, "returns order of object (or tag of their label if order is not initialised)");
	cls_TObj_Object.def("SetOrder", (Standard_Boolean (TObj_Object::*)(const Standard_Integer &)) &TObj_Object::SetOrder, "sets order of object", py::arg("theIndx"));
	cls_TObj_Object.def("GetTypeFlags", (Standard_Integer (TObj_Object::*)() const ) &TObj_Object::GetTypeFlags, "Returns flags (bitmask) that define properties of objects of that type By default returns flag Visible");
	cls_TObj_Object.def("GetFlags", (Standard_Integer (TObj_Object::*)() const ) &TObj_Object::GetFlags, "Returns mask of seted flags");
	cls_TObj_Object.def("SetFlags", (void (TObj_Object::*)(const Standard_Integer)) &TObj_Object::SetFlags, "Sets flags with defined mask.", py::arg("theMask"));
	cls_TObj_Object.def("TestFlags", (Standard_Boolean (TObj_Object::*)(const Standard_Integer) const ) &TObj_Object::TestFlags, "tests flags by the mask.", py::arg("theMask"));
	cls_TObj_Object.def("ClearFlags", [](TObj_Object &self) -> void { return self.ClearFlags(); });
	cls_TObj_Object.def("ClearFlags", (void (TObj_Object::*)(const Standard_Integer)) &TObj_Object::ClearFlags, "clears flags by the mask.", py::arg("theMask"));
	cls_TObj_Object.def("AfterRetrieval", (void (TObj_Object::*)()) &TObj_Object::AfterRetrieval, "Preforms updating the links and dependances of the object which are not stored in persistence. Should be redefined if necessary.");
	cls_TObj_Object.def("BeforeStoring", (void (TObj_Object::*)()) &TObj_Object::BeforeStoring, "Preforms storing the objects transient fields in OCAF document which were outside transaction mechanism. Default implementation doesnot nothing");
	cls_TObj_Object.def_static("get_type_name_", (const char * (*)()) &TObj_Object::get_type_name, "None");
	cls_TObj_Object.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_Object::get_type_descriptor, "None");
	cls_TObj_Object.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_Object::*)() const ) &TObj_Object::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TObj_SequenceOfObject, std::unique_ptr<TObj_SequenceOfObject, Deleter<TObj_SequenceOfObject>>, NCollection_BaseSequence> cls_TObj_SequenceOfObject(mod, "TObj_SequenceOfObject", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TObj_SequenceOfObject.def(py::init<>());
	cls_TObj_SequenceOfObject.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TObj_SequenceOfObject.def(py::init([] (const TObj_SequenceOfObject &other) {return new TObj_SequenceOfObject(other);}), "Copy constructor", py::arg("other"));
	cls_TObj_SequenceOfObject.def("begin", (TObj_SequenceOfObject::iterator (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TObj_SequenceOfObject.def("end", (TObj_SequenceOfObject::iterator (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TObj_SequenceOfObject.def("cbegin", (TObj_SequenceOfObject::const_iterator (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TObj_SequenceOfObject.def("cend", (TObj_SequenceOfObject::const_iterator (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TObj_SequenceOfObject.def("Size", (Standard_Integer (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::Size, "Number of items");
	cls_TObj_SequenceOfObject.def("Length", (Standard_Integer (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::Length, "Number of items");
	cls_TObj_SequenceOfObject.def("Lower", (Standard_Integer (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::Lower, "Method for consistency with other collections.");
	cls_TObj_SequenceOfObject.def("Upper", (Standard_Integer (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::Upper, "Method for consistency with other collections.");
	cls_TObj_SequenceOfObject.def("IsEmpty", (Standard_Boolean (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::IsEmpty, "Empty query");
	cls_TObj_SequenceOfObject.def("Reverse", (void (TObj_SequenceOfObject::*)()) &TObj_SequenceOfObject::Reverse, "Reverse sequence");
	cls_TObj_SequenceOfObject.def("Exchange", (void (TObj_SequenceOfObject::*)(const Standard_Integer, const Standard_Integer)) &TObj_SequenceOfObject::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TObj_SequenceOfObject.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TObj_SequenceOfObject::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TObj_SequenceOfObject.def("Clear", [](TObj_SequenceOfObject &self) -> void { return self.Clear(); });
	cls_TObj_SequenceOfObject.def("Clear", (void (TObj_SequenceOfObject::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TObj_SequenceOfObject::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TObj_SequenceOfObject.def("Assign", (TObj_SequenceOfObject & (TObj_SequenceOfObject::*)(const TObj_SequenceOfObject &)) &TObj_SequenceOfObject::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TObj_SequenceOfObject.def("assign", (TObj_SequenceOfObject & (TObj_SequenceOfObject::*)(const TObj_SequenceOfObject &)) &TObj_SequenceOfObject::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TObj_SequenceOfObject.def("Remove", (void (TObj_SequenceOfObject::*)(TObj_SequenceOfObject::Iterator &)) &TObj_SequenceOfObject::Remove, "Remove one item", py::arg("thePosition"));
	cls_TObj_SequenceOfObject.def("Remove", (void (TObj_SequenceOfObject::*)(const Standard_Integer)) &TObj_SequenceOfObject::Remove, "Remove one item", py::arg("theIndex"));
	cls_TObj_SequenceOfObject.def("Remove", (void (TObj_SequenceOfObject::*)(const Standard_Integer, const Standard_Integer)) &TObj_SequenceOfObject::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TObj_SequenceOfObject.def("Append", (void (TObj_SequenceOfObject::*)(const opencascade::handle<TObj_Object> &)) &TObj_SequenceOfObject::Append, "Append one item", py::arg("theItem"));
	cls_TObj_SequenceOfObject.def("Append", (void (TObj_SequenceOfObject::*)(TObj_SequenceOfObject &)) &TObj_SequenceOfObject::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TObj_SequenceOfObject.def("Prepend", (void (TObj_SequenceOfObject::*)(const opencascade::handle<TObj_Object> &)) &TObj_SequenceOfObject::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TObj_SequenceOfObject.def("Prepend", (void (TObj_SequenceOfObject::*)(TObj_SequenceOfObject &)) &TObj_SequenceOfObject::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TObj_SequenceOfObject.def("InsertBefore", (void (TObj_SequenceOfObject::*)(const Standard_Integer, const opencascade::handle<TObj_Object> &)) &TObj_SequenceOfObject::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TObj_SequenceOfObject.def("InsertBefore", (void (TObj_SequenceOfObject::*)(const Standard_Integer, TObj_SequenceOfObject &)) &TObj_SequenceOfObject::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TObj_SequenceOfObject.def("InsertAfter", (void (TObj_SequenceOfObject::*)(TObj_SequenceOfObject::Iterator &, const opencascade::handle<TObj_Object> &)) &TObj_SequenceOfObject::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TObj_SequenceOfObject.def("InsertAfter", (void (TObj_SequenceOfObject::*)(const Standard_Integer, TObj_SequenceOfObject &)) &TObj_SequenceOfObject::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TObj_SequenceOfObject.def("InsertAfter", (void (TObj_SequenceOfObject::*)(const Standard_Integer, const opencascade::handle<TObj_Object> &)) &TObj_SequenceOfObject::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TObj_SequenceOfObject.def("Split", (void (TObj_SequenceOfObject::*)(const Standard_Integer, TObj_SequenceOfObject &)) &TObj_SequenceOfObject::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TObj_SequenceOfObject.def("First", (const opencascade::handle<TObj_Object> & (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::First, "First item access");
	cls_TObj_SequenceOfObject.def("ChangeFirst", (opencascade::handle<TObj_Object> & (TObj_SequenceOfObject::*)()) &TObj_SequenceOfObject::ChangeFirst, "First item access");
	cls_TObj_SequenceOfObject.def("Last", (const opencascade::handle<TObj_Object> & (TObj_SequenceOfObject::*)() const ) &TObj_SequenceOfObject::Last, "Last item access");
	cls_TObj_SequenceOfObject.def("ChangeLast", (opencascade::handle<TObj_Object> & (TObj_SequenceOfObject::*)()) &TObj_SequenceOfObject::ChangeLast, "Last item access");
	cls_TObj_SequenceOfObject.def("Value", (const opencascade::handle<TObj_Object> & (TObj_SequenceOfObject::*)(const Standard_Integer) const ) &TObj_SequenceOfObject::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TObj_SequenceOfObject.def("__call__", (const opencascade::handle<TObj_Object> & (TObj_SequenceOfObject::*)(const Standard_Integer) const ) &TObj_SequenceOfObject::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TObj_SequenceOfObject.def("ChangeValue", (opencascade::handle<TObj_Object> & (TObj_SequenceOfObject::*)(const Standard_Integer)) &TObj_SequenceOfObject::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TObj_SequenceOfObject.def("__call__", (opencascade::handle<TObj_Object> & (TObj_SequenceOfObject::*)(const Standard_Integer)) &TObj_SequenceOfObject::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TObj_SequenceOfObject.def("SetValue", (void (TObj_SequenceOfObject::*)(const Standard_Integer, const opencascade::handle<TObj_Object> &)) &TObj_SequenceOfObject::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TObj_SequenceOfObject.def("__iter__", [](const TObj_SequenceOfObject &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_Persistence.hxx
	py::class_<TObj_Persistence, std::unique_ptr<TObj_Persistence, py::nodelete>> cls_TObj_Persistence(mod, "TObj_Persistence", "This class is intended to be a root of tools (one per class) to manage persistence of objects inherited from TObj_Object It provides a mechanism to recover correctly typed objects (subtypes of TObj_Object) out of their persistent names");
	cls_TObj_Persistence.def_static("CreateNewObject_", (opencascade::handle<TObj_Object> (*)(const Standard_CString, const TDF_Label &)) &TObj_Persistence::CreateNewObject, "Creates and returns a new object of the registered type If the type is not registered, returns Null handle", py::arg("theType"), py::arg("theLabel"));
	cls_TObj_Persistence.def_static("DumpTypes_", (void (*)(Standard_OStream &)) &TObj_Persistence::DumpTypes, "Dumps names of all the types registered for persistence to the specified stream", py::arg("theOs"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_ObjectIterator.hxx
	py::class_<TObj_ObjectIterator, opencascade::handle<TObj_ObjectIterator>, Standard_Transient> cls_TObj_ObjectIterator(mod, "TObj_ObjectIterator", "This class provides an iterator by objects in a partition. (implements TObj_ObjectIterator interface)");
	cls_TObj_ObjectIterator.def("More", (Standard_Boolean (TObj_ObjectIterator::*)() const ) &TObj_ObjectIterator::More, "Returns True if iteration is not finished and method Current() will give the object. Default implementation returns False");
	cls_TObj_ObjectIterator.def("Next", (void (TObj_ObjectIterator::*)()) &TObj_ObjectIterator::Next, "Iterates to the next object Default implementation does nothing");
	cls_TObj_ObjectIterator.def("Value", (opencascade::handle<TObj_Object> (TObj_ObjectIterator::*)() const ) &TObj_ObjectIterator::Value, "Returns current object (or null if iteration has finished) Default implementation returns null handle");
	cls_TObj_ObjectIterator.def_static("get_type_name_", (const char * (*)()) &TObj_ObjectIterator::get_type_name, "None");
	cls_TObj_ObjectIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_ObjectIterator::get_type_descriptor, "None");
	cls_TObj_ObjectIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_ObjectIterator::*)() const ) &TObj_ObjectIterator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_TNameContainer.hxx
	py::class_<TObj_TNameContainer, opencascade::handle<TObj_TNameContainer>, TDF_Attribute> cls_TObj_TNameContainer(mod, "TObj_TNameContainer", "This class provides OCAF Attribute to storing the unique names of object in model.");
	cls_TObj_TNameContainer.def(py::init<>());
	cls_TObj_TNameContainer.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TNameContainer::GetID, "This method is used in implementation of ID()");
	cls_TObj_TNameContainer.def("ID", (const Standard_GUID & (TObj_TNameContainer::*)() const ) &TObj_TNameContainer::ID, "Returns the ID of TObj_TNameContainer attribute.");
	cls_TObj_TNameContainer.def_static("Set_", (opencascade::handle<TObj_TNameContainer> (*)(const TDF_Label &)) &TObj_TNameContainer::Set, "Creates TObj_DataMapOfNameLabel attribute on given label if not exist", py::arg("theLabel"));
	cls_TObj_TNameContainer.def("RecordName", (void (TObj_TNameContainer::*)(const opencascade::handle<TCollection_HExtendedString> &, const TDF_Label &)) &TObj_TNameContainer::RecordName, "Records name with label attached", py::arg("theName"), py::arg("theLabel"));
	cls_TObj_TNameContainer.def("RemoveName", (void (TObj_TNameContainer::*)(const opencascade::handle<TCollection_HExtendedString> &)) &TObj_TNameContainer::RemoveName, "Remove name from the map", py::arg("theName"));
	cls_TObj_TNameContainer.def("IsRegistered", (Standard_Boolean (TObj_TNameContainer::*)(const opencascade::handle<TCollection_HExtendedString> &) const ) &TObj_TNameContainer::IsRegistered, "Return True is theName is registered in the Map", py::arg("theName"));
	cls_TObj_TNameContainer.def("Clear", (void (TObj_TNameContainer::*)()) &TObj_TNameContainer::Clear, "Remove all names registered in container");
	cls_TObj_TNameContainer.def("Set", (void (TObj_TNameContainer::*)(const TObj_DataMapOfNameLabel &)) &TObj_TNameContainer::Set, "Sets the TObj_DataMapOfNameLabel object", py::arg("theElem"));
	cls_TObj_TNameContainer.def("Get", (const TObj_DataMapOfNameLabel & (TObj_TNameContainer::*)() const ) &TObj_TNameContainer::Get, "Returns the TObj_DataMapOfNameLabel object");
	cls_TObj_TNameContainer.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TNameContainer::*)() const ) &TObj_TNameContainer::NewEmpty, "Returns an new empty TObj_TNameContainer attribute. It is used by the copy algorithm.");
	cls_TObj_TNameContainer.def("Restore", (void (TObj_TNameContainer::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TNameContainer::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
	cls_TObj_TNameContainer.def("Paste", (void (TObj_TNameContainer::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TObj_TNameContainer::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
	cls_TObj_TNameContainer.def_static("get_type_name_", (const char * (*)()) &TObj_TNameContainer::get_type_name, "None");
	cls_TObj_TNameContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TNameContainer::get_type_descriptor, "None");
	cls_TObj_TNameContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TNameContainer::*)() const ) &TObj_TNameContainer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_Partition.hxx
	py::class_<TObj_Partition, opencascade::handle<TObj_Partition>, TObj_Object> cls_TObj_Partition(mod, "TObj_Partition", "This class privides tool handling one of partitions (the set of homogenious elements) in the OCAF based model`s data structure");
	cls_TObj_Partition.def_static("Create_", (opencascade::handle<TObj_Partition> (*)(const TDF_Label &)) &TObj_Partition::Create, "Creates a new partition on given label.", py::arg("theLabel"));
	cls_TObj_Partition.def("SetName", (Standard_Boolean (TObj_Partition::*)(const opencascade::handle<TCollection_HExtendedString> &) const ) &TObj_Partition::SetName, "Sets name of the object. partition does not check unique of own name", py::arg("theName"));
	cls_TObj_Partition.def("AfterRetrieval", (void (TObj_Partition::*)()) &TObj_Partition::AfterRetrieval, "Preforms updating the links and dependances of the object which are not stored in persistence. Does not register the partition name");
	cls_TObj_Partition.def("NewLabel", (TDF_Label (TObj_Partition::*)() const ) &TObj_Partition::NewLabel, "Creates and Returns label for new object in partition.");
	cls_TObj_Partition.def("SetNamePrefix", (void (TObj_Partition::*)(const opencascade::handle<TCollection_HExtendedString> &)) &TObj_Partition::SetNamePrefix, "Sets prefix for names of the objects in partition.", py::arg("thePrefix"));
	cls_TObj_Partition.def("GetNamePrefix", (opencascade::handle<TCollection_HExtendedString> (TObj_Partition::*)() const ) &TObj_Partition::GetNamePrefix, "Returns prefix for names of the objects in partition.");
	cls_TObj_Partition.def("GetNewName", [](TObj_Partition &self) -> opencascade::handle<TCollection_HExtendedString> { return self.GetNewName(); });
	cls_TObj_Partition.def("GetNewName", (opencascade::handle<TCollection_HExtendedString> (TObj_Partition::*)(const Standard_Boolean)) &TObj_Partition::GetNewName, "Generates and returns name for new object in partition. if theIsToChangeCount is true partition icrease own counter to generate new name next time starting from new counter value", py::arg("theIsToChangeCount"));
	cls_TObj_Partition.def("GetLastIndex", (Standard_Integer (TObj_Partition::*)() const ) &TObj_Partition::GetLastIndex, "Return Last index in partition (reserved);");
	cls_TObj_Partition.def("SetLastIndex", (void (TObj_Partition::*)(const Standard_Integer)) &TObj_Partition::SetLastIndex, "Sets Last index in partition (reserved);", py::arg("theIndex"));
	cls_TObj_Partition.def_static("GetPartition_", (opencascade::handle<TObj_Partition> (*)(const opencascade::handle<TObj_Object> &)) &TObj_Partition::GetPartition, "Returns the partition in which object is stored. Null partition returned if not found", py::arg("theObject"));
	cls_TObj_Partition.def("Update", (Standard_Boolean (TObj_Partition::*)()) &TObj_Partition::Update, "Does nothing in the partition.");
	cls_TObj_Partition.def_static("get_type_name_", (const char * (*)()) &TObj_Partition::get_type_name, "None");
	cls_TObj_Partition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_Partition::get_type_descriptor, "None");
	cls_TObj_Partition.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_Partition::*)() const ) &TObj_Partition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_CheckModel.hxx
	py::class_<TObj_CheckModel, opencascade::handle<TObj_CheckModel>, Message_Algorithm> cls_TObj_CheckModel(mod, "TObj_CheckModel", "This class provides consistency check of the TObj model. It collects all inconsistencies in the status bits and prepaires messages to be sent using SendStatusMessages (SendMessages) method. It supports also the fix mode, in which some inconsistencies are corrected.");
	cls_TObj_CheckModel.def(py::init<const opencascade::handle<TObj_Model> &>(), py::arg("theModel"));
	cls_TObj_CheckModel.def("SetToFix", (void (TObj_CheckModel::*)(const Standard_Boolean)) &TObj_CheckModel::SetToFix, "Sets flag allowing fixing inconsistencies", py::arg("theToFix"));
	cls_TObj_CheckModel.def("IsToFix", (Standard_Boolean (TObj_CheckModel::*)() const ) &TObj_CheckModel::IsToFix, "Returns true if it is allowed to fix inconsistencies");
	cls_TObj_CheckModel.def("GetModel", (const opencascade::handle<TObj_Model> & (TObj_CheckModel::*)() const ) &TObj_CheckModel::GetModel, "Returns the checked model");
	cls_TObj_CheckModel.def("Perform", (Standard_Boolean (TObj_CheckModel::*)()) &TObj_CheckModel::Perform, "Performs all checks. Descendants should call parent method before doing own checks. This implementation checks OCAF references and back references between objects of the model. Returns true if no inconsistencies found.");
	cls_TObj_CheckModel.def_static("get_type_name_", (const char * (*)()) &TObj_CheckModel::get_type_name, "None");
	cls_TObj_CheckModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_CheckModel::get_type_descriptor, "None");
	cls_TObj_CheckModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_CheckModel::*)() const ) &TObj_CheckModel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_HiddenPartition.hxx
	py::class_<TObj_HiddenPartition, opencascade::handle<TObj_HiddenPartition>, TObj_Partition> cls_TObj_HiddenPartition(mod, "TObj_HiddenPartition", "This class is partition is predefined hidden flag");
	cls_TObj_HiddenPartition.def(py::init<const TDF_Label &>(), py::arg("theLabel"));
	cls_TObj_HiddenPartition.def("GetTypeFlags", (Standard_Integer (TObj_HiddenPartition::*)() const ) &TObj_HiddenPartition::GetTypeFlags, "Returns all flags of father except Visible");
	cls_TObj_HiddenPartition.def_static("get_type_name_", (const char * (*)()) &TObj_HiddenPartition::get_type_name, "None");
	cls_TObj_HiddenPartition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_HiddenPartition::get_type_descriptor, "None");
	cls_TObj_HiddenPartition.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_HiddenPartition::*)() const ) &TObj_HiddenPartition::DynamicType, "None");

	// Callback for TObj_LabelIterator.
	class PyCallback_TObj_LabelIterator : public TObj_LabelIterator {
	public:
		using TObj_LabelIterator::TObj_LabelIterator;

		void MakeStep() override { PYBIND11_OVERLOAD_PURE(void, TObj_LabelIterator, MakeStep, ); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_LabelIterator.hxx
	py::class_<TObj_LabelIterator, opencascade::handle<TObj_LabelIterator>, PyCallback_TObj_LabelIterator, TObj_ObjectIterator> cls_TObj_LabelIterator(mod, "TObj_LabelIterator", "This class is a basis for OCAF based iterators.");
	cls_TObj_LabelIterator.def(py::init<const TDF_Label &>(), py::arg("theLabel"));
	cls_TObj_LabelIterator.def(py::init<const TDF_Label &, const Standard_Boolean>(), py::arg("theLabel"), py::arg("isRecursive"));
	cls_TObj_LabelIterator.def("More", (Standard_Boolean (TObj_LabelIterator::*)() const ) &TObj_LabelIterator::More, "Returns True if there is a current Item in the iteration.");
	cls_TObj_LabelIterator.def("Next", (void (TObj_LabelIterator::*)()) &TObj_LabelIterator::Next, "Move to the next Item");
	cls_TObj_LabelIterator.def("Value", (opencascade::handle<TObj_Object> (TObj_LabelIterator::*)() const ) &TObj_LabelIterator::Value, "Returns the current item");
	cls_TObj_LabelIterator.def("LabelValue", (const TDF_Label & (TObj_LabelIterator::*)() const ) &TObj_LabelIterator::LabelValue, "Returns the label of the current item");
	cls_TObj_LabelIterator.def_static("get_type_name_", (const char * (*)()) &TObj_LabelIterator::get_type_name, "None");
	cls_TObj_LabelIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_LabelIterator::get_type_descriptor, "None");
	cls_TObj_LabelIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_LabelIterator::*)() const ) &TObj_LabelIterator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_ModelIterator.hxx
	py::class_<TObj_ModelIterator, opencascade::handle<TObj_ModelIterator>, TObj_ObjectIterator> cls_TObj_ModelIterator(mod, "TObj_ModelIterator", "This class provides an iterator by all objects in the model.");
	cls_TObj_ModelIterator.def(py::init<const opencascade::handle<TObj_Model> &>(), py::arg("theModel"));
	cls_TObj_ModelIterator.def("More", (Standard_Boolean (TObj_ModelIterator::*)() const ) &TObj_ModelIterator::More, "Returns True if iteration is not finished and method Value() will give the object");
	cls_TObj_ModelIterator.def("Next", (void (TObj_ModelIterator::*)()) &TObj_ModelIterator::Next, "Iterates to the next object");
	cls_TObj_ModelIterator.def("Value", (opencascade::handle<TObj_Object> (TObj_ModelIterator::*)() const ) &TObj_ModelIterator::Value, "Returns current object (or MainObj of Model if iteration has finished)");
	cls_TObj_ModelIterator.def_static("get_type_name_", (const char * (*)()) &TObj_ModelIterator::get_type_name, "None");
	cls_TObj_ModelIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_ModelIterator::get_type_descriptor, "None");
	cls_TObj_ModelIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_ModelIterator::*)() const ) &TObj_ModelIterator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_OcafObjectIterator.hxx
	py::class_<TObj_OcafObjectIterator, opencascade::handle<TObj_OcafObjectIterator>, TObj_LabelIterator> cls_TObj_OcafObjectIterator(mod, "TObj_OcafObjectIterator", "This class provides an iterator by objects in a partition. (implements TObj_ObjectIterator interface)");
	cls_TObj_OcafObjectIterator.def(py::init<const TDF_Label &>(), py::arg("theLabel"));
	cls_TObj_OcafObjectIterator.def(py::init<const TDF_Label &, const opencascade::handle<Standard_Type> &>(), py::arg("theLabel"), py::arg("theType"));
	cls_TObj_OcafObjectIterator.def(py::init<const TDF_Label &, const opencascade::handle<Standard_Type> &, const Standard_Boolean>(), py::arg("theLabel"), py::arg("theType"), py::arg("theRecursive"));
	cls_TObj_OcafObjectIterator.def_static("get_type_name_", (const char * (*)()) &TObj_OcafObjectIterator::get_type_name, "None");
	cls_TObj_OcafObjectIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_OcafObjectIterator::get_type_descriptor, "None");
	cls_TObj_OcafObjectIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_OcafObjectIterator::*)() const ) &TObj_OcafObjectIterator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_ReferenceIterator.hxx
	py::class_<TObj_ReferenceIterator, opencascade::handle<TObj_ReferenceIterator>, TObj_LabelIterator> cls_TObj_ReferenceIterator(mod, "TObj_ReferenceIterator", "This class provides an iterator by references of the object (implements TObj_ReferenceIterator interface)");
	cls_TObj_ReferenceIterator.def(py::init<const TDF_Label &>(), py::arg("theLabel"));
	cls_TObj_ReferenceIterator.def(py::init<const TDF_Label &, const opencascade::handle<Standard_Type> &>(), py::arg("theLabel"), py::arg("theType"));
	cls_TObj_ReferenceIterator.def(py::init<const TDF_Label &, const opencascade::handle<Standard_Type> &, const Standard_Boolean>(), py::arg("theLabel"), py::arg("theType"), py::arg("theRecursive"));
	cls_TObj_ReferenceIterator.def_static("get_type_name_", (const char * (*)()) &TObj_ReferenceIterator::get_type_name, "None");
	cls_TObj_ReferenceIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_ReferenceIterator::get_type_descriptor, "None");
	cls_TObj_ReferenceIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_ReferenceIterator::*)() const ) &TObj_ReferenceIterator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_SequenceIterator.hxx
	py::class_<TObj_SequenceIterator, opencascade::handle<TObj_SequenceIterator>, TObj_ObjectIterator> cls_TObj_SequenceIterator(mod, "TObj_SequenceIterator", "This class is an iterator on sequence");
	cls_TObj_SequenceIterator.def(py::init<const opencascade::handle<TObj_HSequenceOfObject> &>(), py::arg("theObjects"));
	cls_TObj_SequenceIterator.def(py::init<const opencascade::handle<TObj_HSequenceOfObject> &, const opencascade::handle<Standard_Type> &>(), py::arg("theObjects"), py::arg("theType"));
	cls_TObj_SequenceIterator.def("More", (Standard_Boolean (TObj_SequenceIterator::*)() const ) &TObj_SequenceIterator::More, "Returns True if there is a current Item in the iteration.");
	cls_TObj_SequenceIterator.def("Next", (void (TObj_SequenceIterator::*)()) &TObj_SequenceIterator::Next, "Move to the next Item");
	cls_TObj_SequenceIterator.def("Value", (opencascade::handle<TObj_Object> (TObj_SequenceIterator::*)() const ) &TObj_SequenceIterator::Value, "Returns the current item");
	cls_TObj_SequenceIterator.def_static("get_type_name_", (const char * (*)()) &TObj_SequenceIterator::get_type_name, "None");
	cls_TObj_SequenceIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_SequenceIterator::get_type_descriptor, "None");
	cls_TObj_SequenceIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_SequenceIterator::*)() const ) &TObj_SequenceIterator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_TIntSparseArray.hxx
	py::class_<TObj_TIntSparseArray, opencascade::handle<TObj_TIntSparseArray>, TDF_Attribute> cls_TObj_TIntSparseArray(mod, "TObj_TIntSparseArray", "OCAF Attribute to store a set of positive integer values in the OCAF tree. Each value is identified by ID (positive integer). The supporting underlying data structure is NCollection_SparseArray of integers.");
	cls_TObj_TIntSparseArray.def(py::init<>());
	cls_TObj_TIntSparseArray.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TIntSparseArray::GetID, "This method is used in implementation of ID()");
	cls_TObj_TIntSparseArray.def("ID", (const Standard_GUID & (TObj_TIntSparseArray::*)() const ) &TObj_TIntSparseArray::ID, "Returns the ID of this attribute.");
	cls_TObj_TIntSparseArray.def_static("Set_", (opencascade::handle<TObj_TIntSparseArray> (*)(const TDF_Label &)) &TObj_TIntSparseArray::Set, "Creates TObj_TIntSparseArray attribute on given label.", py::arg("theLabel"));
	cls_TObj_TIntSparseArray.def("Size", (Standard_Size (TObj_TIntSparseArray::*)() const ) &TObj_TIntSparseArray::Size, "Returns the number of stored values in the set");
	cls_TObj_TIntSparseArray.def("GetIterator", (TObj_TIntSparseArray::Iterator (TObj_TIntSparseArray::*)() const ) &TObj_TIntSparseArray::GetIterator, "Returns iterator on objects contained in the set");
	cls_TObj_TIntSparseArray.def("HasValue", (Standard_Boolean (TObj_TIntSparseArray::*)(const Standard_Size) const ) &TObj_TIntSparseArray::HasValue, "Returns true if the value with the given ID is present.", py::arg("theId"));
	cls_TObj_TIntSparseArray.def("Value", (Standard_Integer (TObj_TIntSparseArray::*)(const Standard_Size) const ) &TObj_TIntSparseArray::Value, "Returns the value by its ID. Raises an exception if no value is stored with this ID", py::arg("theId"));
	cls_TObj_TIntSparseArray.def("SetValue", (void (TObj_TIntSparseArray::*)(const Standard_Size, const Standard_Integer)) &TObj_TIntSparseArray::SetValue, "Sets the value with the given ID. Raises an exception if theId is not positive", py::arg("theId"), py::arg("theValue"));
	cls_TObj_TIntSparseArray.def("UnsetValue", (void (TObj_TIntSparseArray::*)(const Standard_Size)) &TObj_TIntSparseArray::UnsetValue, "Unsets the value with the given ID. Raises an exception if theId is not positive", py::arg("theId"));
	cls_TObj_TIntSparseArray.def("Clear", (void (TObj_TIntSparseArray::*)()) &TObj_TIntSparseArray::Clear, "Clears the set");
	cls_TObj_TIntSparseArray.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TIntSparseArray::*)() const ) &TObj_TIntSparseArray::NewEmpty, "Returns an new empty TObj_TIntSparseArray attribute. It is used by the copy algorithm.");
	cls_TObj_TIntSparseArray.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TObj_TIntSparseArray::*)() const ) &TObj_TIntSparseArray::BackupCopy, "Moves this delta into a new other attribute.");
	cls_TObj_TIntSparseArray.def("Restore", (void (TObj_TIntSparseArray::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TIntSparseArray::Restore, "Restores the set using info saved in backup attribute theDelta.", py::arg("theDelta"));
	cls_TObj_TIntSparseArray.def("Paste", (void (TObj_TIntSparseArray::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TObj_TIntSparseArray::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
	cls_TObj_TIntSparseArray.def("BeforeCommitTransaction", (void (TObj_TIntSparseArray::*)()) &TObj_TIntSparseArray::BeforeCommitTransaction, "It is called just before Commit or Abort transaction and does Backup() to create a delta");
	cls_TObj_TIntSparseArray.def("DeltaOnModification", (void (TObj_TIntSparseArray::*)(const opencascade::handle<TDF_DeltaOnModification> &)) &TObj_TIntSparseArray::DeltaOnModification, "Applies theDelta to this.", py::arg("theDelta"));
	cls_TObj_TIntSparseArray.def("AfterUndo", (Standard_Boolean (TObj_TIntSparseArray::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TObj_TIntSparseArray::AfterUndo, "Clears my modification delta; called after application of theDelta", py::arg("theDelta"), py::arg("toForce"));
	cls_TObj_TIntSparseArray.def("SetDoBackup", (void (TObj_TIntSparseArray::*)(const Standard_Boolean)) &TObj_TIntSparseArray::SetDoBackup, "Sets the flag pointing to the necessity to maintain a modification delta. It is called by the retrieval driver", py::arg("toDo"));
	cls_TObj_TIntSparseArray.def("ClearDelta", (void (TObj_TIntSparseArray::*)()) &TObj_TIntSparseArray::ClearDelta, "None");
	cls_TObj_TIntSparseArray.def_static("get_type_name_", (const char * (*)()) &TObj_TIntSparseArray::get_type_name, "None");
	cls_TObj_TIntSparseArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TIntSparseArray::get_type_descriptor, "None");
	cls_TObj_TIntSparseArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TIntSparseArray::*)() const ) &TObj_TIntSparseArray::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_TModel.hxx
	py::class_<TObj_TModel, opencascade::handle<TObj_TModel>, TDF_Attribute> cls_TObj_TModel(mod, "TObj_TModel", "Attribute to store OCAF-based models in OCAF tree The persistency mechanism of the TObj_TModel allowes to save and restore various types of models without recompilation of the schema");
	cls_TObj_TModel.def(py::init<>());
	cls_TObj_TModel.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TModel::GetID, "This method is used in implementation of ID()");
	cls_TObj_TModel.def("ID", (const Standard_GUID & (TObj_TModel::*)() const ) &TObj_TModel::ID, "Returns the ID of TObj_TModel attribute.");
	cls_TObj_TModel.def("Set", (void (TObj_TModel::*)(const opencascade::handle<TObj_Model> &)) &TObj_TModel::Set, "Sets the the Model object", py::arg("theModel"));
	cls_TObj_TModel.def("Model", (opencascade::handle<TObj_Model> (TObj_TModel::*)() const ) &TObj_TModel::Model, "Returns the Model object");
	cls_TObj_TModel.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TModel::*)() const ) &TObj_TModel::NewEmpty, "Returns an new empty TObj_TModel attribute. It is used by the copy algorithm.");
	cls_TObj_TModel.def("Restore", (void (TObj_TModel::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TModel::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
	cls_TObj_TModel.def("Paste", (void (TObj_TModel::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TObj_TModel::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
	cls_TObj_TModel.def_static("get_type_name_", (const char * (*)()) &TObj_TModel::get_type_name, "None");
	cls_TObj_TModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TModel::get_type_descriptor, "None");
	cls_TObj_TModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TModel::*)() const ) &TObj_TModel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_TObject.hxx
	py::class_<TObj_TObject, opencascade::handle<TObj_TObject>, TDF_Attribute> cls_TObj_TObject(mod, "TObj_TObject", "Purpose: OCAF Attribute to storing objects (interfaces) of OCAF-based modelers in the OCAF tree. The persistency mechanism of the TObj_TObject allowes to save and restore objects of various subtypes without recompilation of the schema");
	cls_TObj_TObject.def(py::init<>());
	cls_TObj_TObject.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TObject::GetID, "This method is used in implementation of ID()");
	cls_TObj_TObject.def("ID", (const Standard_GUID & (TObj_TObject::*)() const ) &TObj_TObject::ID, "Returns the ID of TObj_TObject attribute.");
	cls_TObj_TObject.def_static("Set_", (opencascade::handle<TObj_TObject> (*)(const TDF_Label &, const opencascade::handle<TObj_Object> &)) &TObj_TObject::Set, "Creates TObj_TObject attribute on given label", py::arg("theLabel"), py::arg("theElem"));
	cls_TObj_TObject.def("Set", (void (TObj_TObject::*)(const opencascade::handle<TObj_Object> &)) &TObj_TObject::Set, "Sets the TObj_Object object", py::arg("theElem"));
	cls_TObj_TObject.def("Get", (opencascade::handle<TObj_Object> (TObj_TObject::*)() const ) &TObj_TObject::Get, "Returns the TObj_Object object");
	cls_TObj_TObject.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TObject::*)() const ) &TObj_TObject::NewEmpty, "Returns an new empty TObj_TObject attribute. It is used by the copy algorithm.");
	cls_TObj_TObject.def("Restore", (void (TObj_TObject::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TObject::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
	cls_TObj_TObject.def("Paste", (void (TObj_TObject::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TObj_TObject::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
	cls_TObj_TObject.def("BeforeForget", (void (TObj_TObject::*)()) &TObj_TObject::BeforeForget, "Tell TObj_Object to die, i.e. (myElem->IsAlive() == false) after that");
	cls_TObj_TObject.def("AfterUndo", (Standard_Boolean (TObj_TObject::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TObj_TObject::AfterUndo, "Tell TObj_Object to rise from the dead, i.e. (myElem->IsAlive() == true) after that", py::arg("anAttDelta"), py::arg("forceIt"));
	cls_TObj_TObject.def_static("get_type_name_", (const char * (*)()) &TObj_TObject::get_type_name, "None");
	cls_TObj_TObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TObject::get_type_descriptor, "None");
	cls_TObj_TObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TObject::*)() const ) &TObj_TObject::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_TReference.hxx
	py::class_<TObj_TReference, opencascade::handle<TObj_TReference>, TDF_Attribute> cls_TObj_TReference(mod, "TObj_TReference", "Attribute for storing references to the objects which implement TObj_Object interface in the OCAF tree. Its persistency mechanism provides transparent method for storing cross-model references. Each reference, when created, registers itself in the referred object, to support back references");
	cls_TObj_TReference.def(py::init<>());
	cls_TObj_TReference.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TReference::GetID, "This method is used in implementation of ID()");
	cls_TObj_TReference.def("ID", (const Standard_GUID & (TObj_TReference::*)() const ) &TObj_TReference::ID, "Returns the ID of TObj_TReference attribute.");
	cls_TObj_TReference.def_static("Set_", (opencascade::handle<TObj_TReference> (*)(const TDF_Label &, const opencascade::handle<TObj_Object> &, const opencascade::handle<TObj_Object> &)) &TObj_TReference::Set, "Creates reference on TDF_Label <theLabel> to the object <theObject> and creates backreference from the object <theObject> to <theMaster> one.", py::arg("theLabel"), py::arg("theObject"), py::arg("theMaster"));
	cls_TObj_TReference.def("Set", (void (TObj_TReference::*)(const opencascade::handle<TObj_Object> &, const TDF_Label &)) &TObj_TReference::Set, "Sets the reference to the theObject", py::arg("theObject"), py::arg("theMasterLabel"));
	cls_TObj_TReference.def("Set", (void (TObj_TReference::*)(const TDF_Label &, const TDF_Label &)) &TObj_TReference::Set, "Sets the reference to the theObject at indicated Label. It is method for persistent only. Don`t use anywhere else.", py::arg("theLabel"), py::arg("theMasterLabel"));
	cls_TObj_TReference.def("Get", (opencascade::handle<TObj_Object> (TObj_TReference::*)() const ) &TObj_TReference::Get, "Returns the referenced theObject");
	cls_TObj_TReference.def("GetMasterLabel", (TDF_Label (TObj_TReference::*)() const ) &TObj_TReference::GetMasterLabel, "Returns the Label of master object.");
	cls_TObj_TReference.def("GetLabel", (TDF_Label (TObj_TReference::*)() const ) &TObj_TReference::GetLabel, "Returns the referred label.");
	cls_TObj_TReference.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TReference::*)() const ) &TObj_TReference::NewEmpty, "Returns an new empty TObj_TReference attribute. It is used by the copy algorithm.");
	cls_TObj_TReference.def("Restore", (void (TObj_TReference::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TReference::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
	cls_TObj_TReference.def("Paste", (void (TObj_TReference::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TObj_TReference::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
	cls_TObj_TReference.def("BeforeForget", (void (TObj_TReference::*)()) &TObj_TReference::BeforeForget, "Remove back references of it reference if it is in other document.");
	cls_TObj_TReference.def("BeforeUndo", [](TObj_TReference &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); }, py::arg("theDelta"));
	cls_TObj_TReference.def("BeforeUndo", (Standard_Boolean (TObj_TReference::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TObj_TReference::BeforeUndo, "It is necessary for tranzaction mechanism (Undo/Redo).", py::arg("theDelta"), py::arg("isForced"));
	cls_TObj_TReference.def("AfterUndo", [](TObj_TReference &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); }, py::arg("theDelta"));
	cls_TObj_TReference.def("AfterUndo", (Standard_Boolean (TObj_TReference::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TObj_TReference::AfterUndo, "It is necessary for tranzaction mechanism (Undo/Redo).", py::arg("theDelta"), py::arg("isForced"));
	cls_TObj_TReference.def("AfterResume", (void (TObj_TReference::*)()) &TObj_TReference::AfterResume, "Check if back reference exists for reference.");
	cls_TObj_TReference.def("AfterRetrieval", [](TObj_TReference &self) -> Standard_Boolean { return self.AfterRetrieval(); });
	cls_TObj_TReference.def("AfterRetrieval", (Standard_Boolean (TObj_TReference::*)(const Standard_Boolean)) &TObj_TReference::AfterRetrieval, "Called after retrieval reference from file.", py::arg("forceIt"));
	cls_TObj_TReference.def_static("get_type_name_", (const char * (*)()) &TObj_TReference::get_type_name, "None");
	cls_TObj_TReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TReference::get_type_descriptor, "None");
	cls_TObj_TReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TReference::*)() const ) &TObj_TReference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_TXYZ.hxx
	py::class_<TObj_TXYZ, opencascade::handle<TObj_TXYZ>, TDF_Attribute> cls_TObj_TXYZ(mod, "TObj_TXYZ", "None");
	cls_TObj_TXYZ.def(py::init<>());
	cls_TObj_TXYZ.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TXYZ::GetID, "This method is used in implementation of ID()");
	cls_TObj_TXYZ.def("ID", (const Standard_GUID & (TObj_TXYZ::*)() const ) &TObj_TXYZ::ID, "Returns the ID of TObj_TXYZ attribute.");
	cls_TObj_TXYZ.def_static("Set_", (opencascade::handle<TObj_TXYZ> (*)(const TDF_Label &, const gp_XYZ &)) &TObj_TXYZ::Set, "Creates attribute and sets the XYZ", py::arg("theLabel"), py::arg("theXYZ"));
	cls_TObj_TXYZ.def("Set", (void (TObj_TXYZ::*)(const gp_XYZ &)) &TObj_TXYZ::Set, "Sets the XYZ", py::arg("theXYZ"));
	cls_TObj_TXYZ.def("Get", (gp_XYZ (TObj_TXYZ::*)() const ) &TObj_TXYZ::Get, "Returns the XYZ");
	cls_TObj_TXYZ.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TXYZ::*)() const ) &TObj_TXYZ::NewEmpty, "Returns an new empty TObj_TXYZ attribute. It is used by the copy algorithm.");
	cls_TObj_TXYZ.def("Restore", (void (TObj_TXYZ::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TXYZ::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
	cls_TObj_TXYZ.def("Paste", (void (TObj_TXYZ::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TObj_TXYZ::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
	// FIXME cls_TObj_TXYZ.def("Dump", (Standard_OStream & (TObj_TXYZ::*)(Standard_OStream &) const ) &TObj_TXYZ::Dump, "This method dumps the attribute value into the stream", py::arg("theOS"));
	cls_TObj_TXYZ.def_static("get_type_name_", (const char * (*)()) &TObj_TXYZ::get_type_name, "None");
	cls_TObj_TXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TXYZ::get_type_descriptor, "None");
	cls_TObj_TXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TXYZ::*)() const ) &TObj_TXYZ::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_DeletingMode.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TObj_SequenceOfObject.hxx
	py::class_<TObj_HSequenceOfObject, opencascade::handle<TObj_HSequenceOfObject>, TObj_SequenceOfObject, Standard_Transient> cls_TObj_HSequenceOfObject(mod, "TObj_HSequenceOfObject", "None");
	cls_TObj_HSequenceOfObject.def(py::init<>());
	cls_TObj_HSequenceOfObject.def(py::init<const TObj_SequenceOfObject &>(), py::arg("theOther"));
	cls_TObj_HSequenceOfObject.def("Sequence", (const TObj_SequenceOfObject & (TObj_HSequenceOfObject::*)() const ) &TObj_HSequenceOfObject::Sequence, "None");
	cls_TObj_HSequenceOfObject.def("Append", (void (TObj_HSequenceOfObject::*)(const TObj_SequenceOfObject::value_type &)) &TObj_HSequenceOfObject::Append, "None", py::arg("theItem"));
	cls_TObj_HSequenceOfObject.def("Append", (void (TObj_HSequenceOfObject::*)(TObj_SequenceOfObject &)) &TObj_HSequenceOfObject::Append, "None", py::arg("theSequence"));
	cls_TObj_HSequenceOfObject.def("ChangeSequence", (TObj_SequenceOfObject & (TObj_HSequenceOfObject::*)()) &TObj_HSequenceOfObject::ChangeSequence, "None");
	cls_TObj_HSequenceOfObject.def_static("get_type_name_", (const char * (*)()) &TObj_HSequenceOfObject::get_type_name, "None");
	cls_TObj_HSequenceOfObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_HSequenceOfObject::get_type_descriptor, "None");
	cls_TObj_HSequenceOfObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_HSequenceOfObject::*)() const ) &TObj_HSequenceOfObject::DynamicType, "None");

	/* FIXME
	// TObj_DataMapOfNameLabel
	*/

	/* FIXME
	// TObj_DataMapOfObjectHSequenceOcafObjects
	*/

	/* FIXME
	// TObj_DataMapOfStringPointer
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TObj_SequenceOfIterator, std::unique_ptr<TObj_SequenceOfIterator, Deleter<TObj_SequenceOfIterator>>, NCollection_BaseSequence> cls_TObj_SequenceOfIterator(mod, "TObj_SequenceOfIterator", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TObj_SequenceOfIterator.def(py::init<>());
	cls_TObj_SequenceOfIterator.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TObj_SequenceOfIterator.def(py::init([] (const TObj_SequenceOfIterator &other) {return new TObj_SequenceOfIterator(other);}), "Copy constructor", py::arg("other"));
	cls_TObj_SequenceOfIterator.def("begin", (TObj_SequenceOfIterator::iterator (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TObj_SequenceOfIterator.def("end", (TObj_SequenceOfIterator::iterator (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TObj_SequenceOfIterator.def("cbegin", (TObj_SequenceOfIterator::const_iterator (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TObj_SequenceOfIterator.def("cend", (TObj_SequenceOfIterator::const_iterator (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TObj_SequenceOfIterator.def("Size", (Standard_Integer (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::Size, "Number of items");
	cls_TObj_SequenceOfIterator.def("Length", (Standard_Integer (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::Length, "Number of items");
	cls_TObj_SequenceOfIterator.def("Lower", (Standard_Integer (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::Lower, "Method for consistency with other collections.");
	cls_TObj_SequenceOfIterator.def("Upper", (Standard_Integer (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::Upper, "Method for consistency with other collections.");
	cls_TObj_SequenceOfIterator.def("IsEmpty", (Standard_Boolean (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::IsEmpty, "Empty query");
	cls_TObj_SequenceOfIterator.def("Reverse", (void (TObj_SequenceOfIterator::*)()) &TObj_SequenceOfIterator::Reverse, "Reverse sequence");
	cls_TObj_SequenceOfIterator.def("Exchange", (void (TObj_SequenceOfIterator::*)(const Standard_Integer, const Standard_Integer)) &TObj_SequenceOfIterator::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TObj_SequenceOfIterator.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TObj_SequenceOfIterator::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TObj_SequenceOfIterator.def("Clear", [](TObj_SequenceOfIterator &self) -> void { return self.Clear(); });
	cls_TObj_SequenceOfIterator.def("Clear", (void (TObj_SequenceOfIterator::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TObj_SequenceOfIterator::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TObj_SequenceOfIterator.def("Assign", (TObj_SequenceOfIterator & (TObj_SequenceOfIterator::*)(const TObj_SequenceOfIterator &)) &TObj_SequenceOfIterator::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TObj_SequenceOfIterator.def("assign", (TObj_SequenceOfIterator & (TObj_SequenceOfIterator::*)(const TObj_SequenceOfIterator &)) &TObj_SequenceOfIterator::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TObj_SequenceOfIterator.def("Remove", (void (TObj_SequenceOfIterator::*)(TObj_SequenceOfIterator::Iterator &)) &TObj_SequenceOfIterator::Remove, "Remove one item", py::arg("thePosition"));
	cls_TObj_SequenceOfIterator.def("Remove", (void (TObj_SequenceOfIterator::*)(const Standard_Integer)) &TObj_SequenceOfIterator::Remove, "Remove one item", py::arg("theIndex"));
	cls_TObj_SequenceOfIterator.def("Remove", (void (TObj_SequenceOfIterator::*)(const Standard_Integer, const Standard_Integer)) &TObj_SequenceOfIterator::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TObj_SequenceOfIterator.def("Append", (void (TObj_SequenceOfIterator::*)(const opencascade::handle<TObj_ObjectIterator> &)) &TObj_SequenceOfIterator::Append, "Append one item", py::arg("theItem"));
	cls_TObj_SequenceOfIterator.def("Append", (void (TObj_SequenceOfIterator::*)(TObj_SequenceOfIterator &)) &TObj_SequenceOfIterator::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TObj_SequenceOfIterator.def("Prepend", (void (TObj_SequenceOfIterator::*)(const opencascade::handle<TObj_ObjectIterator> &)) &TObj_SequenceOfIterator::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TObj_SequenceOfIterator.def("Prepend", (void (TObj_SequenceOfIterator::*)(TObj_SequenceOfIterator &)) &TObj_SequenceOfIterator::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TObj_SequenceOfIterator.def("InsertBefore", (void (TObj_SequenceOfIterator::*)(const Standard_Integer, const opencascade::handle<TObj_ObjectIterator> &)) &TObj_SequenceOfIterator::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TObj_SequenceOfIterator.def("InsertBefore", (void (TObj_SequenceOfIterator::*)(const Standard_Integer, TObj_SequenceOfIterator &)) &TObj_SequenceOfIterator::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TObj_SequenceOfIterator.def("InsertAfter", (void (TObj_SequenceOfIterator::*)(TObj_SequenceOfIterator::Iterator &, const opencascade::handle<TObj_ObjectIterator> &)) &TObj_SequenceOfIterator::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TObj_SequenceOfIterator.def("InsertAfter", (void (TObj_SequenceOfIterator::*)(const Standard_Integer, TObj_SequenceOfIterator &)) &TObj_SequenceOfIterator::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TObj_SequenceOfIterator.def("InsertAfter", (void (TObj_SequenceOfIterator::*)(const Standard_Integer, const opencascade::handle<TObj_ObjectIterator> &)) &TObj_SequenceOfIterator::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TObj_SequenceOfIterator.def("Split", (void (TObj_SequenceOfIterator::*)(const Standard_Integer, TObj_SequenceOfIterator &)) &TObj_SequenceOfIterator::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TObj_SequenceOfIterator.def("First", (const opencascade::handle<TObj_ObjectIterator> & (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::First, "First item access");
	cls_TObj_SequenceOfIterator.def("ChangeFirst", (opencascade::handle<TObj_ObjectIterator> & (TObj_SequenceOfIterator::*)()) &TObj_SequenceOfIterator::ChangeFirst, "First item access");
	cls_TObj_SequenceOfIterator.def("Last", (const opencascade::handle<TObj_ObjectIterator> & (TObj_SequenceOfIterator::*)() const ) &TObj_SequenceOfIterator::Last, "Last item access");
	cls_TObj_SequenceOfIterator.def("ChangeLast", (opencascade::handle<TObj_ObjectIterator> & (TObj_SequenceOfIterator::*)()) &TObj_SequenceOfIterator::ChangeLast, "Last item access");
	cls_TObj_SequenceOfIterator.def("Value", (const opencascade::handle<TObj_ObjectIterator> & (TObj_SequenceOfIterator::*)(const Standard_Integer) const ) &TObj_SequenceOfIterator::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TObj_SequenceOfIterator.def("__call__", (const opencascade::handle<TObj_ObjectIterator> & (TObj_SequenceOfIterator::*)(const Standard_Integer) const ) &TObj_SequenceOfIterator::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TObj_SequenceOfIterator.def("ChangeValue", (opencascade::handle<TObj_ObjectIterator> & (TObj_SequenceOfIterator::*)(const Standard_Integer)) &TObj_SequenceOfIterator::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TObj_SequenceOfIterator.def("__call__", (opencascade::handle<TObj_ObjectIterator> & (TObj_SequenceOfIterator::*)(const Standard_Integer)) &TObj_SequenceOfIterator::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TObj_SequenceOfIterator.def("SetValue", (void (TObj_SequenceOfIterator::*)(const Standard_Integer, const opencascade::handle<TObj_ObjectIterator> &)) &TObj_SequenceOfIterator::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TObj_SequenceOfIterator.def("__iter__", [](const TObj_SequenceOfIterator &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	if (py::hasattr(mod, "TObj_TIntSparseArray_MapOfData")) {
		mod.attr("TObj_TIntSparseArray_VecOfData") = mod.attr("TObj_TIntSparseArray_MapOfData");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_SparseArray.hxx
	py::class_<TObj_TIntSparseArray_MapOfData, std::unique_ptr<TObj_TIntSparseArray_MapOfData, Deleter<TObj_TIntSparseArray_MapOfData>>, NCollection_SparseArrayBase> cls_TObj_TIntSparseArray_MapOfData(mod, "TObj_TIntSparseArray_MapOfData", "Dynamically resizable sparse array of objects");
	cls_TObj_TIntSparseArray_MapOfData.def(py::init<Standard_Size>(), py::arg("theIncrement"));
	cls_TObj_TIntSparseArray_MapOfData.def("Assign", (TObj_TIntSparseArray_MapOfData & (TObj_TIntSparseArray_MapOfData::*)(const TObj_TIntSparseArray_MapOfData &)) &TObj_TIntSparseArray_MapOfData::Assign, "Explicit assignment operator", py::arg("theOther"));
	cls_TObj_TIntSparseArray_MapOfData.def("Exchange", (void (TObj_TIntSparseArray_MapOfData::*)(TObj_TIntSparseArray_MapOfData &)) &TObj_TIntSparseArray_MapOfData::Exchange, "Exchange the data of two arrays; can be used primarily to move contents of theOther into the new array in a fast way (without creation of duplicated data)", py::arg("theOther"));
	cls_TObj_TIntSparseArray_MapOfData.def("Value", (const Standard_Integer & (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size) const ) &TObj_TIntSparseArray_MapOfData::Value, "Direct const access to the item", py::arg("theIndex"));
	cls_TObj_TIntSparseArray_MapOfData.def("__call__", (const Standard_Integer & (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size) const ) &TObj_TIntSparseArray_MapOfData::operator(), py::is_operator(), "Const access to the item - operator()", py::arg("theIndex"));
	cls_TObj_TIntSparseArray_MapOfData.def("ChangeValue", (Standard_Integer & (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size)) &TObj_TIntSparseArray_MapOfData::ChangeValue, "Modification access to the item", py::arg("theIndex"));
	cls_TObj_TIntSparseArray_MapOfData.def("__call__", (Standard_Integer & (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size)) &TObj_TIntSparseArray_MapOfData::operator(), py::is_operator(), "Access to the item - operator()", py::arg("theIndex"));
	cls_TObj_TIntSparseArray_MapOfData.def("SetValue", (Standard_Integer & (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size, const Standard_Integer &)) &TObj_TIntSparseArray_MapOfData::SetValue, "Set a value at specified index method", py::arg("theIndex"), py::arg("theValue"));
	cls_TObj_TIntSparseArray_MapOfData.def("Extent", (Standard_Size (TObj_TIntSparseArray_MapOfData::*)() const ) &TObj_TIntSparseArray_MapOfData::Extent, "Returns number of items in the array");
	cls_TObj_TIntSparseArray_MapOfData.def("IsEmpty", (Standard_Boolean (TObj_TIntSparseArray_MapOfData::*)() const ) &TObj_TIntSparseArray_MapOfData::IsEmpty, "Returns True if array is empty");
	cls_TObj_TIntSparseArray_MapOfData.def("Find", (const Standard_Integer & (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size) const ) &TObj_TIntSparseArray_MapOfData::Find, "Direct const access to the item", py::arg("theIndex"));
	cls_TObj_TIntSparseArray_MapOfData.def("ChangeFind", (Standard_Integer & (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size)) &TObj_TIntSparseArray_MapOfData::ChangeFind, "Modification access to the item", py::arg("theIndex"));
	cls_TObj_TIntSparseArray_MapOfData.def("Bind", (Standard_Integer & (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size, const Standard_Integer &)) &TObj_TIntSparseArray_MapOfData::Bind, "Set a value as explicit method", py::arg("theIndex"), py::arg("theValue"));
	cls_TObj_TIntSparseArray_MapOfData.def("IsBound", (Standard_Boolean (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size) const ) &TObj_TIntSparseArray_MapOfData::IsBound, "Returns True if the item is defined", py::arg("theIndex"));
	cls_TObj_TIntSparseArray_MapOfData.def("UnBind", (Standard_Boolean (TObj_TIntSparseArray_MapOfData::*)(const Standard_Size)) &TObj_TIntSparseArray_MapOfData::UnBind, "Remove the item from array", py::arg("theIndex"));


}
