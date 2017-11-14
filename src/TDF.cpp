#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Handle.hxx>
#include <TDF_Data.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_OStream.hxx>
#include <TDF_IDFilter.hxx>
#include <TDF_AttributeIndexedMap.hxx>
#include <Standard_Transient.hxx>
#include <TDF_Delta.hxx>
#include <TDF_HAllocator.hxx>
#include <Standard_Type.hxx>
#include <TDF_LabelNode.hxx>
#include <TDF_LabelNodePtr.hxx>
#include <TDF_AttributeDelta.hxx>
#include <TDF_DeltaOnAddition.hxx>
#include <TDF_DeltaOnForget.hxx>
#include <TDF_DeltaOnResume.hxx>
#include <TDF_DeltaOnModification.hxx>
#include <TDF_DeltaOnRemoval.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_IndexedMap.hxx>
#include <TDF_ChildIterator.hxx>
#include <TDF_AttributeIterator.hxx>
#include <TDF_LabelMapHasher.hxx>
#include <TDF_IDList.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_AttributeMap.hxx>
#include <TDF_LabelDataMap.hxx>
#include <TDF_AttributeDataMap.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <TDF_LabelList.hxx>
#include <TDF_TagSource.hxx>
#include <TCollection_AsciiString.hxx>
#include <TDF_Transaction.hxx>
#include <TDF_AttributeDeltaList.hxx>
#include <TCollection_ExtendedString.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TDF_LabelSequence.hxx>
#include <TDF_AttributeList.hxx>
#include <TDF_Reference.hxx>
#include <NCollection_Map.hxx>
#include <TDF_ClosureMode.hxx>
#include <TDF_ClosureTool.hxx>
#include <TDF_CopyTool.hxx>
#include <TDF_CopyLabel.hxx>
#include <TDF_ComparisonTool.hxx>
#include <TDF_DefaultDeltaOnRemoval.hxx>
#include <TDF_DefaultDeltaOnModification.hxx>
#include <TDF_ChildIDIterator.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TDF_LabelIntegerMap.hxx>
#include <TDF_Tool.hxx>
#include <TDF.hxx>
#include <NCollection_Array1.hxx>
#include <TDF_AttributeArray1.hxx>
#include <NCollection_DataMap.hxx>
#include <NCollection_DoubleMap.hxx>
#include <TDF_AttributeDoubleMap.hxx>
#include <TDF_AttributeSequence.hxx>
#include <TDF_IDMap.hxx>
#include <TDF_DeltaList.hxx>
#include <TDF_GUIDProgIDMap.hxx>
#include <TDF_LabelDoubleMap.hxx>
#include <TDF_HAttributeArray1.hxx>
#include <TDF_LabelIndexedMap.hxx>

PYBIND11_MODULE(TDF, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_LabelNode.hxx
	mod.attr("TDF_LabelNodeImportMsk") = py::cast(int(TDF_LabelNodeImportMsk));
	mod.attr("TDF_LabelNodeAttModMsk") = py::cast(int(TDF_LabelNodeAttModMsk));
	mod.attr("TDF_LabelNodeMayModMsk") = py::cast(int(TDF_LabelNodeMayModMsk));
	mod.attr("TDF_LabelNodeFlagsMsk") = py::cast(int(TDF_LabelNodeFlagsMsk));


	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_Label.lxx
	mod.def("operator<<", (Standard_OStream & (*)(Standard_OStream &, const TDF_Label &)) &operator<<, "None", py::arg("anOS"), py::arg("aLab"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_Label.hxx
	py::class_<TDF_Label, std::unique_ptr<TDF_Label, Deleter<TDF_Label>>> cls_TDF_Label(mod, "TDF_Label", "This class provides basic operations to define a label in a data structure. A label is a feature in the feature hierarchy. A label is always connected to a Data from TDF. To a label is attached attributes containing the software components information.");
	cls_TDF_Label.def(py::init<>());
	cls_TDF_Label.def("Nullify", (void (TDF_Label::*)()) &TDF_Label::Nullify, "Nullifies the label.");
	cls_TDF_Label.def("Data", (opencascade::handle<TDF_Data> (TDF_Label::*)() const ) &TDF_Label::Data, "Returns the Data owning <me>.");
	cls_TDF_Label.def("Tag", (Standard_Integer (TDF_Label::*)() const ) &TDF_Label::Tag, "Returns the tag of the label. This is the integer assigned randomly to a label in a data framework. This integer is used to identify this label in an entry.");
	cls_TDF_Label.def("Father", (const TDF_Label (TDF_Label::*)() const ) &TDF_Label::Father, "Returns the label father. This label may be null if the label is root.");
	cls_TDF_Label.def("IsNull", (Standard_Boolean (TDF_Label::*)() const ) &TDF_Label::IsNull, "Returns True if the <aLabel> is null, i.e. it has not been included in the data framework.");
	cls_TDF_Label.def("Imported", (void (TDF_Label::*)(const Standard_Boolean) const ) &TDF_Label::Imported, "Sets or unsets <me> and all its descendants as imported label, according to <aStatus>.", py::arg("aStatus"));
	cls_TDF_Label.def("IsImported", (Standard_Boolean (TDF_Label::*)() const ) &TDF_Label::IsImported, "Returns True if the <aLabel> is imported.");
	cls_TDF_Label.def("IsEqual", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const ) &TDF_Label::IsEqual, "Returns True if the <aLabel> is equal to me (same LabelNode*).", py::arg("aLabel"));
	cls_TDF_Label.def("__eq__", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const ) &TDF_Label::operator==, py::is_operator(), "None", py::arg("aLabel"));
	cls_TDF_Label.def("IsDifferent", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const ) &TDF_Label::IsDifferent, "None", py::arg("aLabel"));
	cls_TDF_Label.def("__ne__", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const ) &TDF_Label::operator!=, py::is_operator(), "None", py::arg("aLabel"));
	cls_TDF_Label.def("IsRoot", (Standard_Boolean (TDF_Label::*)() const ) &TDF_Label::IsRoot, "None");
	cls_TDF_Label.def("IsAttribute", (Standard_Boolean (TDF_Label::*)(const Standard_GUID &) const ) &TDF_Label::IsAttribute, "Returns true if <me> owns an attribute with <anID> as ID.", py::arg("anID"));
	cls_TDF_Label.def("AddAttribute", [](TDF_Label &self, const opencascade::handle<TDF_Attribute> & a0) -> void { return self.AddAttribute(a0); }, py::arg("anAttribute"));
	cls_TDF_Label.def("AddAttribute", (void (TDF_Label::*)(const opencascade::handle<TDF_Attribute> &, const Standard_Boolean) const ) &TDF_Label::AddAttribute, "Adds an Attribute to the current label. Raises if there is already one.", py::arg("anAttribute"), py::arg("append"));
	cls_TDF_Label.def("ForgetAttribute", (void (TDF_Label::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_Label::ForgetAttribute, "Forgets an Attribute from the current label, setting its forgotten status true and its valid status false. Raises if the attribute is not in the structure.", py::arg("anAttribute"));
	cls_TDF_Label.def("ForgetAttribute", (Standard_Boolean (TDF_Label::*)(const Standard_GUID &) const ) &TDF_Label::ForgetAttribute, "Forgets the Attribute of GUID <aguid> from the current label . If the attribute doesn't exist returns False. Otherwise returns True.", py::arg("aguid"));
	cls_TDF_Label.def("ForgetAllAttributes", [](TDF_Label &self) -> void { return self.ForgetAllAttributes(); });
	cls_TDF_Label.def("ForgetAllAttributes", (void (TDF_Label::*)(const Standard_Boolean) const ) &TDF_Label::ForgetAllAttributes, "Forgets all the attributes. Does it on also on the sub-labels if <clearChildren> is set to true. Of course, this method is compatible with Transaction & Delta mecanisms.", py::arg("clearChildren"));
	cls_TDF_Label.def("ResumeAttribute", (void (TDF_Label::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_Label::ResumeAttribute, "Undo Forget action, setting its forgotten status false and its valid status true. Raises if the attribute is not in the structure.", py::arg("anAttribute"));
	cls_TDF_Label.def("FindAttribute", (Standard_Boolean (TDF_Label::*)(const Standard_GUID &, opencascade::handle<TDF_Attribute> &) const ) &TDF_Label::FindAttribute, "Finds an attribute of the current label, according to <anID>. If anAttribute is not a valid one, false is returned.", py::arg("anID"), py::arg("anAttribute"));
	cls_TDF_Label.def("FindAttribute", (Standard_Boolean (TDF_Label::*)(const Standard_GUID &, const Standard_Integer, opencascade::handle<TDF_Attribute> &) const ) &TDF_Label::FindAttribute, "Finds an attribute of the current label, according to <anID> and <aTransaction>. This attribute has/had to be a valid one for the given transaction index . So, this attribute is not necessary a valid one.", py::arg("anID"), py::arg("aTransaction"), py::arg("anAttribute"));
	cls_TDF_Label.def("MayBeModified", (Standard_Boolean (TDF_Label::*)() const ) &TDF_Label::MayBeModified, "Returns true if <me> or a DESCENDANT of <me> owns attributes not yet available in transaction 0. It means at least one of their attributes is new, modified or deleted.");
	cls_TDF_Label.def("AttributesModified", (Standard_Boolean (TDF_Label::*)() const ) &TDF_Label::AttributesModified, "Returns true if <me> owns attributes not yet available in transaction 0. It means at least one attribute is new, modified or deleted.");
	cls_TDF_Label.def("HasAttribute", (Standard_Boolean (TDF_Label::*)() const ) &TDF_Label::HasAttribute, "Returns true if this label has at least one attribute.");
	cls_TDF_Label.def("NbAttributes", (Standard_Integer (TDF_Label::*)() const ) &TDF_Label::NbAttributes, "Returns the number of attributes.");
	cls_TDF_Label.def("Depth", (Standard_Integer (TDF_Label::*)() const ) &TDF_Label::Depth, "Returns the depth of the label in the data framework. This corresponds to the number of fathers which this label has, and is used in determining whether a label is root, null or equivalent to another label. Exceptions: Standard_NullObject if this label is null. This is because a null object can have no depth.");
	cls_TDF_Label.def("IsDescendant", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const ) &TDF_Label::IsDescendant, "Returns True if <me> is a descendant of <aLabel>. Attention: every label is its own descendant.", py::arg("aLabel"));
	cls_TDF_Label.def("Root", (const TDF_Label (TDF_Label::*)() const ) &TDF_Label::Root, "Returns the root label Root of the data structure. This has a depth of 0. Exceptions: Standard_NullObject if this label is null. This is because a null object can have no depth.");
	cls_TDF_Label.def("HasChild", (Standard_Boolean (TDF_Label::*)() const ) &TDF_Label::HasChild, "Returns true if this label has at least one child.");
	cls_TDF_Label.def("NbChildren", (Standard_Integer (TDF_Label::*)() const ) &TDF_Label::NbChildren, "Returns the number of children.");
	cls_TDF_Label.def("FindChild", [](TDF_Label &self, const Standard_Integer a0) -> TDF_Label { return self.FindChild(a0); }, py::arg("aTag"));
	cls_TDF_Label.def("FindChild", (TDF_Label (TDF_Label::*)(const Standard_Integer, const Standard_Boolean) const ) &TDF_Label::FindChild, "Finds a child label having <aTag> as tag. Creates The tag aTag identifies the label which will be the parent. If create is true and no child label is found, a new one is created. Example: //creating a label with tag 10 at Root TDF_Label lab1 = aDF->Root().FindChild(10); //creating labels 7 and 2 on label 10 TDF_Label lab2 = lab1.FindChild(7); TDF_Label lab3 = lab1.FindChild(2);", py::arg("aTag"), py::arg("create"));
	cls_TDF_Label.def("NewChild", (TDF_Label (TDF_Label::*)() const ) &TDF_Label::NewChild, "Create a new child label of me using autoamtic delivery tags provided by TagSource.");
	cls_TDF_Label.def("Transaction", (Standard_Integer (TDF_Label::*)() const ) &TDF_Label::Transaction, "Returns the current transaction index.");
	cls_TDF_Label.def("HasLowerNode", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const ) &TDF_Label::HasLowerNode, "Returns true if node address of <me> is lower than <otherLabel> one. Used to quickly sort labels (not on entry criterion).", py::arg("otherLabel"));
	cls_TDF_Label.def("HasGreaterNode", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const ) &TDF_Label::HasGreaterNode, "Returns true if node address of <me> is greater than <otherLabel> one. Used to quickly sort labels (not on entry criterion).", py::arg("otherLabel"));
	// FIXME cls_TDF_Label.def("Dump", (Standard_OStream & (TDF_Label::*)(Standard_OStream &) const ) &TDF_Label::Dump, "Dumps the minimum information about <me> on <aStream>.", py::arg("anOS"));
	cls_TDF_Label.def("operator<<", (Standard_OStream & (TDF_Label::*)(Standard_OStream &) const ) &TDF_Label::operator<<, "None", py::arg("anOS"));
	cls_TDF_Label.def("ExtendedDump", (void (TDF_Label::*)(Standard_OStream &, const TDF_IDFilter &, TDF_AttributeIndexedMap &) const ) &TDF_Label::ExtendedDump, "Dumps the label on <aStream> and its attributes rank in <aMap> if their IDs are kept by <IDFilter>.", py::arg("anOS"), py::arg("aFilter"), py::arg("aMap"));
	cls_TDF_Label.def("EntryDump", (void (TDF_Label::*)(Standard_OStream &) const ) &TDF_Label::EntryDump, "Dumps the label entry.", py::arg("anOS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_Data.hxx
	py::class_<TDF_Data, opencascade::handle<TDF_Data>, Standard_Transient> cls_TDF_Data(mod, "TDF_Data", "This class is used to manipulate a complete independant, self sufficient data structure and its services:");
	cls_TDF_Data.def(py::init<>());
	cls_TDF_Data.def("Root", (const TDF_Label (TDF_Data::*)() const ) &TDF_Data::Root, "Returns the root label of the Data structure.");
	cls_TDF_Data.def("Transaction", (Standard_Integer (TDF_Data::*)() const ) &TDF_Data::Transaction, "Returns the current transaction number.");
	cls_TDF_Data.def("Time", (Standard_Integer (TDF_Data::*)() const ) &TDF_Data::Time, "Returns the current tick. It is incremented each Commit.");
	cls_TDF_Data.def("IsApplicable", (Standard_Boolean (TDF_Data::*)(const opencascade::handle<TDF_Delta> &) const ) &TDF_Data::IsApplicable, "Returns true if <aDelta> is applicable HERE and NOW.", py::arg("aDelta"));
	cls_TDF_Data.def("Undo", [](TDF_Data &self, const opencascade::handle<TDF_Delta> & a0) -> opencascade::handle<TDF_Delta> { return self.Undo(a0); }, py::arg("aDelta"));
	cls_TDF_Data.def("Undo", (opencascade::handle<TDF_Delta> (TDF_Data::*)(const opencascade::handle<TDF_Delta> &, const Standard_Boolean)) &TDF_Data::Undo, "Apply <aDelta> to undo a set of attribute modifications.", py::arg("aDelta"), py::arg("withDelta"));
	cls_TDF_Data.def("Destroy", (void (TDF_Data::*)()) &TDF_Data::Destroy, "None");
	cls_TDF_Data.def("NotUndoMode", (Standard_Boolean (TDF_Data::*)() const ) &TDF_Data::NotUndoMode, "Returns the undo mode status.");
	// FIXME cls_TDF_Data.def("Dump", (Standard_OStream & (TDF_Data::*)(Standard_OStream &) const ) &TDF_Data::Dump, "Dumps the Data on <aStream>.", py::arg("anOS"));
	cls_TDF_Data.def("operator<<", (Standard_OStream & (TDF_Data::*)(Standard_OStream &) const ) &TDF_Data::operator<<, "None", py::arg("anOS"));
	cls_TDF_Data.def("AllowModification", (void (TDF_Data::*)(const Standard_Boolean)) &TDF_Data::AllowModification, "Sets modification mode.", py::arg("isAllowed"));
	cls_TDF_Data.def("IsModificationAllowed", (Standard_Boolean (TDF_Data::*)() const ) &TDF_Data::IsModificationAllowed, "returns modification mode.");
	cls_TDF_Data.def("LabelNodeAllocator", (const TDF_HAllocator & (TDF_Data::*)() const ) &TDF_Data::LabelNodeAllocator, "Returns TDF_HAllocator, which is an incremental allocator used by TDF_LabelNode. This allocator is used to manage TDF_LabelNode objects, but it can also be used for allocating memory to application-specific data (be careful because this allocator does not release the memory). The benefits of this allocation scheme are noticeable when dealing with large OCAF documents, due to: 1. Very quick allocation of objects (memory heap is not used, the algorithm that replaces it is very simple). 2. Very quick destruction of objects (memory is released not by destructors of TDF_LabelNode, but rather by the destructor of TDF_Data). 3. TDF_LabelNode objects do not fragmentize the memory; they are kept compactly in a number of arrays of 16K each. 4. Swapping is reduced on large data, because each document now occupies a smaller number of memory pages.");
	cls_TDF_Data.def_static("get_type_name_", (const char * (*)()) &TDF_Data::get_type_name, "None");
	cls_TDF_Data.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_Data::get_type_descriptor, "None");
	cls_TDF_Data.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_Data::*)() const ) &TDF_Data::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_LabelNode.hxx
	py::class_<TDF_LabelNode, std::unique_ptr<TDF_LabelNode, Deleter<TDF_LabelNode>>> cls_TDF_LabelNode(mod, "TDF_LabelNode", "None");
	cls_TDF_LabelNode.def("Father", (TDF_LabelNode * (TDF_LabelNode::*)() const ) &TDF_LabelNode::Father, "None");
	cls_TDF_LabelNode.def("Brother", (TDF_LabelNode * (TDF_LabelNode::*)() const ) &TDF_LabelNode::Brother, "None");
	cls_TDF_LabelNode.def("FirstChild", (TDF_LabelNode * (TDF_LabelNode::*)() const ) &TDF_LabelNode::FirstChild, "None");
	cls_TDF_LabelNode.def("FirstAttribute", (const opencascade::handle<TDF_Attribute> & (TDF_LabelNode::*)() const ) &TDF_LabelNode::FirstAttribute, "None");
	cls_TDF_LabelNode.def("Tag", (Standard_Integer (TDF_LabelNode::*)() const ) &TDF_LabelNode::Tag, "None");
	cls_TDF_LabelNode.def("Depth", (Standard_Integer (TDF_LabelNode::*)() const ) &TDF_LabelNode::Depth, "None");
	cls_TDF_LabelNode.def("IsRoot", (Standard_Boolean (TDF_LabelNode::*)() const ) &TDF_LabelNode::IsRoot, "None");
	cls_TDF_LabelNode.def("Data", (TDF_Data * (TDF_LabelNode::*)() const ) &TDF_LabelNode::Data, "None");
	cls_TDF_LabelNode.def("AttributesModified", (void (TDF_LabelNode::*)(const Standard_Boolean)) &TDF_LabelNode::AttributesModified, "None", py::arg("aStatus"));
	cls_TDF_LabelNode.def("AttributesModified", (Standard_Boolean (TDF_LabelNode::*)() const ) &TDF_LabelNode::AttributesModified, "None");
	cls_TDF_LabelNode.def("MayBeModified", (void (TDF_LabelNode::*)(const Standard_Boolean)) &TDF_LabelNode::MayBeModified, "None", py::arg("aStatus"));
	cls_TDF_LabelNode.def("MayBeModified", (Standard_Boolean (TDF_LabelNode::*)() const ) &TDF_LabelNode::MayBeModified, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_Attribute.hxx
	py::class_<TDF_Attribute, opencascade::handle<TDF_Attribute>, Standard_Transient> cls_TDF_Attribute(mod, "TDF_Attribute", "A class each application has to implement. It is used to contain the application data. This abstract class, alongwith Label, is one of the cornerstones of Model Editor. The groundwork is to define the root of information. This information is to be attached to a Label, and could be of any of the following types: - a feature - a constraint - a comment");
	cls_TDF_Attribute.def("ID", (const Standard_GUID & (TDF_Attribute::*)() const ) &TDF_Attribute::ID, "Returns the ID of the attribute.");
	cls_TDF_Attribute.def("SetID", (void (TDF_Attribute::*)(const Standard_GUID &)) &TDF_Attribute::SetID, "Sets specific ID of the attribute (supports several attributes of one type at the same label feature).", py::arg("theGuid"));
	cls_TDF_Attribute.def("SetID", (void (TDF_Attribute::*)()) &TDF_Attribute::SetID, "Sets default ID defined in nested class (to be used for attributes having User ID feature).");
	cls_TDF_Attribute.def("Label", (const TDF_Label (TDF_Attribute::*)() const ) &TDF_Attribute::Label, "Returns the label to which the attribute is attached. If the label is not included in a DF, the label is null. See Label. Warning If the label is not included in a data framework, it is null. This function should not be redefined inline.");
	cls_TDF_Attribute.def("Transaction", (Standard_Integer (TDF_Attribute::*)() const ) &TDF_Attribute::Transaction, "Returns the transaction index in which the attribute has been created or modified.");
	cls_TDF_Attribute.def("UntilTransaction", (Standard_Integer (TDF_Attribute::*)() const ) &TDF_Attribute::UntilTransaction, "Returns the upper transaction index until which the attribute is/was valid. This number may vary. A removed attribute validity range is reduced to its transaction index.");
	cls_TDF_Attribute.def("IsValid", (Standard_Boolean (TDF_Attribute::*)() const ) &TDF_Attribute::IsValid, "Returns true if the attribute is valid; i.e. not a backuped or removed one.");
	cls_TDF_Attribute.def("IsNew", (Standard_Boolean (TDF_Attribute::*)() const ) &TDF_Attribute::IsNew, "Returns true if the attribute has no backup");
	cls_TDF_Attribute.def("IsForgotten", (Standard_Boolean (TDF_Attribute::*)() const ) &TDF_Attribute::IsForgotten, "Returns true if the attribute forgotten status is set.");
	cls_TDF_Attribute.def("IsAttribute", (Standard_Boolean (TDF_Attribute::*)(const Standard_GUID &) const ) &TDF_Attribute::IsAttribute, "Returns true if it exists an associated attribute of <me> with <anID> as ID.", py::arg("anID"));
	cls_TDF_Attribute.def("FindAttribute", (Standard_Boolean (TDF_Attribute::*)(const Standard_GUID &, opencascade::handle<TDF_Attribute> &) const ) &TDF_Attribute::FindAttribute, "Finds an associated attribute of <me>, according to <anID>. the returned <anAttribute> is a valid one. The method returns True if found, False otherwise. A removed attribute cannot be found using this method.", py::arg("anID"), py::arg("anAttribute"));
	cls_TDF_Attribute.def("AddAttribute", (void (TDF_Attribute::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_Attribute::AddAttribute, "Adds an Attribute <other> to the label of <me>.Raises if there is already one of the same GUID fhan <other>.", py::arg("other"));
	cls_TDF_Attribute.def("ForgetAttribute", (Standard_Boolean (TDF_Attribute::*)(const Standard_GUID &) const ) &TDF_Attribute::ForgetAttribute, "Forgets the Attribute of GUID <aguid> associated to the label of <me>. Be carefull that if <me> is the attribute of <guid>, <me> will have a null label after this call. If the attribute doesn't exist returns False. Otherwise returns True.", py::arg("aguid"));
	cls_TDF_Attribute.def("ForgetAllAttributes", [](TDF_Attribute &self) -> void { return self.ForgetAllAttributes(); });
	cls_TDF_Attribute.def("ForgetAllAttributes", (void (TDF_Attribute::*)(const Standard_Boolean) const ) &TDF_Attribute::ForgetAllAttributes, "Forgets all the attributes attached to the label of <me>. Does it on the sub-labels if <clearChildren> is set to true. Of course, this method is compatible with Transaction & Delta mecanisms. Be carefull that if <me> will have a null label after this call", py::arg("clearChildren"));
	cls_TDF_Attribute.def("AfterAddition", (void (TDF_Attribute::*)()) &TDF_Attribute::AfterAddition, "Something to do after adding an Attribute to a label.");
	cls_TDF_Attribute.def("BeforeRemoval", (void (TDF_Attribute::*)()) &TDF_Attribute::BeforeRemoval, "Something to do before removing an Attribute from a label.");
	cls_TDF_Attribute.def("BeforeForget", (void (TDF_Attribute::*)()) &TDF_Attribute::BeforeForget, "Something to do before forgetting an Attribute to a label.");
	cls_TDF_Attribute.def("AfterResume", (void (TDF_Attribute::*)()) &TDF_Attribute::AfterResume, "Something to do after resuming an Attribute from a label.");
	cls_TDF_Attribute.def("AfterRetrieval", [](TDF_Attribute &self) -> Standard_Boolean { return self.AfterRetrieval(); });
	cls_TDF_Attribute.def("AfterRetrieval", (Standard_Boolean (TDF_Attribute::*)(const Standard_Boolean)) &TDF_Attribute::AfterRetrieval, "Something to do AFTER creation of an attribute by persistent-transient translation. The returned status says if AfterUndo has been performed (true) or if this callback must be called once again further (false). If <forceIt> is set to true, the method MUST perform and return true. Does nothing by default and returns true.", py::arg("forceIt"));
	cls_TDF_Attribute.def("BeforeUndo", [](TDF_Attribute &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); }, py::arg("anAttDelta"));
	cls_TDF_Attribute.def("BeforeUndo", (Standard_Boolean (TDF_Attribute::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDF_Attribute::BeforeUndo, "Something to do before applying <anAttDelta>. The returned status says if AfterUndo has been performed (true) or if this callback must be called once again further (false). If <forceIt> is set to true, the method MUST perform and return true. Does nothing by default and returns true.", py::arg("anAttDelta"), py::arg("forceIt"));
	cls_TDF_Attribute.def("AfterUndo", [](TDF_Attribute &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); }, py::arg("anAttDelta"));
	cls_TDF_Attribute.def("AfterUndo", (Standard_Boolean (TDF_Attribute::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDF_Attribute::AfterUndo, "Something to do after applying <anAttDelta>. The returned status says if AfterUndo has been performed (true) or if this callback must be called once again further (false). If <forceIt> is set to true, the method MUST perform and return true. Does nothing by default and returns true.", py::arg("anAttDelta"), py::arg("forceIt"));
	cls_TDF_Attribute.def("BeforeCommitTransaction", (void (TDF_Attribute::*)()) &TDF_Attribute::BeforeCommitTransaction, "A callback. By default does nothing. It is called by TDF_Data::CommitTransaction() method.");
	cls_TDF_Attribute.def("Backup", (void (TDF_Attribute::*)()) &TDF_Attribute::Backup, "Backups the attribute. The backuped attribute is flagged 'Backuped' and not 'Valid'.");
	cls_TDF_Attribute.def("IsBackuped", (Standard_Boolean (TDF_Attribute::*)() const ) &TDF_Attribute::IsBackuped, "Returns true if the attribute backup status is set. This status is set/unset by the Backup() method.");
	cls_TDF_Attribute.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TDF_Attribute::*)() const ) &TDF_Attribute::BackupCopy, "Copies the attribute contents into a new other attribute. It is used by Backup().");
	cls_TDF_Attribute.def("Restore", (void (TDF_Attribute::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_Attribute::Restore, "Restores the backuped contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
	cls_TDF_Attribute.def("DeltaOnAddition", (opencascade::handle<TDF_DeltaOnAddition> (TDF_Attribute::*)() const ) &TDF_Attribute::DeltaOnAddition, "Makes an AttributeDelta because <me> appeared. The only known use of a redefinition of this method is to return a null handle (no delta).");
	cls_TDF_Attribute.def("DeltaOnForget", (opencascade::handle<TDF_DeltaOnForget> (TDF_Attribute::*)() const ) &TDF_Attribute::DeltaOnForget, "Makes an AttributeDelta because <me> has been forgotten.");
	cls_TDF_Attribute.def("DeltaOnResume", (opencascade::handle<TDF_DeltaOnResume> (TDF_Attribute::*)() const ) &TDF_Attribute::DeltaOnResume, "Makes an AttributeDelta because <me> has been resumed.");
	cls_TDF_Attribute.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TDF_Attribute::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_Attribute::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute.", py::arg("anOldAttribute"));
	cls_TDF_Attribute.def("DeltaOnModification", (void (TDF_Attribute::*)(const opencascade::handle<TDF_DeltaOnModification> &)) &TDF_Attribute::DeltaOnModification, "Applies a DeltaOnModification to <me>.", py::arg("aDelta"));
	cls_TDF_Attribute.def("DeltaOnRemoval", (opencascade::handle<TDF_DeltaOnRemoval> (TDF_Attribute::*)() const ) &TDF_Attribute::DeltaOnRemoval, "Makes a DeltaOnRemoval on <me> because <me> has disappeared from the DS.");
	cls_TDF_Attribute.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDF_Attribute::*)() const ) &TDF_Attribute::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
	cls_TDF_Attribute.def("Paste", (void (TDF_Attribute::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TDF_Attribute::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method may paste the contents of <me> into <intoAttribute>.", py::arg("intoAttribute"), py::arg("aRelocationTable"));
	cls_TDF_Attribute.def("References", (void (TDF_Attribute::*)(const opencascade::handle<TDF_DataSet> &) const ) &TDF_Attribute::References, "Adds the first level referenced attributes and labels to <aDataSet>.", py::arg("aDataSet"));
	// FIXME cls_TDF_Attribute.def("Dump", (Standard_OStream & (TDF_Attribute::*)(Standard_OStream &) const ) &TDF_Attribute::Dump, "Dumps the minimum information about <me> on <aStream>.", py::arg("anOS"));
	cls_TDF_Attribute.def("operator<<", (Standard_OStream & (TDF_Attribute::*)(Standard_OStream &) const ) &TDF_Attribute::operator<<, "None", py::arg("anOS"));
	cls_TDF_Attribute.def("ExtendedDump", (void (TDF_Attribute::*)(Standard_OStream &, const TDF_IDFilter &, TDF_AttributeIndexedMap &) const ) &TDF_Attribute::ExtendedDump, "Dumps the attribute content on <aStream>, using <aMap> like this: if an attribute is not in the map, first put add it to the map and then dump it. Use the map rank instead of dumping each attribute field.", py::arg("anOS"), py::arg("aFilter"), py::arg("aMap"));
	cls_TDF_Attribute.def("Forget", (void (TDF_Attribute::*)(const Standard_Integer)) &TDF_Attribute::Forget, "Forgets the attribute. <aTransaction> is the current transaction in which the forget is done. A forgotten attribute is also flagged not 'Valid'.", py::arg("aTransaction"));
	cls_TDF_Attribute.def_static("get_type_name_", (const char * (*)()) &TDF_Attribute::get_type_name, "None");
	cls_TDF_Attribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_Attribute::get_type_descriptor, "None");
	cls_TDF_Attribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_Attribute::*)() const ) &TDF_Attribute::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_ChildIterator.hxx
	py::class_<TDF_ChildIterator, std::unique_ptr<TDF_ChildIterator, Deleter<TDF_ChildIterator>>> cls_TDF_ChildIterator(mod, "TDF_ChildIterator", "Iterates on the children of a label, at the first level only. It is possible to ask the iterator to explore all the sub label levels of the given one, with the option 'allLevels'.");
	cls_TDF_ChildIterator.def(py::init<>());
	cls_TDF_ChildIterator.def(py::init<const TDF_Label &>(), py::arg("aLabel"));
	cls_TDF_ChildIterator.def(py::init<const TDF_Label &, const Standard_Boolean>(), py::arg("aLabel"), py::arg("allLevels"));
	cls_TDF_ChildIterator.def("Initialize", [](TDF_ChildIterator &self, const TDF_Label & a0) -> void { return self.Initialize(a0); }, py::arg("aLabel"));
	cls_TDF_ChildIterator.def("Initialize", (void (TDF_ChildIterator::*)(const TDF_Label &, const Standard_Boolean)) &TDF_ChildIterator::Initialize, "Initializes the iteration on the children of the given label. If <allLevels> option is set to true, it explores not only the first, but all the sub label levels. If allLevels is false, only the first level of child labels is explored. In the example below, the label is iterated using Initialize, More and Next and its child labels dumped using TDF_Tool::Entry. Example void DumpChildren(const TDF_Label& aLabel) { TDF_ChildIterator it; TCollection_AsciiString es; for (it.Initialize(aLabel,Standard_True); it.More(); it.Next()){ TDF_Tool::Entry(it.Value(),es); cout << as.ToCString() << endl; } }", py::arg("aLabel"), py::arg("allLevels"));
	cls_TDF_ChildIterator.def("More", (Standard_Boolean (TDF_ChildIterator::*)() const ) &TDF_ChildIterator::More, "Returns true if a current label is found in the iteration process.");
	cls_TDF_ChildIterator.def("Next", (void (TDF_ChildIterator::*)()) &TDF_ChildIterator::Next, "Move the current iteration to the next Item.");
	cls_TDF_ChildIterator.def("NextBrother", (void (TDF_ChildIterator::*)()) &TDF_ChildIterator::NextBrother, "Moves this iteration to the next brother label. A brother label is one with the same father as an initial label. Use this function when the non-empty constructor or Initialize has allLevels set to true. The result is that the iteration does not explore the children of the current label. This method is interesting only with 'allLevels' behavior, because it avoids to explore the current label children.");
	cls_TDF_ChildIterator.def("Value", (const TDF_Label (TDF_ChildIterator::*)() const ) &TDF_ChildIterator::Value, "Returns the current label; or, if there is none, a null label.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_AttributeIterator.hxx
	py::class_<TDF_AttributeIterator, std::unique_ptr<TDF_AttributeIterator, Deleter<TDF_AttributeIterator>>> cls_TDF_AttributeIterator(mod, "TDF_AttributeIterator", "None");
	cls_TDF_AttributeIterator.def(py::init<>());
	cls_TDF_AttributeIterator.def(py::init<const TDF_Label &>(), py::arg("aLabel"));
	cls_TDF_AttributeIterator.def(py::init<const TDF_Label &, const Standard_Boolean>(), py::arg("aLabel"), py::arg("withoutForgotten"));
	cls_TDF_AttributeIterator.def(py::init<const TDF_LabelNodePtr>(), py::arg("aLabelNode"));
	cls_TDF_AttributeIterator.def(py::init<const TDF_LabelNodePtr, const Standard_Boolean>(), py::arg("aLabelNode"), py::arg("withoutForgotten"));
	cls_TDF_AttributeIterator.def("Initialize", [](TDF_AttributeIterator &self, const TDF_Label & a0) -> void { return self.Initialize(a0); }, py::arg("aLabel"));
	cls_TDF_AttributeIterator.def("Initialize", (void (TDF_AttributeIterator::*)(const TDF_Label &, const Standard_Boolean)) &TDF_AttributeIterator::Initialize, "None", py::arg("aLabel"), py::arg("withoutForgotten"));
	cls_TDF_AttributeIterator.def("More", (Standard_Boolean (TDF_AttributeIterator::*)() const ) &TDF_AttributeIterator::More, "None");
	cls_TDF_AttributeIterator.def("Next", (void (TDF_AttributeIterator::*)()) &TDF_AttributeIterator::Next, "None");
	cls_TDF_AttributeIterator.def("Value", (opencascade::handle<TDF_Attribute> (TDF_AttributeIterator::*)() const ) &TDF_AttributeIterator::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_LabelMapHasher.hxx
	py::class_<TDF_LabelMapHasher, std::unique_ptr<TDF_LabelMapHasher, Deleter<TDF_LabelMapHasher>>> cls_TDF_LabelMapHasher(mod, "TDF_LabelMapHasher", "A label hasher for label maps.");
	cls_TDF_LabelMapHasher.def(py::init<>());
	cls_TDF_LabelMapHasher.def_static("HashCode_", (Standard_Integer (*)(const TDF_Label &, const Standard_Integer)) &TDF_LabelMapHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("aLab"), py::arg("Upper"));
	cls_TDF_LabelMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TDF_Label &, const TDF_Label &)) &TDF_LabelMapHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("aLab1"), py::arg("aLab2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_IDFilter.hxx
	py::class_<TDF_IDFilter, std::unique_ptr<TDF_IDFilter, Deleter<TDF_IDFilter>>> cls_TDF_IDFilter(mod, "TDF_IDFilter", "This class offers filtering services around an ID list.");
	cls_TDF_IDFilter.def(py::init<>());
	cls_TDF_IDFilter.def(py::init<const Standard_Boolean>(), py::arg("ignoreMode"));
	cls_TDF_IDFilter.def("IgnoreAll", (void (TDF_IDFilter::*)(const Standard_Boolean)) &TDF_IDFilter::IgnoreAll, "The list of ID is cleared and the filter mode is set to ignore mode if <keep> is true; false otherwise.", py::arg("ignore"));
	cls_TDF_IDFilter.def("IgnoreAll", (Standard_Boolean (TDF_IDFilter::*)() const ) &TDF_IDFilter::IgnoreAll, "Returns true is the mode is set to 'ignore all but...'.");
	cls_TDF_IDFilter.def("Keep", (void (TDF_IDFilter::*)(const Standard_GUID &)) &TDF_IDFilter::Keep, "An attribute with <anID> as ID is to be kept and the filter will answer true to the question IsKept(<anID>).", py::arg("anID"));
	cls_TDF_IDFilter.def("Keep", (void (TDF_IDFilter::*)(const TDF_IDList &)) &TDF_IDFilter::Keep, "Attributes with ID owned by <anIDList> are to be kept and the filter will answer true to the question IsKept(<anID>) with ID from <anIDList>.", py::arg("anIDList"));
	cls_TDF_IDFilter.def("Ignore", (void (TDF_IDFilter::*)(const Standard_GUID &)) &TDF_IDFilter::Ignore, "An attribute with <anID> as ID is to be ignored and the filter will answer false to the question IsKept(<anID>).", py::arg("anID"));
	cls_TDF_IDFilter.def("Ignore", (void (TDF_IDFilter::*)(const TDF_IDList &)) &TDF_IDFilter::Ignore, "Attributes with ID owned by <anIDList> are to be ignored and the filter will answer false to the question IsKept(<anID>) with ID from <anIDList>.", py::arg("anIDList"));
	cls_TDF_IDFilter.def("IsKept", (Standard_Boolean (TDF_IDFilter::*)(const Standard_GUID &) const ) &TDF_IDFilter::IsKept, "Returns true if the ID is to be kept.", py::arg("anID"));
	cls_TDF_IDFilter.def("IsKept", (Standard_Boolean (TDF_IDFilter::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_IDFilter::IsKept, "Returns true if the attribute is to be kept.", py::arg("anAtt"));
	cls_TDF_IDFilter.def("IsIgnored", (Standard_Boolean (TDF_IDFilter::*)(const Standard_GUID &) const ) &TDF_IDFilter::IsIgnored, "Returns true if the ID is to be ignored.", py::arg("anID"));
	cls_TDF_IDFilter.def("IsIgnored", (Standard_Boolean (TDF_IDFilter::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_IDFilter::IsIgnored, "Returns true if the attribute is to be ignored.", py::arg("anAtt"));
	cls_TDF_IDFilter.def("IDList", (void (TDF_IDFilter::*)(TDF_IDList &) const ) &TDF_IDFilter::IDList, "Copies the list of ID to be kept or ignored in <anIDList>. <anIDList> is cleared before use.", py::arg("anIDList"));
	cls_TDF_IDFilter.def("Copy", (void (TDF_IDFilter::*)(const TDF_IDFilter &)) &TDF_IDFilter::Copy, "Copies into <me> the contents of <fromFilter>. <me> is cleared before copy.", py::arg("fromFilter"));
	// FIXME cls_TDF_IDFilter.def("Dump", (void (TDF_IDFilter::*)(Standard_OStream &) const ) &TDF_IDFilter::Dump, "Writes the contents of <me> to <OS>.", py::arg("anOS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_AttributeDelta.hxx
	py::class_<TDF_AttributeDelta, opencascade::handle<TDF_AttributeDelta>, Standard_Transient> cls_TDF_AttributeDelta(mod, "TDF_AttributeDelta", "This class discribes the services we need to implement Delta and Undo/Redo services.");
	cls_TDF_AttributeDelta.def("Apply", (void (TDF_AttributeDelta::*)()) &TDF_AttributeDelta::Apply, "Applies the delta to the attribute.");
	cls_TDF_AttributeDelta.def("Label", (TDF_Label (TDF_AttributeDelta::*)() const ) &TDF_AttributeDelta::Label, "Returns the label concerned by <me>.");
	cls_TDF_AttributeDelta.def("Attribute", (opencascade::handle<TDF_Attribute> (TDF_AttributeDelta::*)() const ) &TDF_AttributeDelta::Attribute, "Returns the reference attribute.");
	cls_TDF_AttributeDelta.def("ID", (Standard_GUID (TDF_AttributeDelta::*)() const ) &TDF_AttributeDelta::ID, "Returns the ID of the attribute concerned by <me>.");
	// FIXME cls_TDF_AttributeDelta.def("Dump", (Standard_OStream & (TDF_AttributeDelta::*)(Standard_OStream &) const ) &TDF_AttributeDelta::Dump, "Dumps the contents.", py::arg("OS"));
	cls_TDF_AttributeDelta.def("operator<<", (Standard_OStream & (TDF_AttributeDelta::*)(Standard_OStream &) const ) &TDF_AttributeDelta::operator<<, "None", py::arg("OS"));
	cls_TDF_AttributeDelta.def_static("get_type_name_", (const char * (*)()) &TDF_AttributeDelta::get_type_name, "None");
	cls_TDF_AttributeDelta.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_AttributeDelta::get_type_descriptor, "None");
	cls_TDF_AttributeDelta.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_AttributeDelta::*)() const ) &TDF_AttributeDelta::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_DeltaOnForget.hxx
	py::class_<TDF_DeltaOnForget, opencascade::handle<TDF_DeltaOnForget>, TDF_AttributeDelta> cls_TDF_DeltaOnForget(mod, "TDF_DeltaOnForget", "This class provides default services for an AttributeDelta on an Forget action.");
	cls_TDF_DeltaOnForget.def(py::init<const opencascade::handle<TDF_Attribute> &>(), py::arg("anAtt"));
	cls_TDF_DeltaOnForget.def("Apply", (void (TDF_DeltaOnForget::*)()) &TDF_DeltaOnForget::Apply, "Applies the delta to the attribute.");
	cls_TDF_DeltaOnForget.def_static("get_type_name_", (const char * (*)()) &TDF_DeltaOnForget::get_type_name, "None");
	cls_TDF_DeltaOnForget.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DeltaOnForget::get_type_descriptor, "None");
	cls_TDF_DeltaOnForget.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DeltaOnForget::*)() const ) &TDF_DeltaOnForget::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_DeltaOnAddition.hxx
	py::class_<TDF_DeltaOnAddition, opencascade::handle<TDF_DeltaOnAddition>, TDF_AttributeDelta> cls_TDF_DeltaOnAddition(mod, "TDF_DeltaOnAddition", "This class provides default services for an AttributeDelta on an ADDITION action.");
	cls_TDF_DeltaOnAddition.def(py::init<const opencascade::handle<TDF_Attribute> &>(), py::arg("anAtt"));
	cls_TDF_DeltaOnAddition.def("Apply", (void (TDF_DeltaOnAddition::*)()) &TDF_DeltaOnAddition::Apply, "Applies the delta to the attribute.");
	cls_TDF_DeltaOnAddition.def_static("get_type_name_", (const char * (*)()) &TDF_DeltaOnAddition::get_type_name, "None");
	cls_TDF_DeltaOnAddition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DeltaOnAddition::get_type_descriptor, "None");
	cls_TDF_DeltaOnAddition.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DeltaOnAddition::*)() const ) &TDF_DeltaOnAddition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_DeltaOnResume.hxx
	py::class_<TDF_DeltaOnResume, opencascade::handle<TDF_DeltaOnResume>, TDF_AttributeDelta> cls_TDF_DeltaOnResume(mod, "TDF_DeltaOnResume", "This class provides default services for an AttributeDelta on an Resume action.");
	cls_TDF_DeltaOnResume.def(py::init<const opencascade::handle<TDF_Attribute> &>(), py::arg("anAtt"));
	cls_TDF_DeltaOnResume.def("Apply", (void (TDF_DeltaOnResume::*)()) &TDF_DeltaOnResume::Apply, "Applies the delta to the attribute.");
	cls_TDF_DeltaOnResume.def_static("get_type_name_", (const char * (*)()) &TDF_DeltaOnResume::get_type_name, "None");
	cls_TDF_DeltaOnResume.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DeltaOnResume::get_type_descriptor, "None");
	cls_TDF_DeltaOnResume.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DeltaOnResume::*)() const ) &TDF_DeltaOnResume::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_DeltaOnModification.hxx
	py::class_<TDF_DeltaOnModification, opencascade::handle<TDF_DeltaOnModification>, TDF_AttributeDelta> cls_TDF_DeltaOnModification(mod, "TDF_DeltaOnModification", "This class provides default services for an AttributeDelta on a MODIFICATION action.");
	cls_TDF_DeltaOnModification.def("Apply", (void (TDF_DeltaOnModification::*)()) &TDF_DeltaOnModification::Apply, "Applies the delta to the attribute.");
	cls_TDF_DeltaOnModification.def_static("get_type_name_", (const char * (*)()) &TDF_DeltaOnModification::get_type_name, "None");
	cls_TDF_DeltaOnModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DeltaOnModification::get_type_descriptor, "None");
	cls_TDF_DeltaOnModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DeltaOnModification::*)() const ) &TDF_DeltaOnModification::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_DeltaOnRemoval.hxx
	py::class_<TDF_DeltaOnRemoval, opencascade::handle<TDF_DeltaOnRemoval>, TDF_AttributeDelta> cls_TDF_DeltaOnRemoval(mod, "TDF_DeltaOnRemoval", "This class provides default services for an AttributeDelta on a REMOVAL action.");
	cls_TDF_DeltaOnRemoval.def_static("get_type_name_", (const char * (*)()) &TDF_DeltaOnRemoval::get_type_name, "None");
	cls_TDF_DeltaOnRemoval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DeltaOnRemoval::get_type_descriptor, "None");
	cls_TDF_DeltaOnRemoval.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DeltaOnRemoval::*)() const ) &TDF_DeltaOnRemoval::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_RelocationTable.hxx
	py::class_<TDF_RelocationTable, opencascade::handle<TDF_RelocationTable>, Standard_Transient> cls_TDF_RelocationTable(mod, "TDF_RelocationTable", "This is a relocation dictionnary between source and target labels, attributes or any transient(useful for copy or paste actions). Note that one target value may be the relocation value of more than one source object.");
	cls_TDF_RelocationTable.def(py::init<>());
	cls_TDF_RelocationTable.def(py::init<const Standard_Boolean>(), py::arg("selfRelocate"));
	cls_TDF_RelocationTable.def("SelfRelocate", (void (TDF_RelocationTable::*)(const Standard_Boolean)) &TDF_RelocationTable::SelfRelocate, "Sets <mySelfRelocate> to <selfRelocate>.", py::arg("selfRelocate"));
	cls_TDF_RelocationTable.def("SelfRelocate", (Standard_Boolean (TDF_RelocationTable::*)() const ) &TDF_RelocationTable::SelfRelocate, "Returns <mySelfRelocate>.");
	cls_TDF_RelocationTable.def("AfterRelocate", (void (TDF_RelocationTable::*)(const Standard_Boolean)) &TDF_RelocationTable::AfterRelocate, "None", py::arg("afterRelocate"));
	cls_TDF_RelocationTable.def("AfterRelocate", (Standard_Boolean (TDF_RelocationTable::*)() const ) &TDF_RelocationTable::AfterRelocate, "Returns <myAfterRelocate>.");
	cls_TDF_RelocationTable.def("SetRelocation", (void (TDF_RelocationTable::*)(const TDF_Label &, const TDF_Label &)) &TDF_RelocationTable::SetRelocation, "Sets the relocation value of <aSourceLabel> to <aTargetLabel>.", py::arg("aSourceLabel"), py::arg("aTargetLabel"));
	cls_TDF_RelocationTable.def("HasRelocation", (Standard_Boolean (TDF_RelocationTable::*)(const TDF_Label &, TDF_Label &) const ) &TDF_RelocationTable::HasRelocation, "Finds the relocation value of <aSourceLabel> and returns it into <aTargetLabel>.", py::arg("aSourceLabel"), py::arg("aTargetLabel"));
	cls_TDF_RelocationTable.def("SetRelocation", (void (TDF_RelocationTable::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_Attribute> &)) &TDF_RelocationTable::SetRelocation, "Sets the relocation value of <aSourceAttribute> to <aTargetAttribute>.", py::arg("aSourceAttribute"), py::arg("aTargetAttribute"));
	cls_TDF_RelocationTable.def("HasRelocation", (Standard_Boolean (TDF_RelocationTable::*)(const opencascade::handle<TDF_Attribute> &, opencascade::handle<TDF_Attribute> &) const ) &TDF_RelocationTable::HasRelocation, "Finds the relocation value of <aSourceAttribute> and returns it into <aTargetAttribute>.", py::arg("aSourceAttribute"), py::arg("aTargetAttribute"));
	cls_TDF_RelocationTable.def("SetTransientRelocation", (void (TDF_RelocationTable::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &TDF_RelocationTable::SetTransientRelocation, "Sets the relocation value of <aSourceTransient> to <aTargetTransient>.", py::arg("aSourceTransient"), py::arg("aTargetTransient"));
	cls_TDF_RelocationTable.def("HasTransientRelocation", (Standard_Boolean (TDF_RelocationTable::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const ) &TDF_RelocationTable::HasTransientRelocation, "Finds the relocation value of <aSourceTransient> and returns it into <aTargetTransient>.", py::arg("aSourceTransient"), py::arg("aTargetTransient"));
	cls_TDF_RelocationTable.def("Clear", (void (TDF_RelocationTable::*)()) &TDF_RelocationTable::Clear, "Clears the relocation dictionnary, but lets the self relocation flag to its current value.");
	cls_TDF_RelocationTable.def("TargetLabelMap", (void (TDF_RelocationTable::*)(TDF_LabelMap &) const ) &TDF_RelocationTable::TargetLabelMap, "Fills <aLabelMap> with target relocation labels. <aLabelMap> is not cleared before use.", py::arg("aLabelMap"));
	cls_TDF_RelocationTable.def("TargetAttributeMap", (void (TDF_RelocationTable::*)(TDF_AttributeMap &) const ) &TDF_RelocationTable::TargetAttributeMap, "Fills <anAttributeMap> with target relocation attributes. <anAttributeMap> is not cleared before use.", py::arg("anAttributeMap"));
	cls_TDF_RelocationTable.def("LabelTable", (TDF_LabelDataMap & (TDF_RelocationTable::*)()) &TDF_RelocationTable::LabelTable, "Returns <myLabelTable> to be used or updated.");
	cls_TDF_RelocationTable.def("AttributeTable", (TDF_AttributeDataMap & (TDF_RelocationTable::*)()) &TDF_RelocationTable::AttributeTable, "Returns <myAttributeTable> to be used or updated.");
	cls_TDF_RelocationTable.def("TransientTable", (TColStd_IndexedDataMapOfTransientTransient & (TDF_RelocationTable::*)()) &TDF_RelocationTable::TransientTable, "Returns <myTransientTable> to be used or updated.");
	// FIXME cls_TDF_RelocationTable.def("Dump", (Standard_OStream & (TDF_RelocationTable::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, Standard_OStream &) const ) &TDF_RelocationTable::Dump, "Dumps the relocation table.", py::arg("dumpLabels"), py::arg("dumpAttributes"), py::arg("dumpTransients"), py::arg("anOS"));
	cls_TDF_RelocationTable.def_static("get_type_name_", (const char * (*)()) &TDF_RelocationTable::get_type_name, "None");
	cls_TDF_RelocationTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_RelocationTable::get_type_descriptor, "None");
	cls_TDF_RelocationTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_RelocationTable::*)() const ) &TDF_RelocationTable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_DataSet.hxx
	py::class_<TDF_DataSet, opencascade::handle<TDF_DataSet>, Standard_Transient> cls_TDF_DataSet(mod, "TDF_DataSet", "This class is a set of TDF informations like labels and attributes.");
	cls_TDF_DataSet.def(py::init<>());
	cls_TDF_DataSet.def("Clear", (void (TDF_DataSet::*)()) &TDF_DataSet::Clear, "Clears all information.");
	cls_TDF_DataSet.def("IsEmpty", (Standard_Boolean (TDF_DataSet::*)() const ) &TDF_DataSet::IsEmpty, "Returns true if there is at least one label or one attribute.");
	cls_TDF_DataSet.def("AddLabel", (void (TDF_DataSet::*)(const TDF_Label &)) &TDF_DataSet::AddLabel, "Adds <aLabel> in the current data set.", py::arg("aLabel"));
	cls_TDF_DataSet.def("ContainsLabel", (Standard_Boolean (TDF_DataSet::*)(const TDF_Label &) const ) &TDF_DataSet::ContainsLabel, "Returns true if the label <alabel> is in the data set.", py::arg("aLabel"));
	cls_TDF_DataSet.def("Labels", (TDF_LabelMap & (TDF_DataSet::*)()) &TDF_DataSet::Labels, "Returns the map of labels in this data set. This map can be used directly, or updated.");
	cls_TDF_DataSet.def("AddAttribute", (void (TDF_DataSet::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_DataSet::AddAttribute, "Adds <anAttribute> into the current data set.", py::arg("anAttribute"));
	cls_TDF_DataSet.def("ContainsAttribute", (Standard_Boolean (TDF_DataSet::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_DataSet::ContainsAttribute, "Returns true if <anAttribute> is in the data set.", py::arg("anAttribute"));
	cls_TDF_DataSet.def("Attributes", (TDF_AttributeMap & (TDF_DataSet::*)()) &TDF_DataSet::Attributes, "Returns the map of attributes in the current data set. This map can be used directly, or updated.");
	cls_TDF_DataSet.def("AddRoot", (void (TDF_DataSet::*)(const TDF_Label &)) &TDF_DataSet::AddRoot, "Adds a root label to <myRootLabels>.", py::arg("aLabel"));
	cls_TDF_DataSet.def("Roots", (TDF_LabelList & (TDF_DataSet::*)()) &TDF_DataSet::Roots, "Returns <myRootLabels> to be used or updated.");
	// FIXME cls_TDF_DataSet.def("Dump", (Standard_OStream & (TDF_DataSet::*)(Standard_OStream &) const ) &TDF_DataSet::Dump, "Dumps the minimum information about <me> on <aStream>.", py::arg("anOS"));
	cls_TDF_DataSet.def("operator<<", (Standard_OStream & (TDF_DataSet::*)(Standard_OStream &) const ) &TDF_DataSet::operator<<, "None", py::arg("anOS"));
	cls_TDF_DataSet.def_static("get_type_name_", (const char * (*)()) &TDF_DataSet::get_type_name, "None");
	cls_TDF_DataSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DataSet::get_type_descriptor, "None");
	cls_TDF_DataSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DataSet::*)() const ) &TDF_DataSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_TagSource.hxx
	py::class_<TDF_TagSource, opencascade::handle<TDF_TagSource>, TDF_Attribute> cls_TDF_TagSource(mod, "TDF_TagSource", "This attribute manage a tag provider to create child labels of a given one.");
	cls_TDF_TagSource.def(py::init<>());
	cls_TDF_TagSource.def_static("GetID_", (const Standard_GUID & (*)()) &TDF_TagSource::GetID, "class methods =============");
	cls_TDF_TagSource.def_static("Set_", (opencascade::handle<TDF_TagSource> (*)(const TDF_Label &)) &TDF_TagSource::Set, "Find, or create, a TagSource attribute. the TagSource attribute is returned.", py::arg("label"));
	cls_TDF_TagSource.def_static("NewChild_", (TDF_Label (*)(const TDF_Label &)) &TDF_TagSource::NewChild, "Find (or create) a tagSource attribute located at <L> and make a new child label. TagSource methods =================", py::arg("L"));
	cls_TDF_TagSource.def("NewTag", (Standard_Integer (TDF_TagSource::*)()) &TDF_TagSource::NewTag, "None");
	cls_TDF_TagSource.def("NewChild", (TDF_Label (TDF_TagSource::*)()) &TDF_TagSource::NewChild, "None");
	cls_TDF_TagSource.def("Get", (Standard_Integer (TDF_TagSource::*)() const ) &TDF_TagSource::Get, "None");
	cls_TDF_TagSource.def("Set", (void (TDF_TagSource::*)(const Standard_Integer)) &TDF_TagSource::Set, "TDF_Attribute methods =====================", py::arg("T"));
	cls_TDF_TagSource.def("ID", (const Standard_GUID & (TDF_TagSource::*)() const ) &TDF_TagSource::ID, "None");
	cls_TDF_TagSource.def("Restore", (void (TDF_TagSource::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_TagSource::Restore, "None", py::arg("with"));
	cls_TDF_TagSource.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDF_TagSource::*)() const ) &TDF_TagSource::NewEmpty, "None");
	cls_TDF_TagSource.def("Paste", (void (TDF_TagSource::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TDF_TagSource::Paste, "None", py::arg("Into"), py::arg("RT"));
	cls_TDF_TagSource.def_static("get_type_name_", (const char * (*)()) &TDF_TagSource::get_type_name, "None");
	cls_TDF_TagSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_TagSource::get_type_descriptor, "None");
	cls_TDF_TagSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_TagSource::*)() const ) &TDF_TagSource::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_Transaction.hxx
	py::class_<TDF_Transaction, std::unique_ptr<TDF_Transaction, Deleter<TDF_Transaction>>> cls_TDF_Transaction(mod, "TDF_Transaction", "This class offers services to open, commit or abort a transaction in a more secure way than using Data from TDF. If you forget to close a transaction, it will be automaticaly aborted at the destruction of this object, at the closure of its scope.");
	cls_TDF_Transaction.def(py::init<>());
	cls_TDF_Transaction.def(py::init<const TCollection_AsciiString &>(), py::arg("aName"));
	cls_TDF_Transaction.def(py::init<const opencascade::handle<TDF_Data> &>(), py::arg("aDF"));
	cls_TDF_Transaction.def(py::init<const opencascade::handle<TDF_Data> &, const TCollection_AsciiString &>(), py::arg("aDF"), py::arg("aName"));
	cls_TDF_Transaction.def("Initialize", (void (TDF_Transaction::*)(const opencascade::handle<TDF_Data> &)) &TDF_Transaction::Initialize, "Aborts all the transactions on <myDF> and sets <aDF> to build a transaction context on <aDF>, ready to be opened.", py::arg("aDF"));
	cls_TDF_Transaction.def("Open", (Standard_Integer (TDF_Transaction::*)()) &TDF_Transaction::Open, "If not yet done, opens a new transaction on <myDF>. Returns the index of the just opened transaction.");
	cls_TDF_Transaction.def("Commit", [](TDF_Transaction &self) -> opencascade::handle<TDF_Delta> { return self.Commit(); });
	cls_TDF_Transaction.def("Commit", (opencascade::handle<TDF_Delta> (TDF_Transaction::*)(const Standard_Boolean)) &TDF_Transaction::Commit, "Commits the transactions until AND including the current opened one.", py::arg("withDelta"));
	cls_TDF_Transaction.def("Abort", (void (TDF_Transaction::*)()) &TDF_Transaction::Abort, "Aborts the transactions until AND including the current opened one.");
	cls_TDF_Transaction.def("Data", (opencascade::handle<TDF_Data> (TDF_Transaction::*)() const ) &TDF_Transaction::Data, "Returns the Data from TDF.");
	cls_TDF_Transaction.def("Transaction", (Standard_Integer (TDF_Transaction::*)() const ) &TDF_Transaction::Transaction, "Returns the number of the transaction opened by <me>.");
	cls_TDF_Transaction.def("Name", (const TCollection_AsciiString & (TDF_Transaction::*)() const ) &TDF_Transaction::Name, "Returns the transaction name.");
	cls_TDF_Transaction.def("IsOpen", (Standard_Boolean (TDF_Transaction::*)() const ) &TDF_Transaction::IsOpen, "Returns true if the transaction is open.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_Delta.hxx
	py::class_<TDF_Delta, opencascade::handle<TDF_Delta>, Standard_Transient> cls_TDF_Delta(mod, "TDF_Delta", "A set of AttributeDelta for a given transaction number and reference time number. A delta set is available at <aSourceTime>. If applied, it restores the TDF_Data in the state it was at <aTargetTime>.");
	cls_TDF_Delta.def(py::init<>());
	cls_TDF_Delta.def("IsEmpty", (Standard_Boolean (TDF_Delta::*)() const ) &TDF_Delta::IsEmpty, "Returns true if there is nothing to undo.");
	cls_TDF_Delta.def("IsApplicable", (Standard_Boolean (TDF_Delta::*)(const Standard_Integer) const ) &TDF_Delta::IsApplicable, "Returns true if the Undo action of <me> is applicable at <aCurrentTime>.", py::arg("aCurrentTime"));
	cls_TDF_Delta.def("BeginTime", (Standard_Integer (TDF_Delta::*)() const ) &TDF_Delta::BeginTime, "Returns the field <myBeginTime>.");
	cls_TDF_Delta.def("EndTime", (Standard_Integer (TDF_Delta::*)() const ) &TDF_Delta::EndTime, "Returns the field <myEndTime>.");
	cls_TDF_Delta.def("Labels", (void (TDF_Delta::*)(TDF_LabelList &) const ) &TDF_Delta::Labels, "Adds in <aLabelList> the labels of the attribute deltas. Caution: <aLabelList> is not cleared before use.", py::arg("aLabelList"));
	cls_TDF_Delta.def("AttributeDeltas", (const TDF_AttributeDeltaList & (TDF_Delta::*)() const ) &TDF_Delta::AttributeDeltas, "Returns the field <myAttDeltaList>.");
	cls_TDF_Delta.def("Name", (TCollection_ExtendedString (TDF_Delta::*)() const ) &TDF_Delta::Name, "Returns a name associated with this delta.");
	cls_TDF_Delta.def("SetName", (void (TDF_Delta::*)(const TCollection_ExtendedString &)) &TDF_Delta::SetName, "Associates a name <theName> with this delta", py::arg("theName"));
	// FIXME cls_TDF_Delta.def("Dump", (void (TDF_Delta::*)(Standard_OStream &) const ) &TDF_Delta::Dump, "None", py::arg("OS"));
	cls_TDF_Delta.def_static("get_type_name_", (const char * (*)()) &TDF_Delta::get_type_name, "None");
	cls_TDF_Delta.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_Delta::get_type_descriptor, "None");
	cls_TDF_Delta.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_Delta::*)() const ) &TDF_Delta::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_Reference.hxx
	py::class_<TDF_Reference, opencascade::handle<TDF_Reference>, TDF_Attribute> cls_TDF_Reference(mod, "TDF_Reference", "This attribute is used to store in the framework a reference to an other label.");
	cls_TDF_Reference.def(py::init<>());
	cls_TDF_Reference.def_static("GetID_", (const Standard_GUID & (*)()) &TDF_Reference::GetID, "None");
	cls_TDF_Reference.def_static("Set_", (opencascade::handle<TDF_Reference> (*)(const TDF_Label &, const TDF_Label &)) &TDF_Reference::Set, "None", py::arg("I"), py::arg("Origin"));
	cls_TDF_Reference.def("Set", (void (TDF_Reference::*)(const TDF_Label &)) &TDF_Reference::Set, "None", py::arg("Origin"));
	cls_TDF_Reference.def("Get", (TDF_Label (TDF_Reference::*)() const ) &TDF_Reference::Get, "None");
	cls_TDF_Reference.def("ID", (const Standard_GUID & (TDF_Reference::*)() const ) &TDF_Reference::ID, "None");
	cls_TDF_Reference.def("Restore", (void (TDF_Reference::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_Reference::Restore, "None", py::arg("With"));
	cls_TDF_Reference.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDF_Reference::*)() const ) &TDF_Reference::NewEmpty, "None");
	cls_TDF_Reference.def("Paste", (void (TDF_Reference::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TDF_Reference::Paste, "None", py::arg("Into"), py::arg("RT"));
	cls_TDF_Reference.def("References", (void (TDF_Reference::*)(const opencascade::handle<TDF_DataSet> &) const ) &TDF_Reference::References, "None", py::arg("DS"));
	// FIXME cls_TDF_Reference.def("Dump", (Standard_OStream & (TDF_Reference::*)(Standard_OStream &) const ) &TDF_Reference::Dump, "None", py::arg("anOS"));
	cls_TDF_Reference.def_static("get_type_name_", (const char * (*)()) &TDF_Reference::get_type_name, "None");
	cls_TDF_Reference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_Reference::get_type_descriptor, "None");
	cls_TDF_Reference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_Reference::*)() const ) &TDF_Reference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_ClosureMode.hxx
	py::class_<TDF_ClosureMode, std::unique_ptr<TDF_ClosureMode, Deleter<TDF_ClosureMode>>> cls_TDF_ClosureMode(mod, "TDF_ClosureMode", "This class provides options closure management.");
	cls_TDF_ClosureMode.def(py::init<>());
	cls_TDF_ClosureMode.def(py::init<const Standard_Boolean>(), py::arg("aMode"));
	cls_TDF_ClosureMode.def("Descendants", (void (TDF_ClosureMode::*)(const Standard_Boolean)) &TDF_ClosureMode::Descendants, "Sets the mode 'Descendants' to <aStatus>.", py::arg("aStatus"));
	cls_TDF_ClosureMode.def("Descendants", (Standard_Boolean (TDF_ClosureMode::*)() const ) &TDF_ClosureMode::Descendants, "Returns true if the mode 'Descendants' is set.");
	cls_TDF_ClosureMode.def("References", (void (TDF_ClosureMode::*)(const Standard_Boolean)) &TDF_ClosureMode::References, "Sets the mode 'References' to <aStatus>.", py::arg("aStatus"));
	cls_TDF_ClosureMode.def("References", (Standard_Boolean (TDF_ClosureMode::*)() const ) &TDF_ClosureMode::References, "Returns true if the mode 'References' is set.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_ClosureTool.hxx
	py::class_<TDF_ClosureTool, std::unique_ptr<TDF_ClosureTool, Deleter<TDF_ClosureTool>>> cls_TDF_ClosureTool(mod, "TDF_ClosureTool", "This class provides services to build the closure of an information set. This class gives services around the transitive enclosure of a set of information, starting from a list of label. You can set closure options by using IDFilter (to select or exclude specific attribute IDs) and CopyOption objects and by giving to Closure method.");
	cls_TDF_ClosureTool.def(py::init<>());
	cls_TDF_ClosureTool.def_static("Closure_", (void (*)(const opencascade::handle<TDF_DataSet> &)) &TDF_ClosureTool::Closure, "Builds the transitive closure of label and attribute sets into <aDataSet>.", py::arg("aDataSet"));
	cls_TDF_ClosureTool.def_static("Closure_", (void (*)(const opencascade::handle<TDF_DataSet> &, const TDF_IDFilter &, const TDF_ClosureMode &)) &TDF_ClosureTool::Closure, "Builds the transitive closure of label and attribute sets into <aDataSet>. Uses <aFilter> to determine if an attribute has to be taken in account or not. Uses <aMode> for various way of closing.", py::arg("aDataSet"), py::arg("aFilter"), py::arg("aMode"));
	cls_TDF_ClosureTool.def_static("Closure_", (void (*)(const TDF_Label &, TDF_LabelMap &, TDF_AttributeMap &, const TDF_IDFilter &, const TDF_ClosureMode &)) &TDF_ClosureTool::Closure, "Builds the transitive closure of <aLabel>.", py::arg("aLabel"), py::arg("aLabMap"), py::arg("anAttMap"), py::arg("aFilter"), py::arg("aMode"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_CopyTool.hxx
	py::class_<TDF_CopyTool, std::unique_ptr<TDF_CopyTool, Deleter<TDF_CopyTool>>> cls_TDF_CopyTool(mod, "TDF_CopyTool", "This class provides services to build, copy or paste a set of information.");
	cls_TDF_CopyTool.def(py::init<>());
	cls_TDF_CopyTool.def_static("Copy_", (void (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &)) &TDF_CopyTool::Copy, "Copy <aSourceDataSet> with using and updating <aRelocationTable>. This method ignores target attributes privilege over source ones.", py::arg("aSourceDataSet"), py::arg("aRelocationTable"));
	cls_TDF_CopyTool.def_static("Copy_", (void (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &, const TDF_IDFilter &)) &TDF_CopyTool::Copy, "Copy <aSourceDataSet> using and updating <aRelocationTable>. Use <aPrivilegeFilter> to give a list of IDs for which the target attribute prevails over the source one.", py::arg("aSourceDataSet"), py::arg("aRelocationTable"), py::arg("aPrivilegeFilter"));
	cls_TDF_CopyTool.def_static("Copy_", (void (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &, const TDF_IDFilter &, const TDF_IDFilter &, const Standard_Boolean)) &TDF_CopyTool::Copy, "Copy <aSourceDataSet> using and updating <aRelocationTable>. Use <aPrivilegeFilter> to give a list of IDs for which the target attribute prevails over the source one. If <setSelfContained> is set to true, every TDF_Reference will be replaced by the referenced structure according to <aRefFilter>.", py::arg("aSourceDataSet"), py::arg("aRelocationTable"), py::arg("aPrivilegeFilter"), py::arg("aRefFilter"), py::arg("setSelfContained"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_CopyLabel.hxx
	py::class_<TDF_CopyLabel, std::unique_ptr<TDF_CopyLabel, Deleter<TDF_CopyLabel>>> cls_TDF_CopyLabel(mod, "TDF_CopyLabel", "This class gives copy of source label hierarchy");
	cls_TDF_CopyLabel.def(py::init<>());
	cls_TDF_CopyLabel.def(py::init<const TDF_Label &, const TDF_Label &>(), py::arg("aSource"), py::arg("aTarget"));
	cls_TDF_CopyLabel.def("Load", (void (TDF_CopyLabel::*)(const TDF_Label &, const TDF_Label &)) &TDF_CopyLabel::Load, "Loads src and tgt labels", py::arg("aSource"), py::arg("aTarget"));
	cls_TDF_CopyLabel.def("UseFilter", (void (TDF_CopyLabel::*)(const TDF_IDFilter &)) &TDF_CopyLabel::UseFilter, "Sets filter", py::arg("aFilter"));
	cls_TDF_CopyLabel.def_static("ExternalReferences_", (Standard_Boolean (*)(const TDF_Label &, TDF_AttributeMap &, const TDF_IDFilter &)) &TDF_CopyLabel::ExternalReferences, "Check external references and if exist fills the aExternals Map", py::arg("Lab"), py::arg("aExternals"), py::arg("aFilter"));
	cls_TDF_CopyLabel.def_static("ExternalReferences_", (void (*)(const TDF_Label &, const TDF_Label &, TDF_AttributeMap &, const TDF_IDFilter &, opencascade::handle<TDF_DataSet> &)) &TDF_CopyLabel::ExternalReferences, "Check external references and if exist fills the aExternals Map", py::arg("aRefLab"), py::arg("Lab"), py::arg("aExternals"), py::arg("aFilter"), py::arg("aDataSet"));
	cls_TDF_CopyLabel.def("Perform", (void (TDF_CopyLabel::*)()) &TDF_CopyLabel::Perform, "performs algorithm of selfcontained copy");
	cls_TDF_CopyLabel.def("IsDone", (Standard_Boolean (TDF_CopyLabel::*)() const ) &TDF_CopyLabel::IsDone, "None");
	cls_TDF_CopyLabel.def("RelocationTable", (const opencascade::handle<TDF_RelocationTable> & (TDF_CopyLabel::*)() const ) &TDF_CopyLabel::RelocationTable, "returns relocation table");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_ComparisonTool.hxx
	py::class_<TDF_ComparisonTool, std::unique_ptr<TDF_ComparisonTool, Deleter<TDF_ComparisonTool>>> cls_TDF_ComparisonTool(mod, "TDF_ComparisonTool", "This class provides services to compare sets of information. The use of this tool can works after a copy, acted by a CopyTool.");
	cls_TDF_ComparisonTool.def(py::init<>());
	cls_TDF_ComparisonTool.def_static("Compare_", (void (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_DataSet> &, const TDF_IDFilter &, const opencascade::handle<TDF_RelocationTable> &)) &TDF_ComparisonTool::Compare, "Compares <aSourceDataSet> with <aTargetDataSet>, updating <aRelocationTable> with labels and attributes found in both sets.", py::arg("aSourceDataSet"), py::arg("aTargetDataSet"), py::arg("aFilter"), py::arg("aRelocationTable"));
	cls_TDF_ComparisonTool.def_static("SourceUnbound_", [](const opencascade::handle<TDF_DataSet> & a0, const opencascade::handle<TDF_RelocationTable> & a1, const TDF_IDFilter & a2, const opencascade::handle<TDF_DataSet> & a3) -> Standard_Boolean { return TDF_ComparisonTool::SourceUnbound(a0, a1, a2, a3); }, py::arg("aRefDataSet"), py::arg("aRelocationTable"), py::arg("aFilter"), py::arg("aDiffDataSet"));
	cls_TDF_ComparisonTool.def_static("SourceUnbound_", (Standard_Boolean (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &, const TDF_IDFilter &, const opencascade::handle<TDF_DataSet> &, const Standard_Integer)) &TDF_ComparisonTool::SourceUnbound, "Finds from <aRefDataSet> all the keys not bound into <aRelocationTable> and put them into <aDiffDataSet>. Returns True if the difference contains at least one key. (A key is a source object).", py::arg("aRefDataSet"), py::arg("aRelocationTable"), py::arg("aFilter"), py::arg("aDiffDataSet"), py::arg("anOption"));
	cls_TDF_ComparisonTool.def_static("TargetUnbound_", [](const opencascade::handle<TDF_DataSet> & a0, const opencascade::handle<TDF_RelocationTable> & a1, const TDF_IDFilter & a2, const opencascade::handle<TDF_DataSet> & a3) -> Standard_Boolean { return TDF_ComparisonTool::TargetUnbound(a0, a1, a2, a3); }, py::arg("aRefDataSet"), py::arg("aRelocationTable"), py::arg("aFilter"), py::arg("aDiffDataSet"));
	cls_TDF_ComparisonTool.def_static("TargetUnbound_", (Standard_Boolean (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &, const TDF_IDFilter &, const opencascade::handle<TDF_DataSet> &, const Standard_Integer)) &TDF_ComparisonTool::TargetUnbound, "Substracts from <aRefDataSet> all the items bound into <aRelocationTable>. The result is put into <aDiffDataSet>. Returns True if the difference contains at least one item. (An item is a target object).", py::arg("aRefDataSet"), py::arg("aRelocationTable"), py::arg("aFilter"), py::arg("aDiffDataSet"), py::arg("anOption"));
	cls_TDF_ComparisonTool.def_static("Cut_", (void (*)(const opencascade::handle<TDF_DataSet> &)) &TDF_ComparisonTool::Cut, "Removes attributes from <aDataSet>.", py::arg("aDataSet"));
	cls_TDF_ComparisonTool.def_static("IsSelfContained_", (Standard_Boolean (*)(const TDF_Label &, const opencascade::handle<TDF_DataSet> &)) &TDF_ComparisonTool::IsSelfContained, "Returns true if all the labels of <aDataSet> are descendant of <aLabel>.", py::arg("aLabel"), py::arg("aDataSet"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_DefaultDeltaOnRemoval.hxx
	py::class_<TDF_DefaultDeltaOnRemoval, opencascade::handle<TDF_DefaultDeltaOnRemoval>, TDF_DeltaOnRemoval> cls_TDF_DefaultDeltaOnRemoval(mod, "TDF_DefaultDeltaOnRemoval", "This class provides a default implementation of a TDF_DeltaOnRemoval.");
	cls_TDF_DefaultDeltaOnRemoval.def(py::init<const opencascade::handle<TDF_Attribute> &>(), py::arg("anAttribute"));
	cls_TDF_DefaultDeltaOnRemoval.def("Apply", (void (TDF_DefaultDeltaOnRemoval::*)()) &TDF_DefaultDeltaOnRemoval::Apply, "Applies the delta to the attribute.");
	cls_TDF_DefaultDeltaOnRemoval.def_static("get_type_name_", (const char * (*)()) &TDF_DefaultDeltaOnRemoval::get_type_name, "None");
	cls_TDF_DefaultDeltaOnRemoval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DefaultDeltaOnRemoval::get_type_descriptor, "None");
	cls_TDF_DefaultDeltaOnRemoval.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DefaultDeltaOnRemoval::*)() const ) &TDF_DefaultDeltaOnRemoval::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_DefaultDeltaOnModification.hxx
	py::class_<TDF_DefaultDeltaOnModification, opencascade::handle<TDF_DefaultDeltaOnModification>, TDF_DeltaOnModification> cls_TDF_DefaultDeltaOnModification(mod, "TDF_DefaultDeltaOnModification", "This class provides a default implementation of a TDF_DeltaOnModification.");
	cls_TDF_DefaultDeltaOnModification.def(py::init<const opencascade::handle<TDF_Attribute> &>(), py::arg("anAttribute"));
	cls_TDF_DefaultDeltaOnModification.def("Apply", (void (TDF_DefaultDeltaOnModification::*)()) &TDF_DefaultDeltaOnModification::Apply, "Applies the delta to the attribute.");
	cls_TDF_DefaultDeltaOnModification.def_static("get_type_name_", (const char * (*)()) &TDF_DefaultDeltaOnModification::get_type_name, "None");
	cls_TDF_DefaultDeltaOnModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DefaultDeltaOnModification::get_type_descriptor, "None");
	cls_TDF_DefaultDeltaOnModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DefaultDeltaOnModification::*)() const ) &TDF_DefaultDeltaOnModification::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_ChildIDIterator.hxx
	py::class_<TDF_ChildIDIterator, std::unique_ptr<TDF_ChildIDIterator, Deleter<TDF_ChildIDIterator>>> cls_TDF_ChildIDIterator(mod, "TDF_ChildIDIterator", "Iterates on the children of a label, to find attributes having ID as Attribute ID.");
	cls_TDF_ChildIDIterator.def(py::init<>());
	cls_TDF_ChildIDIterator.def(py::init<const TDF_Label &, const Standard_GUID &>(), py::arg("aLabel"), py::arg("anID"));
	cls_TDF_ChildIDIterator.def(py::init<const TDF_Label &, const Standard_GUID &, const Standard_Boolean>(), py::arg("aLabel"), py::arg("anID"), py::arg("allLevels"));
	cls_TDF_ChildIDIterator.def("Initialize", [](TDF_ChildIDIterator &self, const TDF_Label & a0, const Standard_GUID & a1) -> void { return self.Initialize(a0, a1); }, py::arg("aLabel"), py::arg("anID"));
	cls_TDF_ChildIDIterator.def("Initialize", (void (TDF_ChildIDIterator::*)(const TDF_Label &, const Standard_GUID &, const Standard_Boolean)) &TDF_ChildIDIterator::Initialize, "Initializes the iteration on the children of the given label. If <allLevels> option is set to true, it explores not only the first, but all the sub label levels.", py::arg("aLabel"), py::arg("anID"), py::arg("allLevels"));
	cls_TDF_ChildIDIterator.def("More", (Standard_Boolean (TDF_ChildIDIterator::*)() const ) &TDF_ChildIDIterator::More, "Returns True if there is a current Item in the iteration.");
	cls_TDF_ChildIDIterator.def("Next", (void (TDF_ChildIDIterator::*)()) &TDF_ChildIDIterator::Next, "Move to the next Item");
	cls_TDF_ChildIDIterator.def("NextBrother", (void (TDF_ChildIDIterator::*)()) &TDF_ChildIDIterator::NextBrother, "Move to the next Brother. If there is none, go up etc. This method is interesting only with 'allLevels' behavior, because it avoids to explore the current label children.");
	cls_TDF_ChildIDIterator.def("Value", (opencascade::handle<TDF_Attribute> (TDF_ChildIDIterator::*)() const ) &TDF_ChildIDIterator::Value, "Returns the current item; a null handle if there is none.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_Tool.hxx
	py::class_<TDF_Tool, std::unique_ptr<TDF_Tool, Deleter<TDF_Tool>>> cls_TDF_Tool(mod, "TDF_Tool", "This class provides general services for a data framework.");
	cls_TDF_Tool.def(py::init<>());
	cls_TDF_Tool.def_static("NbLabels_", (Standard_Integer (*)(const TDF_Label &)) &TDF_Tool::NbLabels, "Returns the number of labels of the tree, including <aLabel>. aLabel is also included in this figure. This information is useful in setting the size of an array.", py::arg("aLabel"));
	cls_TDF_Tool.def_static("NbAttributes_", (Standard_Integer (*)(const TDF_Label &)) &TDF_Tool::NbAttributes, "Returns the total number of attributes attached to the labels dependent on the label aLabel. The attributes of aLabel are also included in this figure. This information is useful in setting the size of an array.", py::arg("aLabel"));
	cls_TDF_Tool.def_static("NbAttributes_", (Standard_Integer (*)(const TDF_Label &, const TDF_IDFilter &)) &TDF_Tool::NbAttributes, "Returns the number of attributes of the tree, selected by a<Filter>, including those of <aLabel>.", py::arg("aLabel"), py::arg("aFilter"));
	cls_TDF_Tool.def_static("IsSelfContained_", (Standard_Boolean (*)(const TDF_Label &)) &TDF_Tool::IsSelfContained, "Returns true if <aLabel> and its descendants reference only attributes or labels attached to themselves.", py::arg("aLabel"));
	cls_TDF_Tool.def_static("IsSelfContained_", (Standard_Boolean (*)(const TDF_Label &, const TDF_IDFilter &)) &TDF_Tool::IsSelfContained, "Returns true if <aLabel> and its descendants reference only attributes or labels attached to themselves and kept by <aFilter>.", py::arg("aLabel"), py::arg("aFilter"));
	cls_TDF_Tool.def_static("OutReferers_", (void (*)(const TDF_Label &, TDF_AttributeMap &)) &TDF_Tool::OutReferers, "Returns in <theAtts> the attributes having out references.", py::arg("theLabel"), py::arg("theAtts"));
	cls_TDF_Tool.def_static("OutReferers_", (void (*)(const TDF_Label &, const TDF_IDFilter &, const TDF_IDFilter &, TDF_AttributeMap &)) &TDF_Tool::OutReferers, "Returns in <atts> the attributes having out references and kept by <aFilterForReferers>. It considers only the references kept by <aFilterForReferences>. Caution: <atts> is not cleared before use!", py::arg("aLabel"), py::arg("aFilterForReferers"), py::arg("aFilterForReferences"), py::arg("atts"));
	cls_TDF_Tool.def_static("OutReferences_", (void (*)(const TDF_Label &, TDF_AttributeMap &)) &TDF_Tool::OutReferences, "Returns in <atts> the referenced attributes. Caution: <atts> is not cleared before use!", py::arg("aLabel"), py::arg("atts"));
	cls_TDF_Tool.def_static("OutReferences_", (void (*)(const TDF_Label &, const TDF_IDFilter &, const TDF_IDFilter &, TDF_AttributeMap &)) &TDF_Tool::OutReferences, "Returns in <atts> the referenced attributes and kept by <aFilterForReferences>. It considers only the referers kept by <aFilterForReferers>. Caution: <atts> is not cleared before use!", py::arg("aLabel"), py::arg("aFilterForReferers"), py::arg("aFilterForReferences"), py::arg("atts"));
	cls_TDF_Tool.def_static("RelocateLabel_", [](const TDF_Label & a0, const TDF_Label & a1, const TDF_Label & a2, TDF_Label & a3) -> void { return TDF_Tool::RelocateLabel(a0, a1, a2, a3); }, py::arg("aSourceLabel"), py::arg("fromRoot"), py::arg("toRoot"), py::arg("aTargetLabel"));
	cls_TDF_Tool.def_static("RelocateLabel_", (void (*)(const TDF_Label &, const TDF_Label &, const TDF_Label &, TDF_Label &, const Standard_Boolean)) &TDF_Tool::RelocateLabel, "Returns the label having the same sub-entry as <aLabel> but located as descendant as <toRoot> instead of <fromRoot>.", py::arg("aSourceLabel"), py::arg("fromRoot"), py::arg("toRoot"), py::arg("aTargetLabel"), py::arg("create"));
	cls_TDF_Tool.def_static("Entry_", (void (*)(const TDF_Label &, TCollection_AsciiString &)) &TDF_Tool::Entry, "Returns the entry for the label aLabel in the form of the ASCII character string anEntry containing the tag list for aLabel.", py::arg("aLabel"), py::arg("anEntry"));
	cls_TDF_Tool.def_static("TagList_", (void (*)(const TDF_Label &, TColStd_ListOfInteger &)) &TDF_Tool::TagList, "Returns the entry of <aLabel> as list of integers in <aTagList>.", py::arg("aLabel"), py::arg("aTagList"));
	cls_TDF_Tool.def_static("TagList_", (void (*)(const TCollection_AsciiString &, TColStd_ListOfInteger &)) &TDF_Tool::TagList, "Returns the entry expressed by <anEntry> as list of integers in <aTagList>.", py::arg("anEntry"), py::arg("aTagList"));
	cls_TDF_Tool.def_static("Label_", [](const opencascade::handle<TDF_Data> & a0, const TCollection_AsciiString & a1, TDF_Label & a2) -> void { return TDF_Tool::Label(a0, a1, a2); }, py::arg("aDF"), py::arg("anEntry"), py::arg("aLabel"));
	cls_TDF_Tool.def_static("Label_", (void (*)(const opencascade::handle<TDF_Data> &, const TCollection_AsciiString &, TDF_Label &, const Standard_Boolean)) &TDF_Tool::Label, "Returns the label expressed by <anEntry>; creates the label if it does not exist and if <create> is true.", py::arg("aDF"), py::arg("anEntry"), py::arg("aLabel"), py::arg("create"));
	cls_TDF_Tool.def_static("Label_", [](const opencascade::handle<TDF_Data> & a0, const Standard_CString a1, TDF_Label & a2) -> void { return TDF_Tool::Label(a0, a1, a2); }, py::arg("aDF"), py::arg("anEntry"), py::arg("aLabel"));
	cls_TDF_Tool.def_static("Label_", (void (*)(const opencascade::handle<TDF_Data> &, const Standard_CString, TDF_Label &, const Standard_Boolean)) &TDF_Tool::Label, "Returns the label expressed by <anEntry>; creates the label if it does not exist and if <create> is true.", py::arg("aDF"), py::arg("anEntry"), py::arg("aLabel"), py::arg("create"));
	cls_TDF_Tool.def_static("Label_", [](const opencascade::handle<TDF_Data> & a0, const TColStd_ListOfInteger & a1, TDF_Label & a2) -> void { return TDF_Tool::Label(a0, a1, a2); }, py::arg("aDF"), py::arg("aTagList"), py::arg("aLabel"));
	cls_TDF_Tool.def_static("Label_", (void (*)(const opencascade::handle<TDF_Data> &, const TColStd_ListOfInteger &, TDF_Label &, const Standard_Boolean)) &TDF_Tool::Label, "Returns the label expressed by <anEntry>; creates the label if it does not exist and if <create> is true.", py::arg("aDF"), py::arg("aTagList"), py::arg("aLabel"), py::arg("create"));
	cls_TDF_Tool.def_static("CountLabels_", (void (*)(TDF_LabelList &, TDF_LabelIntegerMap &)) &TDF_Tool::CountLabels, "Adds the labels of <aLabelList> to <aLabelMap> if they are unbound, or increases their reference counters. At the end of the process, <aLabelList> contains only the ADDED labels.", py::arg("aLabelList"), py::arg("aLabelMap"));
	cls_TDF_Tool.def_static("DeductLabels_", (void (*)(TDF_LabelList &, TDF_LabelIntegerMap &)) &TDF_Tool::DeductLabels, "Decreases the reference counters of the labels of <aLabelList> to <aLabelMap>, and removes labels with null counter. At the end of the process, <aLabelList> contains only the SUPPRESSED labels.", py::arg("aLabelList"), py::arg("aLabelMap"));
	cls_TDF_Tool.def_static("DeepDump_", (void (*)(Standard_OStream &, const opencascade::handle<TDF_Data> &)) &TDF_Tool::DeepDump, "Dumps <aDF> and its labels and their attributes.", py::arg("anOS"), py::arg("aDF"));
	cls_TDF_Tool.def_static("ExtendedDeepDump_", (void (*)(Standard_OStream &, const opencascade::handle<TDF_Data> &, const TDF_IDFilter &)) &TDF_Tool::ExtendedDeepDump, "Dumps <aDF> and its labels and their attributes, if their IDs are kept by <aFilter>. Dumps also the attributes content.", py::arg("anOS"), py::arg("aDF"), py::arg("aFilter"));
	cls_TDF_Tool.def_static("DeepDump_", (void (*)(Standard_OStream &, const TDF_Label &)) &TDF_Tool::DeepDump, "Dumps <aLabel>, its chilren and their attributes.", py::arg("anOS"), py::arg("aLabel"));
	cls_TDF_Tool.def_static("ExtendedDeepDump_", (void (*)(Standard_OStream &, const TDF_Label &, const TDF_IDFilter &)) &TDF_Tool::ExtendedDeepDump, "Dumps <aLabel>, its chilren and their attributes, if their IDs are kept by <aFilter>. Dumps also the attributes content.", py::arg("anOS"), py::arg("aLabel"), py::arg("aFilter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF.hxx
	py::class_<TDF, std::unique_ptr<TDF, Deleter<TDF>>> cls_TDF(mod, "TDF", "This package provides data framework for binding features and data structures.");
	cls_TDF.def(py::init<>());
	cls_TDF.def_static("LowestID_", (const Standard_GUID & (*)()) &TDF::LowestID, "Returns ID '00000000-0000-0000-0000-000000000000', sometimes used as null ID.");
	cls_TDF.def_static("UppestID_", (const Standard_GUID & (*)()) &TDF::UppestID, "Returns ID 'ffffffff-ffff-ffff-ffff-ffffffffffff'.");
	cls_TDF.def_static("AddLinkGUIDToProgID_", (void (*)(const Standard_GUID &, const TCollection_ExtendedString &)) &TDF::AddLinkGUIDToProgID, "Sets link between GUID and ProgID in hidden DataMap", py::arg("ID"), py::arg("ProgID"));
	cls_TDF.def_static("GUIDFromProgID_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_GUID &)) &TDF::GUIDFromProgID, "Returns True if there is GUID for given <ProgID> then GUID is returned in <ID>", py::arg("ProgID"), py::arg("ID"));
	cls_TDF.def_static("ProgIDFromGUID_", (Standard_Boolean (*)(const Standard_GUID &, TCollection_ExtendedString &)) &TDF::ProgIDFromGUID, "Returns True if there is ProgID for given <ID> then ProgID is returned in <ProgID>", py::arg("ID"), py::arg("ProgID"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TDF_AttributeArray1, std::unique_ptr<TDF_AttributeArray1, Deleter<TDF_AttributeArray1>>> cls_TDF_AttributeArray1(mod, "TDF_AttributeArray1", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TDF_AttributeArray1.def(py::init<>());
	cls_TDF_AttributeArray1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TDF_AttributeArray1.def(py::init([] (const TDF_AttributeArray1 &other) {return new TDF_AttributeArray1(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TDF_AttributeArray1.def(py::init<TDF_AttributeArray1 &&>(), py::arg("theOther"));
	cls_TDF_AttributeArray1.def(py::init<const opencascade::handle<TDF_Attribute> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TDF_AttributeArray1.def("begin", (TDF_AttributeArray1::iterator (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TDF_AttributeArray1.def("end", (TDF_AttributeArray1::iterator (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TDF_AttributeArray1.def("cbegin", (TDF_AttributeArray1::const_iterator (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TDF_AttributeArray1.def("cend", (TDF_AttributeArray1::const_iterator (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TDF_AttributeArray1.def("Init", (void (TDF_AttributeArray1::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeArray1::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TDF_AttributeArray1.def("Size", (Standard_Integer (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::Size, "Size query");
	cls_TDF_AttributeArray1.def("Length", (Standard_Integer (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::Length, "Length query (the same)");
	cls_TDF_AttributeArray1.def("IsEmpty", (Standard_Boolean (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::IsEmpty, "Return TRUE if array has zero length.");
	cls_TDF_AttributeArray1.def("Lower", (Standard_Integer (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::Lower, "Lower bound");
	cls_TDF_AttributeArray1.def("Upper", (Standard_Integer (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::Upper, "Upper bound");
	cls_TDF_AttributeArray1.def("IsDeletable", (Standard_Boolean (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::IsDeletable, "myDeletable flag");
	cls_TDF_AttributeArray1.def("IsAllocated", (Standard_Boolean (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TDF_AttributeArray1.def("Assign", (TDF_AttributeArray1 & (TDF_AttributeArray1::*)(const TDF_AttributeArray1 &)) &TDF_AttributeArray1::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TDF_AttributeArray1.def("Move", (TDF_AttributeArray1 & (TDF_AttributeArray1::*)(TDF_AttributeArray1 &&)) &TDF_AttributeArray1::Move, "Move assignment", py::arg("theOther"));
	cls_TDF_AttributeArray1.def("assign", (TDF_AttributeArray1 & (TDF_AttributeArray1::*)(const TDF_AttributeArray1 &)) &TDF_AttributeArray1::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TDF_AttributeArray1.def("assign", (TDF_AttributeArray1 & (TDF_AttributeArray1::*)(TDF_AttributeArray1 &&)) &TDF_AttributeArray1::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TDF_AttributeArray1.def("First", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::First, "Returns first element");
	cls_TDF_AttributeArray1.def("ChangeFirst", (opencascade::handle<TDF_Attribute> & (TDF_AttributeArray1::*)()) &TDF_AttributeArray1::ChangeFirst, "Returns first element");
	cls_TDF_AttributeArray1.def("Last", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeArray1::*)() const ) &TDF_AttributeArray1::Last, "Returns last element");
	cls_TDF_AttributeArray1.def("ChangeLast", (opencascade::handle<TDF_Attribute> & (TDF_AttributeArray1::*)()) &TDF_AttributeArray1::ChangeLast, "Returns last element");
	cls_TDF_AttributeArray1.def("Value", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeArray1::*)(const Standard_Integer) const ) &TDF_AttributeArray1::Value, "Constant value access", py::arg("theIndex"));
	cls_TDF_AttributeArray1.def("__call__", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeArray1::*)(const Standard_Integer) const ) &TDF_AttributeArray1::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TDF_AttributeArray1.def("ChangeValue", (opencascade::handle<TDF_Attribute> & (TDF_AttributeArray1::*)(const Standard_Integer)) &TDF_AttributeArray1::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TDF_AttributeArray1.def("__call__", (opencascade::handle<TDF_Attribute> & (TDF_AttributeArray1::*)(const Standard_Integer)) &TDF_AttributeArray1::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TDF_AttributeArray1.def("SetValue", (void (TDF_AttributeArray1::*)(const Standard_Integer, const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeArray1::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TDF_AttributeArray1.def("Resize", (void (TDF_AttributeArray1::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TDF_AttributeArray1::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TDF_AttributeArray1.def("__iter__", [](const TDF_AttributeArray1 &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_LabelNodePtr.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
	py::class_<TDF_AttributeIndexedMap, std::unique_ptr<TDF_AttributeIndexedMap, Deleter<TDF_AttributeIndexedMap>>, NCollection_BaseMap> cls_TDF_AttributeIndexedMap(mod, "TDF_AttributeIndexedMap", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.");
	cls_TDF_AttributeIndexedMap.def(py::init<>());
	cls_TDF_AttributeIndexedMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_AttributeIndexedMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_AttributeIndexedMap.def(py::init([] (const TDF_AttributeIndexedMap &other) {return new TDF_AttributeIndexedMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_AttributeIndexedMap.def("cbegin", (TDF_AttributeIndexedMap::const_iterator (TDF_AttributeIndexedMap::*)() const ) &TDF_AttributeIndexedMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TDF_AttributeIndexedMap.def("cend", (TDF_AttributeIndexedMap::const_iterator (TDF_AttributeIndexedMap::*)() const ) &TDF_AttributeIndexedMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TDF_AttributeIndexedMap.def("Exchange", (void (TDF_AttributeIndexedMap::*)(TDF_AttributeIndexedMap &)) &TDF_AttributeIndexedMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_AttributeIndexedMap.def("Assign", (TDF_AttributeIndexedMap & (TDF_AttributeIndexedMap::*)(const TDF_AttributeIndexedMap &)) &TDF_AttributeIndexedMap::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_AttributeIndexedMap.def("assign", (TDF_AttributeIndexedMap & (TDF_AttributeIndexedMap::*)(const TDF_AttributeIndexedMap &)) &TDF_AttributeIndexedMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TDF_AttributeIndexedMap.def("ReSize", (void (TDF_AttributeIndexedMap::*)(const Standard_Integer)) &TDF_AttributeIndexedMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_AttributeIndexedMap.def("Add", (Standard_Integer (TDF_AttributeIndexedMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeIndexedMap::Add, "Add", py::arg("theKey1"));
	cls_TDF_AttributeIndexedMap.def("Contains", (Standard_Boolean (TDF_AttributeIndexedMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeIndexedMap::Contains, "Contains", py::arg("theKey1"));
	cls_TDF_AttributeIndexedMap.def("Substitute", (void (TDF_AttributeIndexedMap::*)(const Standard_Integer, const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeIndexedMap::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
	cls_TDF_AttributeIndexedMap.def("Swap", (void (TDF_AttributeIndexedMap::*)(const Standard_Integer, const Standard_Integer)) &TDF_AttributeIndexedMap::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TDF_AttributeIndexedMap.def("RemoveLast", (void (TDF_AttributeIndexedMap::*)()) &TDF_AttributeIndexedMap::RemoveLast, "RemoveLast");
	cls_TDF_AttributeIndexedMap.def("RemoveFromIndex", (void (TDF_AttributeIndexedMap::*)(const Standard_Integer)) &TDF_AttributeIndexedMap::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TDF_AttributeIndexedMap.def("RemoveKey", (Standard_Boolean (TDF_AttributeIndexedMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeIndexedMap::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TDF_AttributeIndexedMap.def("FindKey", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeIndexedMap::*)(const Standard_Integer) const ) &TDF_AttributeIndexedMap::FindKey, "FindKey", py::arg("theKey2"));
	cls_TDF_AttributeIndexedMap.def("__call__", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeIndexedMap::*)(const Standard_Integer) const ) &TDF_AttributeIndexedMap::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TDF_AttributeIndexedMap.def("FindIndex", (Standard_Integer (TDF_AttributeIndexedMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeIndexedMap::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TDF_AttributeIndexedMap.def("Clear", [](TDF_AttributeIndexedMap &self) -> void { return self.Clear(); });
	cls_TDF_AttributeIndexedMap.def("Clear", (void (TDF_AttributeIndexedMap::*)(const Standard_Boolean)) &TDF_AttributeIndexedMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_AttributeIndexedMap.def("Clear", (void (TDF_AttributeIndexedMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_AttributeIndexedMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_AttributeIndexedMap.def("Size", (Standard_Integer (TDF_AttributeIndexedMap::*)() const ) &TDF_AttributeIndexedMap::Size, "Size");

	other_mod = py::module::import("OCCT.BOPCol");
	if (py::hasattr(other_mod, "BOPCol_BaseAllocator")) {
		mod.attr("TDF_HAllocator") = other_mod.attr("BOPCol_BaseAllocator");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TDF_LabelList, std::unique_ptr<TDF_LabelList, Deleter<TDF_LabelList>>, NCollection_BaseList> cls_TDF_LabelList(mod, "TDF_LabelList", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TDF_LabelList.def(py::init<>());
	cls_TDF_LabelList.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TDF_LabelList.def(py::init([] (const TDF_LabelList &other) {return new TDF_LabelList(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_LabelList.def("begin", (TDF_LabelList::iterator (TDF_LabelList::*)() const ) &TDF_LabelList::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TDF_LabelList.def("end", (TDF_LabelList::iterator (TDF_LabelList::*)() const ) &TDF_LabelList::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TDF_LabelList.def("cbegin", (TDF_LabelList::const_iterator (TDF_LabelList::*)() const ) &TDF_LabelList::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TDF_LabelList.def("cend", (TDF_LabelList::const_iterator (TDF_LabelList::*)() const ) &TDF_LabelList::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TDF_LabelList.def("Size", (Standard_Integer (TDF_LabelList::*)() const ) &TDF_LabelList::Size, "Size - Number of items");
	cls_TDF_LabelList.def("Assign", (TDF_LabelList & (TDF_LabelList::*)(const TDF_LabelList &)) &TDF_LabelList::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_LabelList.def("assign", (TDF_LabelList & (TDF_LabelList::*)(const TDF_LabelList &)) &TDF_LabelList::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TDF_LabelList.def("Clear", [](TDF_LabelList &self) -> void { return self.Clear(); });
	cls_TDF_LabelList.def("Clear", (void (TDF_LabelList::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_LabelList::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TDF_LabelList.def("First", (const TDF_Label & (TDF_LabelList::*)() const ) &TDF_LabelList::First, "First item");
	cls_TDF_LabelList.def("First", (TDF_Label & (TDF_LabelList::*)()) &TDF_LabelList::First, "First item (non-const)");
	cls_TDF_LabelList.def("Last", (const TDF_Label & (TDF_LabelList::*)() const ) &TDF_LabelList::Last, "Last item");
	cls_TDF_LabelList.def("Last", (TDF_Label & (TDF_LabelList::*)()) &TDF_LabelList::Last, "Last item (non-const)");
	cls_TDF_LabelList.def("Append", (TDF_Label & (TDF_LabelList::*)(const TDF_Label &)) &TDF_LabelList::Append, "Append one item at the end", py::arg("theItem"));
	cls_TDF_LabelList.def("Append", (void (TDF_LabelList::*)(const TDF_Label &, TDF_LabelList::Iterator &)) &TDF_LabelList::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_LabelList.def("Append", (void (TDF_LabelList::*)(TDF_LabelList &)) &TDF_LabelList::Append, "Append another list at the end", py::arg("theOther"));
	cls_TDF_LabelList.def("Prepend", (TDF_Label & (TDF_LabelList::*)(const TDF_Label &)) &TDF_LabelList::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TDF_LabelList.def("Prepend", (void (TDF_LabelList::*)(TDF_LabelList &)) &TDF_LabelList::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TDF_LabelList.def("RemoveFirst", (void (TDF_LabelList::*)()) &TDF_LabelList::RemoveFirst, "RemoveFirst item");
	cls_TDF_LabelList.def("Remove", (void (TDF_LabelList::*)(TDF_LabelList::Iterator &)) &TDF_LabelList::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TDF_LabelList.def("InsertBefore", (TDF_Label & (TDF_LabelList::*)(const TDF_Label &, TDF_LabelList::Iterator &)) &TDF_LabelList::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_LabelList.def("InsertBefore", (void (TDF_LabelList::*)(TDF_LabelList &, TDF_LabelList::Iterator &)) &TDF_LabelList::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_LabelList.def("InsertAfter", (TDF_Label & (TDF_LabelList::*)(const TDF_Label &, TDF_LabelList::Iterator &)) &TDF_LabelList::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_LabelList.def("InsertAfter", (void (TDF_LabelList::*)(TDF_LabelList &, TDF_LabelList::Iterator &)) &TDF_LabelList::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_LabelList.def("Reverse", (void (TDF_LabelList::*)()) &TDF_LabelList::Reverse, "Reverse the list");
	cls_TDF_LabelList.def("__iter__", [](const TDF_LabelList &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TDF_ListIteratorOfLabelList, std::unique_ptr<TDF_ListIteratorOfLabelList, Deleter<TDF_ListIteratorOfLabelList>>> cls_TDF_ListIteratorOfLabelList(mod, "TDF_ListIteratorOfLabelList", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TDF_ListIteratorOfLabelList.def(py::init<>());
	cls_TDF_ListIteratorOfLabelList.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TDF_ListIteratorOfLabelList.def("More", (Standard_Boolean (TDF_ListIteratorOfLabelList::*)() const ) &TDF_ListIteratorOfLabelList::More, "Check end");
	cls_TDF_ListIteratorOfLabelList.def("Next", (void (TDF_ListIteratorOfLabelList::*)()) &TDF_ListIteratorOfLabelList::Next, "Make step");
	cls_TDF_ListIteratorOfLabelList.def("Value", (const TDF_Label & (TDF_ListIteratorOfLabelList::*)() const ) &TDF_ListIteratorOfLabelList::Value, "Constant Value access");
	cls_TDF_ListIteratorOfLabelList.def("Value", (TDF_Label & (TDF_ListIteratorOfLabelList::*)()) &TDF_ListIteratorOfLabelList::Value, "Non-const Value access");
	cls_TDF_ListIteratorOfLabelList.def("ChangeValue", (TDF_Label & (TDF_ListIteratorOfLabelList::*)() const ) &TDF_ListIteratorOfLabelList::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TDF_LabelSequence, std::unique_ptr<TDF_LabelSequence, Deleter<TDF_LabelSequence>>, NCollection_BaseSequence> cls_TDF_LabelSequence(mod, "TDF_LabelSequence", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TDF_LabelSequence.def(py::init<>());
	cls_TDF_LabelSequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TDF_LabelSequence.def(py::init([] (const TDF_LabelSequence &other) {return new TDF_LabelSequence(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_LabelSequence.def("begin", (TDF_LabelSequence::iterator (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TDF_LabelSequence.def("end", (TDF_LabelSequence::iterator (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TDF_LabelSequence.def("cbegin", (TDF_LabelSequence::const_iterator (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TDF_LabelSequence.def("cend", (TDF_LabelSequence::const_iterator (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TDF_LabelSequence.def("Size", (Standard_Integer (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::Size, "Number of items");
	cls_TDF_LabelSequence.def("Length", (Standard_Integer (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::Length, "Number of items");
	cls_TDF_LabelSequence.def("Lower", (Standard_Integer (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::Lower, "Method for consistency with other collections.");
	cls_TDF_LabelSequence.def("Upper", (Standard_Integer (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::Upper, "Method for consistency with other collections.");
	cls_TDF_LabelSequence.def("IsEmpty", (Standard_Boolean (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::IsEmpty, "Empty query");
	cls_TDF_LabelSequence.def("Reverse", (void (TDF_LabelSequence::*)()) &TDF_LabelSequence::Reverse, "Reverse sequence");
	cls_TDF_LabelSequence.def("Exchange", (void (TDF_LabelSequence::*)(const Standard_Integer, const Standard_Integer)) &TDF_LabelSequence::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TDF_LabelSequence.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TDF_LabelSequence::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TDF_LabelSequence.def("Clear", [](TDF_LabelSequence &self) -> void { return self.Clear(); });
	cls_TDF_LabelSequence.def("Clear", (void (TDF_LabelSequence::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_LabelSequence::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TDF_LabelSequence.def("Assign", (TDF_LabelSequence & (TDF_LabelSequence::*)(const TDF_LabelSequence &)) &TDF_LabelSequence::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_LabelSequence.def("assign", (TDF_LabelSequence & (TDF_LabelSequence::*)(const TDF_LabelSequence &)) &TDF_LabelSequence::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TDF_LabelSequence.def("Remove", (void (TDF_LabelSequence::*)(TDF_LabelSequence::Iterator &)) &TDF_LabelSequence::Remove, "Remove one item", py::arg("thePosition"));
	cls_TDF_LabelSequence.def("Remove", (void (TDF_LabelSequence::*)(const Standard_Integer)) &TDF_LabelSequence::Remove, "Remove one item", py::arg("theIndex"));
	cls_TDF_LabelSequence.def("Remove", (void (TDF_LabelSequence::*)(const Standard_Integer, const Standard_Integer)) &TDF_LabelSequence::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TDF_LabelSequence.def("Append", (void (TDF_LabelSequence::*)(const TDF_Label &)) &TDF_LabelSequence::Append, "Append one item", py::arg("theItem"));
	cls_TDF_LabelSequence.def("Append", (void (TDF_LabelSequence::*)(TDF_LabelSequence &)) &TDF_LabelSequence::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TDF_LabelSequence.def("Prepend", (void (TDF_LabelSequence::*)(const TDF_Label &)) &TDF_LabelSequence::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TDF_LabelSequence.def("Prepend", (void (TDF_LabelSequence::*)(TDF_LabelSequence &)) &TDF_LabelSequence::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TDF_LabelSequence.def("InsertBefore", (void (TDF_LabelSequence::*)(const Standard_Integer, const TDF_Label &)) &TDF_LabelSequence::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TDF_LabelSequence.def("InsertBefore", (void (TDF_LabelSequence::*)(const Standard_Integer, TDF_LabelSequence &)) &TDF_LabelSequence::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TDF_LabelSequence.def("InsertAfter", (void (TDF_LabelSequence::*)(TDF_LabelSequence::Iterator &, const TDF_Label &)) &TDF_LabelSequence::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TDF_LabelSequence.def("InsertAfter", (void (TDF_LabelSequence::*)(const Standard_Integer, TDF_LabelSequence &)) &TDF_LabelSequence::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TDF_LabelSequence.def("InsertAfter", (void (TDF_LabelSequence::*)(const Standard_Integer, const TDF_Label &)) &TDF_LabelSequence::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TDF_LabelSequence.def("Split", (void (TDF_LabelSequence::*)(const Standard_Integer, TDF_LabelSequence &)) &TDF_LabelSequence::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TDF_LabelSequence.def("First", (const TDF_Label & (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::First, "First item access");
	cls_TDF_LabelSequence.def("ChangeFirst", (TDF_Label & (TDF_LabelSequence::*)()) &TDF_LabelSequence::ChangeFirst, "First item access");
	cls_TDF_LabelSequence.def("Last", (const TDF_Label & (TDF_LabelSequence::*)() const ) &TDF_LabelSequence::Last, "Last item access");
	cls_TDF_LabelSequence.def("ChangeLast", (TDF_Label & (TDF_LabelSequence::*)()) &TDF_LabelSequence::ChangeLast, "Last item access");
	cls_TDF_LabelSequence.def("Value", (const TDF_Label & (TDF_LabelSequence::*)(const Standard_Integer) const ) &TDF_LabelSequence::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TDF_LabelSequence.def("__call__", (const TDF_Label & (TDF_LabelSequence::*)(const Standard_Integer) const ) &TDF_LabelSequence::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TDF_LabelSequence.def("ChangeValue", (TDF_Label & (TDF_LabelSequence::*)(const Standard_Integer)) &TDF_LabelSequence::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TDF_LabelSequence.def("__call__", (TDF_Label & (TDF_LabelSequence::*)(const Standard_Integer)) &TDF_LabelSequence::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TDF_LabelSequence.def("SetValue", (void (TDF_LabelSequence::*)(const Standard_Integer, const TDF_Label &)) &TDF_LabelSequence::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TDF_LabelSequence.def("__iter__", [](const TDF_LabelSequence &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TDF_AttributeList, std::unique_ptr<TDF_AttributeList, Deleter<TDF_AttributeList>>, NCollection_BaseList> cls_TDF_AttributeList(mod, "TDF_AttributeList", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TDF_AttributeList.def(py::init<>());
	cls_TDF_AttributeList.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TDF_AttributeList.def(py::init([] (const TDF_AttributeList &other) {return new TDF_AttributeList(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_AttributeList.def("begin", (TDF_AttributeList::iterator (TDF_AttributeList::*)() const ) &TDF_AttributeList::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TDF_AttributeList.def("end", (TDF_AttributeList::iterator (TDF_AttributeList::*)() const ) &TDF_AttributeList::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TDF_AttributeList.def("cbegin", (TDF_AttributeList::const_iterator (TDF_AttributeList::*)() const ) &TDF_AttributeList::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TDF_AttributeList.def("cend", (TDF_AttributeList::const_iterator (TDF_AttributeList::*)() const ) &TDF_AttributeList::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TDF_AttributeList.def("Size", (Standard_Integer (TDF_AttributeList::*)() const ) &TDF_AttributeList::Size, "Size - Number of items");
	cls_TDF_AttributeList.def("Assign", (TDF_AttributeList & (TDF_AttributeList::*)(const TDF_AttributeList &)) &TDF_AttributeList::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_AttributeList.def("assign", (TDF_AttributeList & (TDF_AttributeList::*)(const TDF_AttributeList &)) &TDF_AttributeList::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TDF_AttributeList.def("Clear", [](TDF_AttributeList &self) -> void { return self.Clear(); });
	cls_TDF_AttributeList.def("Clear", (void (TDF_AttributeList::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_AttributeList::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TDF_AttributeList.def("First", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeList::*)() const ) &TDF_AttributeList::First, "First item");
	cls_TDF_AttributeList.def("First", (opencascade::handle<TDF_Attribute> & (TDF_AttributeList::*)()) &TDF_AttributeList::First, "First item (non-const)");
	cls_TDF_AttributeList.def("Last", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeList::*)() const ) &TDF_AttributeList::Last, "Last item");
	cls_TDF_AttributeList.def("Last", (opencascade::handle<TDF_Attribute> & (TDF_AttributeList::*)()) &TDF_AttributeList::Last, "Last item (non-const)");
	cls_TDF_AttributeList.def("Append", (opencascade::handle<TDF_Attribute> & (TDF_AttributeList::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeList::Append, "Append one item at the end", py::arg("theItem"));
	cls_TDF_AttributeList.def("Append", (void (TDF_AttributeList::*)(const opencascade::handle<TDF_Attribute> &, TDF_AttributeList::Iterator &)) &TDF_AttributeList::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_AttributeList.def("Append", (void (TDF_AttributeList::*)(TDF_AttributeList &)) &TDF_AttributeList::Append, "Append another list at the end", py::arg("theOther"));
	cls_TDF_AttributeList.def("Prepend", (opencascade::handle<TDF_Attribute> & (TDF_AttributeList::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeList::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TDF_AttributeList.def("Prepend", (void (TDF_AttributeList::*)(TDF_AttributeList &)) &TDF_AttributeList::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TDF_AttributeList.def("RemoveFirst", (void (TDF_AttributeList::*)()) &TDF_AttributeList::RemoveFirst, "RemoveFirst item");
	cls_TDF_AttributeList.def("Remove", (void (TDF_AttributeList::*)(TDF_AttributeList::Iterator &)) &TDF_AttributeList::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TDF_AttributeList.def("InsertBefore", (opencascade::handle<TDF_Attribute> & (TDF_AttributeList::*)(const opencascade::handle<TDF_Attribute> &, TDF_AttributeList::Iterator &)) &TDF_AttributeList::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_AttributeList.def("InsertBefore", (void (TDF_AttributeList::*)(TDF_AttributeList &, TDF_AttributeList::Iterator &)) &TDF_AttributeList::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_AttributeList.def("InsertAfter", (opencascade::handle<TDF_Attribute> & (TDF_AttributeList::*)(const opencascade::handle<TDF_Attribute> &, TDF_AttributeList::Iterator &)) &TDF_AttributeList::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_AttributeList.def("InsertAfter", (void (TDF_AttributeList::*)(TDF_AttributeList &, TDF_AttributeList::Iterator &)) &TDF_AttributeList::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_AttributeList.def("Reverse", (void (TDF_AttributeList::*)()) &TDF_AttributeList::Reverse, "Reverse the list");
	cls_TDF_AttributeList.def("__iter__", [](const TDF_AttributeList &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TDF_ListIteratorOfAttributeList, std::unique_ptr<TDF_ListIteratorOfAttributeList, Deleter<TDF_ListIteratorOfAttributeList>>> cls_TDF_ListIteratorOfAttributeList(mod, "TDF_ListIteratorOfAttributeList", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TDF_ListIteratorOfAttributeList.def(py::init<>());
	cls_TDF_ListIteratorOfAttributeList.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TDF_ListIteratorOfAttributeList.def("More", (Standard_Boolean (TDF_ListIteratorOfAttributeList::*)() const ) &TDF_ListIteratorOfAttributeList::More, "Check end");
	cls_TDF_ListIteratorOfAttributeList.def("Next", (void (TDF_ListIteratorOfAttributeList::*)()) &TDF_ListIteratorOfAttributeList::Next, "Make step");
	cls_TDF_ListIteratorOfAttributeList.def("Value", (const opencascade::handle<TDF_Attribute> & (TDF_ListIteratorOfAttributeList::*)() const ) &TDF_ListIteratorOfAttributeList::Value, "Constant Value access");
	cls_TDF_ListIteratorOfAttributeList.def("Value", (opencascade::handle<TDF_Attribute> & (TDF_ListIteratorOfAttributeList::*)()) &TDF_ListIteratorOfAttributeList::Value, "Non-const Value access");
	cls_TDF_ListIteratorOfAttributeList.def("ChangeValue", (opencascade::handle<TDF_Attribute> & (TDF_ListIteratorOfAttributeList::*)() const ) &TDF_ListIteratorOfAttributeList::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<TDF_LabelMap, std::unique_ptr<TDF_LabelMap, Deleter<TDF_LabelMap>>, NCollection_BaseMap> cls_TDF_LabelMap(mod, "TDF_LabelMap", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_TDF_LabelMap.def(py::init<>());
	cls_TDF_LabelMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_LabelMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_LabelMap.def(py::init([] (const TDF_LabelMap &other) {return new TDF_LabelMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_LabelMap.def("cbegin", (TDF_LabelMap::const_iterator (TDF_LabelMap::*)() const ) &TDF_LabelMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TDF_LabelMap.def("cend", (TDF_LabelMap::const_iterator (TDF_LabelMap::*)() const ) &TDF_LabelMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TDF_LabelMap.def("Exchange", (void (TDF_LabelMap::*)(TDF_LabelMap &)) &TDF_LabelMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_LabelMap.def("Assign", (TDF_LabelMap & (TDF_LabelMap::*)(const TDF_LabelMap &)) &TDF_LabelMap::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_LabelMap.def("assign", (TDF_LabelMap & (TDF_LabelMap::*)(const TDF_LabelMap &)) &TDF_LabelMap::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_TDF_LabelMap.def("ReSize", (void (TDF_LabelMap::*)(const Standard_Integer)) &TDF_LabelMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_LabelMap.def("Add", (Standard_Boolean (TDF_LabelMap::*)(const TDF_Label &)) &TDF_LabelMap::Add, "Add", py::arg("K"));
	cls_TDF_LabelMap.def("Added", (const TDF_Label & (TDF_LabelMap::*)(const TDF_Label &)) &TDF_LabelMap::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_TDF_LabelMap.def("Contains", (Standard_Boolean (TDF_LabelMap::*)(const TDF_Label &) const ) &TDF_LabelMap::Contains, "Contains", py::arg("K"));
	cls_TDF_LabelMap.def("Remove", (Standard_Boolean (TDF_LabelMap::*)(const TDF_Label &)) &TDF_LabelMap::Remove, "Remove", py::arg("K"));
	cls_TDF_LabelMap.def("Clear", [](TDF_LabelMap &self) -> void { return self.Clear(); });
	cls_TDF_LabelMap.def("Clear", (void (TDF_LabelMap::*)(const Standard_Boolean)) &TDF_LabelMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_LabelMap.def("Clear", (void (TDF_LabelMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_LabelMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_LabelMap.def("Size", (Standard_Integer (TDF_LabelMap::*)() const ) &TDF_LabelMap::Size, "Size");
	cls_TDF_LabelMap.def("IsEqual", (Standard_Boolean (TDF_LabelMap::*)(const TDF_LabelMap &) const ) &TDF_LabelMap::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_TDF_LabelMap.def("Contains", (Standard_Boolean (TDF_LabelMap::*)(const TDF_LabelMap &) const ) &TDF_LabelMap::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_TDF_LabelMap.def("Union", (void (TDF_LabelMap::*)(const TDF_LabelMap &, const TDF_LabelMap &)) &TDF_LabelMap::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_LabelMap.def("Unite", (Standard_Boolean (TDF_LabelMap::*)(const TDF_LabelMap &)) &TDF_LabelMap::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TDF_LabelMap.def("HasIntersection", (Standard_Boolean (TDF_LabelMap::*)(const TDF_LabelMap &) const ) &TDF_LabelMap::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_TDF_LabelMap.def("Intersection", (void (TDF_LabelMap::*)(const TDF_LabelMap &, const TDF_LabelMap &)) &TDF_LabelMap::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_LabelMap.def("Intersect", (Standard_Boolean (TDF_LabelMap::*)(const TDF_LabelMap &)) &TDF_LabelMap::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TDF_LabelMap.def("Subtraction", (void (TDF_LabelMap::*)(const TDF_LabelMap &, const TDF_LabelMap &)) &TDF_LabelMap::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_LabelMap.def("Subtract", (Standard_Boolean (TDF_LabelMap::*)(const TDF_LabelMap &)) &TDF_LabelMap::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TDF_LabelMap.def("Difference", (void (TDF_LabelMap::*)(const TDF_LabelMap &, const TDF_LabelMap &)) &TDF_LabelMap::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_LabelMap.def("Differ", (Standard_Boolean (TDF_LabelMap::*)(const TDF_LabelMap &)) &TDF_LabelMap::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_LabelMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TDF_IDList, std::unique_ptr<TDF_IDList, Deleter<TDF_IDList>>, NCollection_BaseList> cls_TDF_IDList(mod, "TDF_IDList", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TDF_IDList.def(py::init<>());
	cls_TDF_IDList.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TDF_IDList.def(py::init([] (const TDF_IDList &other) {return new TDF_IDList(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_IDList.def("begin", (TDF_IDList::iterator (TDF_IDList::*)() const ) &TDF_IDList::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TDF_IDList.def("end", (TDF_IDList::iterator (TDF_IDList::*)() const ) &TDF_IDList::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TDF_IDList.def("cbegin", (TDF_IDList::const_iterator (TDF_IDList::*)() const ) &TDF_IDList::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TDF_IDList.def("cend", (TDF_IDList::const_iterator (TDF_IDList::*)() const ) &TDF_IDList::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TDF_IDList.def("Size", (Standard_Integer (TDF_IDList::*)() const ) &TDF_IDList::Size, "Size - Number of items");
	cls_TDF_IDList.def("Assign", (TDF_IDList & (TDF_IDList::*)(const TDF_IDList &)) &TDF_IDList::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_IDList.def("assign", (TDF_IDList & (TDF_IDList::*)(const TDF_IDList &)) &TDF_IDList::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TDF_IDList.def("Clear", [](TDF_IDList &self) -> void { return self.Clear(); });
	cls_TDF_IDList.def("Clear", (void (TDF_IDList::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_IDList::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TDF_IDList.def("First", (const Standard_GUID & (TDF_IDList::*)() const ) &TDF_IDList::First, "First item");
	cls_TDF_IDList.def("First", (Standard_GUID & (TDF_IDList::*)()) &TDF_IDList::First, "First item (non-const)");
	cls_TDF_IDList.def("Last", (const Standard_GUID & (TDF_IDList::*)() const ) &TDF_IDList::Last, "Last item");
	cls_TDF_IDList.def("Last", (Standard_GUID & (TDF_IDList::*)()) &TDF_IDList::Last, "Last item (non-const)");
	cls_TDF_IDList.def("Append", (Standard_GUID & (TDF_IDList::*)(const Standard_GUID &)) &TDF_IDList::Append, "Append one item at the end", py::arg("theItem"));
	cls_TDF_IDList.def("Append", (void (TDF_IDList::*)(const Standard_GUID &, TDF_IDList::Iterator &)) &TDF_IDList::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_IDList.def("Append", (void (TDF_IDList::*)(TDF_IDList &)) &TDF_IDList::Append, "Append another list at the end", py::arg("theOther"));
	cls_TDF_IDList.def("Prepend", (Standard_GUID & (TDF_IDList::*)(const Standard_GUID &)) &TDF_IDList::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TDF_IDList.def("Prepend", (void (TDF_IDList::*)(TDF_IDList &)) &TDF_IDList::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TDF_IDList.def("RemoveFirst", (void (TDF_IDList::*)()) &TDF_IDList::RemoveFirst, "RemoveFirst item");
	cls_TDF_IDList.def("Remove", (void (TDF_IDList::*)(TDF_IDList::Iterator &)) &TDF_IDList::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TDF_IDList.def("InsertBefore", (Standard_GUID & (TDF_IDList::*)(const Standard_GUID &, TDF_IDList::Iterator &)) &TDF_IDList::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_IDList.def("InsertBefore", (void (TDF_IDList::*)(TDF_IDList &, TDF_IDList::Iterator &)) &TDF_IDList::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_IDList.def("InsertAfter", (Standard_GUID & (TDF_IDList::*)(const Standard_GUID &, TDF_IDList::Iterator &)) &TDF_IDList::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_IDList.def("InsertAfter", (void (TDF_IDList::*)(TDF_IDList &, TDF_IDList::Iterator &)) &TDF_IDList::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_IDList.def("Reverse", (void (TDF_IDList::*)()) &TDF_IDList::Reverse, "Reverse the list");
	cls_TDF_IDList.def("__iter__", [](const TDF_IDList &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TDF_ListIteratorOfIDList, std::unique_ptr<TDF_ListIteratorOfIDList, Deleter<TDF_ListIteratorOfIDList>>> cls_TDF_ListIteratorOfIDList(mod, "TDF_ListIteratorOfIDList", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TDF_ListIteratorOfIDList.def(py::init<>());
	cls_TDF_ListIteratorOfIDList.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TDF_ListIteratorOfIDList.def("More", (Standard_Boolean (TDF_ListIteratorOfIDList::*)() const ) &TDF_ListIteratorOfIDList::More, "Check end");
	cls_TDF_ListIteratorOfIDList.def("Next", (void (TDF_ListIteratorOfIDList::*)()) &TDF_ListIteratorOfIDList::Next, "Make step");
	cls_TDF_ListIteratorOfIDList.def("Value", (const Standard_GUID & (TDF_ListIteratorOfIDList::*)() const ) &TDF_ListIteratorOfIDList::Value, "Constant Value access");
	cls_TDF_ListIteratorOfIDList.def("Value", (Standard_GUID & (TDF_ListIteratorOfIDList::*)()) &TDF_ListIteratorOfIDList::Value, "Non-const Value access");
	cls_TDF_ListIteratorOfIDList.def("ChangeValue", (Standard_GUID & (TDF_ListIteratorOfIDList::*)() const ) &TDF_ListIteratorOfIDList::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_HAttributeArray1.hxx
	py::class_<TDF_HAttributeArray1, opencascade::handle<TDF_HAttributeArray1>, TDF_AttributeArray1, Standard_Transient> cls_TDF_HAttributeArray1(mod, "TDF_HAttributeArray1", "None");
	cls_TDF_HAttributeArray1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TDF_HAttributeArray1.def(py::init<const Standard_Integer, const Standard_Integer, const TDF_AttributeArray1::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TDF_HAttributeArray1.def(py::init<const TDF_AttributeArray1 &>(), py::arg("theOther"));
	cls_TDF_HAttributeArray1.def("Array1", (const TDF_AttributeArray1 & (TDF_HAttributeArray1::*)() const ) &TDF_HAttributeArray1::Array1, "None");
	cls_TDF_HAttributeArray1.def("ChangeArray1", (TDF_AttributeArray1 & (TDF_HAttributeArray1::*)()) &TDF_HAttributeArray1::ChangeArray1, "None");
	cls_TDF_HAttributeArray1.def_static("get_type_name_", (const char * (*)()) &TDF_HAttributeArray1::get_type_name, "None");
	cls_TDF_HAttributeArray1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_HAttributeArray1::get_type_descriptor, "None");
	cls_TDF_HAttributeArray1.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_HAttributeArray1::*)() const ) &TDF_HAttributeArray1::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TDF_AttributeDataMap, std::unique_ptr<TDF_AttributeDataMap, Deleter<TDF_AttributeDataMap>>, NCollection_BaseMap> cls_TDF_AttributeDataMap(mod, "TDF_AttributeDataMap", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TDF_AttributeDataMap.def(py::init<>());
	cls_TDF_AttributeDataMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_AttributeDataMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_AttributeDataMap.def(py::init([] (const TDF_AttributeDataMap &other) {return new TDF_AttributeDataMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_AttributeDataMap.def("begin", (TDF_AttributeDataMap::iterator (TDF_AttributeDataMap::*)() const ) &TDF_AttributeDataMap::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TDF_AttributeDataMap.def("end", (TDF_AttributeDataMap::iterator (TDF_AttributeDataMap::*)() const ) &TDF_AttributeDataMap::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TDF_AttributeDataMap.def("cbegin", (TDF_AttributeDataMap::const_iterator (TDF_AttributeDataMap::*)() const ) &TDF_AttributeDataMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TDF_AttributeDataMap.def("cend", (TDF_AttributeDataMap::const_iterator (TDF_AttributeDataMap::*)() const ) &TDF_AttributeDataMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TDF_AttributeDataMap.def("Exchange", (void (TDF_AttributeDataMap::*)(TDF_AttributeDataMap &)) &TDF_AttributeDataMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_AttributeDataMap.def("Assign", (TDF_AttributeDataMap & (TDF_AttributeDataMap::*)(const TDF_AttributeDataMap &)) &TDF_AttributeDataMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_AttributeDataMap.def("assign", (TDF_AttributeDataMap & (TDF_AttributeDataMap::*)(const TDF_AttributeDataMap &)) &TDF_AttributeDataMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TDF_AttributeDataMap.def("ReSize", (void (TDF_AttributeDataMap::*)(const Standard_Integer)) &TDF_AttributeDataMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_AttributeDataMap.def("Bind", (Standard_Boolean (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeDataMap::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TDF_AttributeDataMap.def("Bound", (opencascade::handle<TDF_Attribute> * (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeDataMap::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TDF_AttributeDataMap.def("IsBound", (Standard_Boolean (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDataMap::IsBound, "IsBound", py::arg("theKey"));
	cls_TDF_AttributeDataMap.def("UnBind", (Standard_Boolean (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeDataMap::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TDF_AttributeDataMap.def("Seek", (const opencascade::handle<TDF_Attribute> * (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDataMap::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TDF_AttributeDataMap.def("Find", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDataMap::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TDF_AttributeDataMap.def("Find", (Standard_Boolean (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &, opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDataMap::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TDF_AttributeDataMap.def("__call__", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDataMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TDF_AttributeDataMap.def("ChangeSeek", (opencascade::handle<TDF_Attribute> * (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeDataMap::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TDF_AttributeDataMap.def("ChangeFind", (opencascade::handle<TDF_Attribute> & (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeDataMap::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TDF_AttributeDataMap.def("__call__", (opencascade::handle<TDF_Attribute> & (TDF_AttributeDataMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeDataMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TDF_AttributeDataMap.def("Clear", [](TDF_AttributeDataMap &self) -> void { return self.Clear(); });
	cls_TDF_AttributeDataMap.def("Clear", (void (TDF_AttributeDataMap::*)(const Standard_Boolean)) &TDF_AttributeDataMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_AttributeDataMap.def("Clear", (void (TDF_AttributeDataMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_AttributeDataMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_AttributeDataMap.def("Size", (Standard_Integer (TDF_AttributeDataMap::*)() const ) &TDF_AttributeDataMap::Size, "Size");
	cls_TDF_AttributeDataMap.def("__iter__", [](const TDF_AttributeDataMap &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_AttributeDataMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TDF_AttributeDeltaList, std::unique_ptr<TDF_AttributeDeltaList, Deleter<TDF_AttributeDeltaList>>, NCollection_BaseList> cls_TDF_AttributeDeltaList(mod, "TDF_AttributeDeltaList", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TDF_AttributeDeltaList.def(py::init<>());
	cls_TDF_AttributeDeltaList.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TDF_AttributeDeltaList.def(py::init([] (const TDF_AttributeDeltaList &other) {return new TDF_AttributeDeltaList(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_AttributeDeltaList.def("begin", (TDF_AttributeDeltaList::iterator (TDF_AttributeDeltaList::*)() const ) &TDF_AttributeDeltaList::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TDF_AttributeDeltaList.def("end", (TDF_AttributeDeltaList::iterator (TDF_AttributeDeltaList::*)() const ) &TDF_AttributeDeltaList::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TDF_AttributeDeltaList.def("cbegin", (TDF_AttributeDeltaList::const_iterator (TDF_AttributeDeltaList::*)() const ) &TDF_AttributeDeltaList::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TDF_AttributeDeltaList.def("cend", (TDF_AttributeDeltaList::const_iterator (TDF_AttributeDeltaList::*)() const ) &TDF_AttributeDeltaList::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TDF_AttributeDeltaList.def("Size", (Standard_Integer (TDF_AttributeDeltaList::*)() const ) &TDF_AttributeDeltaList::Size, "Size - Number of items");
	cls_TDF_AttributeDeltaList.def("Assign", (TDF_AttributeDeltaList & (TDF_AttributeDeltaList::*)(const TDF_AttributeDeltaList &)) &TDF_AttributeDeltaList::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_AttributeDeltaList.def("assign", (TDF_AttributeDeltaList & (TDF_AttributeDeltaList::*)(const TDF_AttributeDeltaList &)) &TDF_AttributeDeltaList::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TDF_AttributeDeltaList.def("Clear", [](TDF_AttributeDeltaList &self) -> void { return self.Clear(); });
	cls_TDF_AttributeDeltaList.def("Clear", (void (TDF_AttributeDeltaList::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_AttributeDeltaList::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TDF_AttributeDeltaList.def("First", (const opencascade::handle<TDF_AttributeDelta> & (TDF_AttributeDeltaList::*)() const ) &TDF_AttributeDeltaList::First, "First item");
	cls_TDF_AttributeDeltaList.def("First", (opencascade::handle<TDF_AttributeDelta> & (TDF_AttributeDeltaList::*)()) &TDF_AttributeDeltaList::First, "First item (non-const)");
	cls_TDF_AttributeDeltaList.def("Last", (const opencascade::handle<TDF_AttributeDelta> & (TDF_AttributeDeltaList::*)() const ) &TDF_AttributeDeltaList::Last, "Last item");
	cls_TDF_AttributeDeltaList.def("Last", (opencascade::handle<TDF_AttributeDelta> & (TDF_AttributeDeltaList::*)()) &TDF_AttributeDeltaList::Last, "Last item (non-const)");
	cls_TDF_AttributeDeltaList.def("Append", (opencascade::handle<TDF_AttributeDelta> & (TDF_AttributeDeltaList::*)(const opencascade::handle<TDF_AttributeDelta> &)) &TDF_AttributeDeltaList::Append, "Append one item at the end", py::arg("theItem"));
	cls_TDF_AttributeDeltaList.def("Append", (void (TDF_AttributeDeltaList::*)(const opencascade::handle<TDF_AttributeDelta> &, TDF_AttributeDeltaList::Iterator &)) &TDF_AttributeDeltaList::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_AttributeDeltaList.def("Append", (void (TDF_AttributeDeltaList::*)(TDF_AttributeDeltaList &)) &TDF_AttributeDeltaList::Append, "Append another list at the end", py::arg("theOther"));
	cls_TDF_AttributeDeltaList.def("Prepend", (opencascade::handle<TDF_AttributeDelta> & (TDF_AttributeDeltaList::*)(const opencascade::handle<TDF_AttributeDelta> &)) &TDF_AttributeDeltaList::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TDF_AttributeDeltaList.def("Prepend", (void (TDF_AttributeDeltaList::*)(TDF_AttributeDeltaList &)) &TDF_AttributeDeltaList::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TDF_AttributeDeltaList.def("RemoveFirst", (void (TDF_AttributeDeltaList::*)()) &TDF_AttributeDeltaList::RemoveFirst, "RemoveFirst item");
	cls_TDF_AttributeDeltaList.def("Remove", (void (TDF_AttributeDeltaList::*)(TDF_AttributeDeltaList::Iterator &)) &TDF_AttributeDeltaList::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TDF_AttributeDeltaList.def("InsertBefore", (opencascade::handle<TDF_AttributeDelta> & (TDF_AttributeDeltaList::*)(const opencascade::handle<TDF_AttributeDelta> &, TDF_AttributeDeltaList::Iterator &)) &TDF_AttributeDeltaList::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_AttributeDeltaList.def("InsertBefore", (void (TDF_AttributeDeltaList::*)(TDF_AttributeDeltaList &, TDF_AttributeDeltaList::Iterator &)) &TDF_AttributeDeltaList::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_AttributeDeltaList.def("InsertAfter", (opencascade::handle<TDF_AttributeDelta> & (TDF_AttributeDeltaList::*)(const opencascade::handle<TDF_AttributeDelta> &, TDF_AttributeDeltaList::Iterator &)) &TDF_AttributeDeltaList::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_AttributeDeltaList.def("InsertAfter", (void (TDF_AttributeDeltaList::*)(TDF_AttributeDeltaList &, TDF_AttributeDeltaList::Iterator &)) &TDF_AttributeDeltaList::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_AttributeDeltaList.def("Reverse", (void (TDF_AttributeDeltaList::*)()) &TDF_AttributeDeltaList::Reverse, "Reverse the list");
	cls_TDF_AttributeDeltaList.def("__iter__", [](const TDF_AttributeDeltaList &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TDF_ListIteratorOfAttributeDeltaList, std::unique_ptr<TDF_ListIteratorOfAttributeDeltaList, Deleter<TDF_ListIteratorOfAttributeDeltaList>>> cls_TDF_ListIteratorOfAttributeDeltaList(mod, "TDF_ListIteratorOfAttributeDeltaList", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TDF_ListIteratorOfAttributeDeltaList.def(py::init<>());
	cls_TDF_ListIteratorOfAttributeDeltaList.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TDF_ListIteratorOfAttributeDeltaList.def("More", (Standard_Boolean (TDF_ListIteratorOfAttributeDeltaList::*)() const ) &TDF_ListIteratorOfAttributeDeltaList::More, "Check end");
	cls_TDF_ListIteratorOfAttributeDeltaList.def("Next", (void (TDF_ListIteratorOfAttributeDeltaList::*)()) &TDF_ListIteratorOfAttributeDeltaList::Next, "Make step");
	cls_TDF_ListIteratorOfAttributeDeltaList.def("Value", (const opencascade::handle<TDF_AttributeDelta> & (TDF_ListIteratorOfAttributeDeltaList::*)() const ) &TDF_ListIteratorOfAttributeDeltaList::Value, "Constant Value access");
	cls_TDF_ListIteratorOfAttributeDeltaList.def("Value", (opencascade::handle<TDF_AttributeDelta> & (TDF_ListIteratorOfAttributeDeltaList::*)()) &TDF_ListIteratorOfAttributeDeltaList::Value, "Non-const Value access");
	cls_TDF_ListIteratorOfAttributeDeltaList.def("ChangeValue", (opencascade::handle<TDF_AttributeDelta> & (TDF_ListIteratorOfAttributeDeltaList::*)() const ) &TDF_ListIteratorOfAttributeDeltaList::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DoubleMap.hxx
	py::class_<TDF_AttributeDoubleMap, std::unique_ptr<TDF_AttributeDoubleMap, Deleter<TDF_AttributeDoubleMap>>, NCollection_BaseMap> cls_TDF_AttributeDoubleMap(mod, "TDF_AttributeDoubleMap", "Purpose: The DoubleMap is used to bind pairs (Key1,Key2) and retrieve them in linear time.");
	cls_TDF_AttributeDoubleMap.def(py::init<>());
	cls_TDF_AttributeDoubleMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_AttributeDoubleMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_AttributeDoubleMap.def(py::init([] (const TDF_AttributeDoubleMap &other) {return new TDF_AttributeDoubleMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_AttributeDoubleMap.def("Exchange", (void (TDF_AttributeDoubleMap::*)(TDF_AttributeDoubleMap &)) &TDF_AttributeDoubleMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_AttributeDoubleMap.def("Assign", (TDF_AttributeDoubleMap & (TDF_AttributeDoubleMap::*)(const TDF_AttributeDoubleMap &)) &TDF_AttributeDoubleMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_AttributeDoubleMap.def("assign", (TDF_AttributeDoubleMap & (TDF_AttributeDoubleMap::*)(const TDF_AttributeDoubleMap &)) &TDF_AttributeDoubleMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TDF_AttributeDoubleMap.def("ReSize", (void (TDF_AttributeDoubleMap::*)(const Standard_Integer)) &TDF_AttributeDoubleMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_AttributeDoubleMap.def("Bind", (void (TDF_AttributeDoubleMap::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeDoubleMap::Bind, "Bind", py::arg("theKey1"), py::arg("theKey2"));
	cls_TDF_AttributeDoubleMap.def("AreBound", (Standard_Boolean (TDF_AttributeDoubleMap::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDoubleMap::AreBound, "* AreBound", py::arg("theKey1"), py::arg("theKey2"));
	cls_TDF_AttributeDoubleMap.def("IsBound1", (Standard_Boolean (TDF_AttributeDoubleMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDoubleMap::IsBound1, "IsBound1", py::arg("theKey1"));
	cls_TDF_AttributeDoubleMap.def("IsBound2", (Standard_Boolean (TDF_AttributeDoubleMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDoubleMap::IsBound2, "IsBound2", py::arg("theKey2"));
	cls_TDF_AttributeDoubleMap.def("UnBind1", (Standard_Boolean (TDF_AttributeDoubleMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeDoubleMap::UnBind1, "UnBind1", py::arg("theKey1"));
	cls_TDF_AttributeDoubleMap.def("UnBind2", (Standard_Boolean (TDF_AttributeDoubleMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeDoubleMap::UnBind2, "UnBind2", py::arg("theKey2"));
	cls_TDF_AttributeDoubleMap.def("Find1", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeDoubleMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDoubleMap::Find1, "Find1", py::arg("theKey1"));
	cls_TDF_AttributeDoubleMap.def("Find2", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeDoubleMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeDoubleMap::Find2, "Find2", py::arg("theKey2"));
	cls_TDF_AttributeDoubleMap.def("Clear", [](TDF_AttributeDoubleMap &self) -> void { return self.Clear(); });
	cls_TDF_AttributeDoubleMap.def("Clear", (void (TDF_AttributeDoubleMap::*)(const Standard_Boolean)) &TDF_AttributeDoubleMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_AttributeDoubleMap.def("Clear", (void (TDF_AttributeDoubleMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_AttributeDoubleMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_AttributeDoubleMap.def("Size", (Standard_Integer (TDF_AttributeDoubleMap::*)() const ) &TDF_AttributeDoubleMap::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_AttributeDoubleMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<TDF_AttributeMap, std::unique_ptr<TDF_AttributeMap, Deleter<TDF_AttributeMap>>, NCollection_BaseMap> cls_TDF_AttributeMap(mod, "TDF_AttributeMap", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_TDF_AttributeMap.def(py::init<>());
	cls_TDF_AttributeMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_AttributeMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_AttributeMap.def(py::init([] (const TDF_AttributeMap &other) {return new TDF_AttributeMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_AttributeMap.def("cbegin", (TDF_AttributeMap::const_iterator (TDF_AttributeMap::*)() const ) &TDF_AttributeMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TDF_AttributeMap.def("cend", (TDF_AttributeMap::const_iterator (TDF_AttributeMap::*)() const ) &TDF_AttributeMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TDF_AttributeMap.def("Exchange", (void (TDF_AttributeMap::*)(TDF_AttributeMap &)) &TDF_AttributeMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_AttributeMap.def("Assign", (TDF_AttributeMap & (TDF_AttributeMap::*)(const TDF_AttributeMap &)) &TDF_AttributeMap::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_AttributeMap.def("assign", (TDF_AttributeMap & (TDF_AttributeMap::*)(const TDF_AttributeMap &)) &TDF_AttributeMap::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_TDF_AttributeMap.def("ReSize", (void (TDF_AttributeMap::*)(const Standard_Integer)) &TDF_AttributeMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_AttributeMap.def("Add", (Standard_Boolean (TDF_AttributeMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeMap::Add, "Add", py::arg("K"));
	cls_TDF_AttributeMap.def("Added", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeMap::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_TDF_AttributeMap.def("Contains", (Standard_Boolean (TDF_AttributeMap::*)(const opencascade::handle<TDF_Attribute> &) const ) &TDF_AttributeMap::Contains, "Contains", py::arg("K"));
	cls_TDF_AttributeMap.def("Remove", (Standard_Boolean (TDF_AttributeMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeMap::Remove, "Remove", py::arg("K"));
	cls_TDF_AttributeMap.def("Clear", [](TDF_AttributeMap &self) -> void { return self.Clear(); });
	cls_TDF_AttributeMap.def("Clear", (void (TDF_AttributeMap::*)(const Standard_Boolean)) &TDF_AttributeMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_AttributeMap.def("Clear", (void (TDF_AttributeMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_AttributeMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_AttributeMap.def("Size", (Standard_Integer (TDF_AttributeMap::*)() const ) &TDF_AttributeMap::Size, "Size");
	cls_TDF_AttributeMap.def("IsEqual", (Standard_Boolean (TDF_AttributeMap::*)(const TDF_AttributeMap &) const ) &TDF_AttributeMap::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_TDF_AttributeMap.def("Contains", (Standard_Boolean (TDF_AttributeMap::*)(const TDF_AttributeMap &) const ) &TDF_AttributeMap::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_TDF_AttributeMap.def("Union", (void (TDF_AttributeMap::*)(const TDF_AttributeMap &, const TDF_AttributeMap &)) &TDF_AttributeMap::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_AttributeMap.def("Unite", (Standard_Boolean (TDF_AttributeMap::*)(const TDF_AttributeMap &)) &TDF_AttributeMap::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TDF_AttributeMap.def("HasIntersection", (Standard_Boolean (TDF_AttributeMap::*)(const TDF_AttributeMap &) const ) &TDF_AttributeMap::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_TDF_AttributeMap.def("Intersection", (void (TDF_AttributeMap::*)(const TDF_AttributeMap &, const TDF_AttributeMap &)) &TDF_AttributeMap::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_AttributeMap.def("Intersect", (Standard_Boolean (TDF_AttributeMap::*)(const TDF_AttributeMap &)) &TDF_AttributeMap::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TDF_AttributeMap.def("Subtraction", (void (TDF_AttributeMap::*)(const TDF_AttributeMap &, const TDF_AttributeMap &)) &TDF_AttributeMap::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_AttributeMap.def("Subtract", (Standard_Boolean (TDF_AttributeMap::*)(const TDF_AttributeMap &)) &TDF_AttributeMap::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TDF_AttributeMap.def("Difference", (void (TDF_AttributeMap::*)(const TDF_AttributeMap &, const TDF_AttributeMap &)) &TDF_AttributeMap::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_AttributeMap.def("Differ", (Standard_Boolean (TDF_AttributeMap::*)(const TDF_AttributeMap &)) &TDF_AttributeMap::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_AttributeMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TDF_AttributeSequence, std::unique_ptr<TDF_AttributeSequence, Deleter<TDF_AttributeSequence>>, NCollection_BaseSequence> cls_TDF_AttributeSequence(mod, "TDF_AttributeSequence", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TDF_AttributeSequence.def(py::init<>());
	cls_TDF_AttributeSequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TDF_AttributeSequence.def(py::init([] (const TDF_AttributeSequence &other) {return new TDF_AttributeSequence(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_AttributeSequence.def("begin", (TDF_AttributeSequence::iterator (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TDF_AttributeSequence.def("end", (TDF_AttributeSequence::iterator (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TDF_AttributeSequence.def("cbegin", (TDF_AttributeSequence::const_iterator (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TDF_AttributeSequence.def("cend", (TDF_AttributeSequence::const_iterator (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TDF_AttributeSequence.def("Size", (Standard_Integer (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::Size, "Number of items");
	cls_TDF_AttributeSequence.def("Length", (Standard_Integer (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::Length, "Number of items");
	cls_TDF_AttributeSequence.def("Lower", (Standard_Integer (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::Lower, "Method for consistency with other collections.");
	cls_TDF_AttributeSequence.def("Upper", (Standard_Integer (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::Upper, "Method for consistency with other collections.");
	cls_TDF_AttributeSequence.def("IsEmpty", (Standard_Boolean (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::IsEmpty, "Empty query");
	cls_TDF_AttributeSequence.def("Reverse", (void (TDF_AttributeSequence::*)()) &TDF_AttributeSequence::Reverse, "Reverse sequence");
	cls_TDF_AttributeSequence.def("Exchange", (void (TDF_AttributeSequence::*)(const Standard_Integer, const Standard_Integer)) &TDF_AttributeSequence::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TDF_AttributeSequence.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TDF_AttributeSequence::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TDF_AttributeSequence.def("Clear", [](TDF_AttributeSequence &self) -> void { return self.Clear(); });
	cls_TDF_AttributeSequence.def("Clear", (void (TDF_AttributeSequence::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_AttributeSequence::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TDF_AttributeSequence.def("Assign", (TDF_AttributeSequence & (TDF_AttributeSequence::*)(const TDF_AttributeSequence &)) &TDF_AttributeSequence::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_AttributeSequence.def("assign", (TDF_AttributeSequence & (TDF_AttributeSequence::*)(const TDF_AttributeSequence &)) &TDF_AttributeSequence::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TDF_AttributeSequence.def("Remove", (void (TDF_AttributeSequence::*)(TDF_AttributeSequence::Iterator &)) &TDF_AttributeSequence::Remove, "Remove one item", py::arg("thePosition"));
	cls_TDF_AttributeSequence.def("Remove", (void (TDF_AttributeSequence::*)(const Standard_Integer)) &TDF_AttributeSequence::Remove, "Remove one item", py::arg("theIndex"));
	cls_TDF_AttributeSequence.def("Remove", (void (TDF_AttributeSequence::*)(const Standard_Integer, const Standard_Integer)) &TDF_AttributeSequence::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TDF_AttributeSequence.def("Append", (void (TDF_AttributeSequence::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeSequence::Append, "Append one item", py::arg("theItem"));
	cls_TDF_AttributeSequence.def("Append", (void (TDF_AttributeSequence::*)(TDF_AttributeSequence &)) &TDF_AttributeSequence::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TDF_AttributeSequence.def("Prepend", (void (TDF_AttributeSequence::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeSequence::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TDF_AttributeSequence.def("Prepend", (void (TDF_AttributeSequence::*)(TDF_AttributeSequence &)) &TDF_AttributeSequence::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TDF_AttributeSequence.def("InsertBefore", (void (TDF_AttributeSequence::*)(const Standard_Integer, const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeSequence::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TDF_AttributeSequence.def("InsertBefore", (void (TDF_AttributeSequence::*)(const Standard_Integer, TDF_AttributeSequence &)) &TDF_AttributeSequence::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TDF_AttributeSequence.def("InsertAfter", (void (TDF_AttributeSequence::*)(TDF_AttributeSequence::Iterator &, const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeSequence::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TDF_AttributeSequence.def("InsertAfter", (void (TDF_AttributeSequence::*)(const Standard_Integer, TDF_AttributeSequence &)) &TDF_AttributeSequence::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TDF_AttributeSequence.def("InsertAfter", (void (TDF_AttributeSequence::*)(const Standard_Integer, const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeSequence::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TDF_AttributeSequence.def("Split", (void (TDF_AttributeSequence::*)(const Standard_Integer, TDF_AttributeSequence &)) &TDF_AttributeSequence::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TDF_AttributeSequence.def("First", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::First, "First item access");
	cls_TDF_AttributeSequence.def("ChangeFirst", (opencascade::handle<TDF_Attribute> & (TDF_AttributeSequence::*)()) &TDF_AttributeSequence::ChangeFirst, "First item access");
	cls_TDF_AttributeSequence.def("Last", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeSequence::*)() const ) &TDF_AttributeSequence::Last, "Last item access");
	cls_TDF_AttributeSequence.def("ChangeLast", (opencascade::handle<TDF_Attribute> & (TDF_AttributeSequence::*)()) &TDF_AttributeSequence::ChangeLast, "Last item access");
	cls_TDF_AttributeSequence.def("Value", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeSequence::*)(const Standard_Integer) const ) &TDF_AttributeSequence::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TDF_AttributeSequence.def("__call__", (const opencascade::handle<TDF_Attribute> & (TDF_AttributeSequence::*)(const Standard_Integer) const ) &TDF_AttributeSequence::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TDF_AttributeSequence.def("ChangeValue", (opencascade::handle<TDF_Attribute> & (TDF_AttributeSequence::*)(const Standard_Integer)) &TDF_AttributeSequence::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TDF_AttributeSequence.def("__call__", (opencascade::handle<TDF_Attribute> & (TDF_AttributeSequence::*)(const Standard_Integer)) &TDF_AttributeSequence::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TDF_AttributeSequence.def("SetValue", (void (TDF_AttributeSequence::*)(const Standard_Integer, const opencascade::handle<TDF_Attribute> &)) &TDF_AttributeSequence::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TDF_AttributeSequence.def("__iter__", [](const TDF_AttributeSequence &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<TDF_IDMap, std::unique_ptr<TDF_IDMap, Deleter<TDF_IDMap>>, NCollection_BaseMap> cls_TDF_IDMap(mod, "TDF_IDMap", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_TDF_IDMap.def(py::init<>());
	cls_TDF_IDMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_IDMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_IDMap.def(py::init([] (const TDF_IDMap &other) {return new TDF_IDMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_IDMap.def("cbegin", (TDF_IDMap::const_iterator (TDF_IDMap::*)() const ) &TDF_IDMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TDF_IDMap.def("cend", (TDF_IDMap::const_iterator (TDF_IDMap::*)() const ) &TDF_IDMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TDF_IDMap.def("Exchange", (void (TDF_IDMap::*)(TDF_IDMap &)) &TDF_IDMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_IDMap.def("Assign", (TDF_IDMap & (TDF_IDMap::*)(const TDF_IDMap &)) &TDF_IDMap::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_IDMap.def("assign", (TDF_IDMap & (TDF_IDMap::*)(const TDF_IDMap &)) &TDF_IDMap::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_TDF_IDMap.def("ReSize", (void (TDF_IDMap::*)(const Standard_Integer)) &TDF_IDMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_IDMap.def("Add", (Standard_Boolean (TDF_IDMap::*)(const Standard_GUID &)) &TDF_IDMap::Add, "Add", py::arg("K"));
	cls_TDF_IDMap.def("Added", (const Standard_GUID & (TDF_IDMap::*)(const Standard_GUID &)) &TDF_IDMap::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_TDF_IDMap.def("Contains", (Standard_Boolean (TDF_IDMap::*)(const Standard_GUID &) const ) &TDF_IDMap::Contains, "Contains", py::arg("K"));
	cls_TDF_IDMap.def("Remove", (Standard_Boolean (TDF_IDMap::*)(const Standard_GUID &)) &TDF_IDMap::Remove, "Remove", py::arg("K"));
	cls_TDF_IDMap.def("Clear", [](TDF_IDMap &self) -> void { return self.Clear(); });
	cls_TDF_IDMap.def("Clear", (void (TDF_IDMap::*)(const Standard_Boolean)) &TDF_IDMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_IDMap.def("Clear", (void (TDF_IDMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_IDMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_IDMap.def("Size", (Standard_Integer (TDF_IDMap::*)() const ) &TDF_IDMap::Size, "Size");
	cls_TDF_IDMap.def("IsEqual", (Standard_Boolean (TDF_IDMap::*)(const TDF_IDMap &) const ) &TDF_IDMap::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_TDF_IDMap.def("Contains", (Standard_Boolean (TDF_IDMap::*)(const TDF_IDMap &) const ) &TDF_IDMap::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_TDF_IDMap.def("Union", (void (TDF_IDMap::*)(const TDF_IDMap &, const TDF_IDMap &)) &TDF_IDMap::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_IDMap.def("Unite", (Standard_Boolean (TDF_IDMap::*)(const TDF_IDMap &)) &TDF_IDMap::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TDF_IDMap.def("HasIntersection", (Standard_Boolean (TDF_IDMap::*)(const TDF_IDMap &) const ) &TDF_IDMap::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_TDF_IDMap.def("Intersection", (void (TDF_IDMap::*)(const TDF_IDMap &, const TDF_IDMap &)) &TDF_IDMap::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_IDMap.def("Intersect", (Standard_Boolean (TDF_IDMap::*)(const TDF_IDMap &)) &TDF_IDMap::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TDF_IDMap.def("Subtraction", (void (TDF_IDMap::*)(const TDF_IDMap &, const TDF_IDMap &)) &TDF_IDMap::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_IDMap.def("Subtract", (Standard_Boolean (TDF_IDMap::*)(const TDF_IDMap &)) &TDF_IDMap::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TDF_IDMap.def("Difference", (void (TDF_IDMap::*)(const TDF_IDMap &, const TDF_IDMap &)) &TDF_IDMap::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TDF_IDMap.def("Differ", (Standard_Boolean (TDF_IDMap::*)(const TDF_IDMap &)) &TDF_IDMap::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_IDMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TDF_LabelDataMap, std::unique_ptr<TDF_LabelDataMap, Deleter<TDF_LabelDataMap>>, NCollection_BaseMap> cls_TDF_LabelDataMap(mod, "TDF_LabelDataMap", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TDF_LabelDataMap.def(py::init<>());
	cls_TDF_LabelDataMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_LabelDataMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_LabelDataMap.def(py::init([] (const TDF_LabelDataMap &other) {return new TDF_LabelDataMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_LabelDataMap.def("begin", (TDF_LabelDataMap::iterator (TDF_LabelDataMap::*)() const ) &TDF_LabelDataMap::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TDF_LabelDataMap.def("end", (TDF_LabelDataMap::iterator (TDF_LabelDataMap::*)() const ) &TDF_LabelDataMap::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TDF_LabelDataMap.def("cbegin", (TDF_LabelDataMap::const_iterator (TDF_LabelDataMap::*)() const ) &TDF_LabelDataMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TDF_LabelDataMap.def("cend", (TDF_LabelDataMap::const_iterator (TDF_LabelDataMap::*)() const ) &TDF_LabelDataMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TDF_LabelDataMap.def("Exchange", (void (TDF_LabelDataMap::*)(TDF_LabelDataMap &)) &TDF_LabelDataMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_LabelDataMap.def("Assign", (TDF_LabelDataMap & (TDF_LabelDataMap::*)(const TDF_LabelDataMap &)) &TDF_LabelDataMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_LabelDataMap.def("assign", (TDF_LabelDataMap & (TDF_LabelDataMap::*)(const TDF_LabelDataMap &)) &TDF_LabelDataMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TDF_LabelDataMap.def("ReSize", (void (TDF_LabelDataMap::*)(const Standard_Integer)) &TDF_LabelDataMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_LabelDataMap.def("Bind", (Standard_Boolean (TDF_LabelDataMap::*)(const TDF_Label &, const TDF_Label &)) &TDF_LabelDataMap::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TDF_LabelDataMap.def("Bound", (TDF_Label * (TDF_LabelDataMap::*)(const TDF_Label &, const TDF_Label &)) &TDF_LabelDataMap::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TDF_LabelDataMap.def("IsBound", (Standard_Boolean (TDF_LabelDataMap::*)(const TDF_Label &) const ) &TDF_LabelDataMap::IsBound, "IsBound", py::arg("theKey"));
	cls_TDF_LabelDataMap.def("UnBind", (Standard_Boolean (TDF_LabelDataMap::*)(const TDF_Label &)) &TDF_LabelDataMap::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TDF_LabelDataMap.def("Seek", (const TDF_Label * (TDF_LabelDataMap::*)(const TDF_Label &) const ) &TDF_LabelDataMap::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TDF_LabelDataMap.def("Find", (const TDF_Label & (TDF_LabelDataMap::*)(const TDF_Label &) const ) &TDF_LabelDataMap::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TDF_LabelDataMap.def("Find", (Standard_Boolean (TDF_LabelDataMap::*)(const TDF_Label &, TDF_Label &) const ) &TDF_LabelDataMap::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TDF_LabelDataMap.def("__call__", (const TDF_Label & (TDF_LabelDataMap::*)(const TDF_Label &) const ) &TDF_LabelDataMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TDF_LabelDataMap.def("ChangeSeek", (TDF_Label * (TDF_LabelDataMap::*)(const TDF_Label &)) &TDF_LabelDataMap::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TDF_LabelDataMap.def("ChangeFind", (TDF_Label & (TDF_LabelDataMap::*)(const TDF_Label &)) &TDF_LabelDataMap::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TDF_LabelDataMap.def("__call__", (TDF_Label & (TDF_LabelDataMap::*)(const TDF_Label &)) &TDF_LabelDataMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TDF_LabelDataMap.def("Clear", [](TDF_LabelDataMap &self) -> void { return self.Clear(); });
	cls_TDF_LabelDataMap.def("Clear", (void (TDF_LabelDataMap::*)(const Standard_Boolean)) &TDF_LabelDataMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_LabelDataMap.def("Clear", (void (TDF_LabelDataMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_LabelDataMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_LabelDataMap.def("Size", (Standard_Integer (TDF_LabelDataMap::*)() const ) &TDF_LabelDataMap::Size, "Size");
	cls_TDF_LabelDataMap.def("__iter__", [](const TDF_LabelDataMap &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_LabelDataMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TDF_LabelIntegerMap, std::unique_ptr<TDF_LabelIntegerMap, Deleter<TDF_LabelIntegerMap>>, NCollection_BaseMap> cls_TDF_LabelIntegerMap(mod, "TDF_LabelIntegerMap", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TDF_LabelIntegerMap.def(py::init<>());
	cls_TDF_LabelIntegerMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_LabelIntegerMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_LabelIntegerMap.def(py::init([] (const TDF_LabelIntegerMap &other) {return new TDF_LabelIntegerMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_LabelIntegerMap.def("begin", (TDF_LabelIntegerMap::iterator (TDF_LabelIntegerMap::*)() const ) &TDF_LabelIntegerMap::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TDF_LabelIntegerMap.def("end", (TDF_LabelIntegerMap::iterator (TDF_LabelIntegerMap::*)() const ) &TDF_LabelIntegerMap::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TDF_LabelIntegerMap.def("cbegin", (TDF_LabelIntegerMap::const_iterator (TDF_LabelIntegerMap::*)() const ) &TDF_LabelIntegerMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TDF_LabelIntegerMap.def("cend", (TDF_LabelIntegerMap::const_iterator (TDF_LabelIntegerMap::*)() const ) &TDF_LabelIntegerMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TDF_LabelIntegerMap.def("Exchange", (void (TDF_LabelIntegerMap::*)(TDF_LabelIntegerMap &)) &TDF_LabelIntegerMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_LabelIntegerMap.def("Assign", (TDF_LabelIntegerMap & (TDF_LabelIntegerMap::*)(const TDF_LabelIntegerMap &)) &TDF_LabelIntegerMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_LabelIntegerMap.def("assign", (TDF_LabelIntegerMap & (TDF_LabelIntegerMap::*)(const TDF_LabelIntegerMap &)) &TDF_LabelIntegerMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TDF_LabelIntegerMap.def("ReSize", (void (TDF_LabelIntegerMap::*)(const Standard_Integer)) &TDF_LabelIntegerMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_LabelIntegerMap.def("Bind", (Standard_Boolean (TDF_LabelIntegerMap::*)(const TDF_Label &, const Standard_Integer &)) &TDF_LabelIntegerMap::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TDF_LabelIntegerMap.def("Bound", (Standard_Integer * (TDF_LabelIntegerMap::*)(const TDF_Label &, const Standard_Integer &)) &TDF_LabelIntegerMap::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TDF_LabelIntegerMap.def("IsBound", (Standard_Boolean (TDF_LabelIntegerMap::*)(const TDF_Label &) const ) &TDF_LabelIntegerMap::IsBound, "IsBound", py::arg("theKey"));
	cls_TDF_LabelIntegerMap.def("UnBind", (Standard_Boolean (TDF_LabelIntegerMap::*)(const TDF_Label &)) &TDF_LabelIntegerMap::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TDF_LabelIntegerMap.def("Seek", (const Standard_Integer * (TDF_LabelIntegerMap::*)(const TDF_Label &) const ) &TDF_LabelIntegerMap::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TDF_LabelIntegerMap.def("Find", (const Standard_Integer & (TDF_LabelIntegerMap::*)(const TDF_Label &) const ) &TDF_LabelIntegerMap::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TDF_LabelIntegerMap.def("Find", (Standard_Boolean (TDF_LabelIntegerMap::*)(const TDF_Label &, Standard_Integer &) const ) &TDF_LabelIntegerMap::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TDF_LabelIntegerMap.def("__call__", (const Standard_Integer & (TDF_LabelIntegerMap::*)(const TDF_Label &) const ) &TDF_LabelIntegerMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TDF_LabelIntegerMap.def("ChangeSeek", (Standard_Integer * (TDF_LabelIntegerMap::*)(const TDF_Label &)) &TDF_LabelIntegerMap::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TDF_LabelIntegerMap.def("ChangeFind", (Standard_Integer & (TDF_LabelIntegerMap::*)(const TDF_Label &)) &TDF_LabelIntegerMap::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TDF_LabelIntegerMap.def("__call__", (Standard_Integer & (TDF_LabelIntegerMap::*)(const TDF_Label &)) &TDF_LabelIntegerMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TDF_LabelIntegerMap.def("Clear", [](TDF_LabelIntegerMap &self) -> void { return self.Clear(); });
	cls_TDF_LabelIntegerMap.def("Clear", (void (TDF_LabelIntegerMap::*)(const Standard_Boolean)) &TDF_LabelIntegerMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_LabelIntegerMap.def("Clear", (void (TDF_LabelIntegerMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_LabelIntegerMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_LabelIntegerMap.def("Size", (Standard_Integer (TDF_LabelIntegerMap::*)() const ) &TDF_LabelIntegerMap::Size, "Size");
	cls_TDF_LabelIntegerMap.def("__iter__", [](const TDF_LabelIntegerMap &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_LabelIntegerMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TDF_DeltaList, std::unique_ptr<TDF_DeltaList, Deleter<TDF_DeltaList>>, NCollection_BaseList> cls_TDF_DeltaList(mod, "TDF_DeltaList", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TDF_DeltaList.def(py::init<>());
	cls_TDF_DeltaList.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TDF_DeltaList.def(py::init([] (const TDF_DeltaList &other) {return new TDF_DeltaList(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_DeltaList.def("begin", (TDF_DeltaList::iterator (TDF_DeltaList::*)() const ) &TDF_DeltaList::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TDF_DeltaList.def("end", (TDF_DeltaList::iterator (TDF_DeltaList::*)() const ) &TDF_DeltaList::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TDF_DeltaList.def("cbegin", (TDF_DeltaList::const_iterator (TDF_DeltaList::*)() const ) &TDF_DeltaList::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TDF_DeltaList.def("cend", (TDF_DeltaList::const_iterator (TDF_DeltaList::*)() const ) &TDF_DeltaList::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TDF_DeltaList.def("Size", (Standard_Integer (TDF_DeltaList::*)() const ) &TDF_DeltaList::Size, "Size - Number of items");
	cls_TDF_DeltaList.def("Assign", (TDF_DeltaList & (TDF_DeltaList::*)(const TDF_DeltaList &)) &TDF_DeltaList::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_DeltaList.def("assign", (TDF_DeltaList & (TDF_DeltaList::*)(const TDF_DeltaList &)) &TDF_DeltaList::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TDF_DeltaList.def("Clear", [](TDF_DeltaList &self) -> void { return self.Clear(); });
	cls_TDF_DeltaList.def("Clear", (void (TDF_DeltaList::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_DeltaList::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TDF_DeltaList.def("First", (const opencascade::handle<TDF_Delta> & (TDF_DeltaList::*)() const ) &TDF_DeltaList::First, "First item");
	cls_TDF_DeltaList.def("First", (opencascade::handle<TDF_Delta> & (TDF_DeltaList::*)()) &TDF_DeltaList::First, "First item (non-const)");
	cls_TDF_DeltaList.def("Last", (const opencascade::handle<TDF_Delta> & (TDF_DeltaList::*)() const ) &TDF_DeltaList::Last, "Last item");
	cls_TDF_DeltaList.def("Last", (opencascade::handle<TDF_Delta> & (TDF_DeltaList::*)()) &TDF_DeltaList::Last, "Last item (non-const)");
	cls_TDF_DeltaList.def("Append", (opencascade::handle<TDF_Delta> & (TDF_DeltaList::*)(const opencascade::handle<TDF_Delta> &)) &TDF_DeltaList::Append, "Append one item at the end", py::arg("theItem"));
	cls_TDF_DeltaList.def("Append", (void (TDF_DeltaList::*)(const opencascade::handle<TDF_Delta> &, TDF_DeltaList::Iterator &)) &TDF_DeltaList::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_DeltaList.def("Append", (void (TDF_DeltaList::*)(TDF_DeltaList &)) &TDF_DeltaList::Append, "Append another list at the end", py::arg("theOther"));
	cls_TDF_DeltaList.def("Prepend", (opencascade::handle<TDF_Delta> & (TDF_DeltaList::*)(const opencascade::handle<TDF_Delta> &)) &TDF_DeltaList::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TDF_DeltaList.def("Prepend", (void (TDF_DeltaList::*)(TDF_DeltaList &)) &TDF_DeltaList::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TDF_DeltaList.def("RemoveFirst", (void (TDF_DeltaList::*)()) &TDF_DeltaList::RemoveFirst, "RemoveFirst item");
	cls_TDF_DeltaList.def("Remove", (void (TDF_DeltaList::*)(TDF_DeltaList::Iterator &)) &TDF_DeltaList::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TDF_DeltaList.def("InsertBefore", (opencascade::handle<TDF_Delta> & (TDF_DeltaList::*)(const opencascade::handle<TDF_Delta> &, TDF_DeltaList::Iterator &)) &TDF_DeltaList::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_DeltaList.def("InsertBefore", (void (TDF_DeltaList::*)(TDF_DeltaList &, TDF_DeltaList::Iterator &)) &TDF_DeltaList::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_DeltaList.def("InsertAfter", (opencascade::handle<TDF_Delta> & (TDF_DeltaList::*)(const opencascade::handle<TDF_Delta> &, TDF_DeltaList::Iterator &)) &TDF_DeltaList::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TDF_DeltaList.def("InsertAfter", (void (TDF_DeltaList::*)(TDF_DeltaList &, TDF_DeltaList::Iterator &)) &TDF_DeltaList::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TDF_DeltaList.def("Reverse", (void (TDF_DeltaList::*)()) &TDF_DeltaList::Reverse, "Reverse the list");
	cls_TDF_DeltaList.def("__iter__", [](const TDF_DeltaList &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TDF_ListIteratorOfDeltaList, std::unique_ptr<TDF_ListIteratorOfDeltaList, Deleter<TDF_ListIteratorOfDeltaList>>> cls_TDF_ListIteratorOfDeltaList(mod, "TDF_ListIteratorOfDeltaList", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TDF_ListIteratorOfDeltaList.def(py::init<>());
	cls_TDF_ListIteratorOfDeltaList.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TDF_ListIteratorOfDeltaList.def("More", (Standard_Boolean (TDF_ListIteratorOfDeltaList::*)() const ) &TDF_ListIteratorOfDeltaList::More, "Check end");
	cls_TDF_ListIteratorOfDeltaList.def("Next", (void (TDF_ListIteratorOfDeltaList::*)()) &TDF_ListIteratorOfDeltaList::Next, "Make step");
	cls_TDF_ListIteratorOfDeltaList.def("Value", (const opencascade::handle<TDF_Delta> & (TDF_ListIteratorOfDeltaList::*)() const ) &TDF_ListIteratorOfDeltaList::Value, "Constant Value access");
	cls_TDF_ListIteratorOfDeltaList.def("Value", (opencascade::handle<TDF_Delta> & (TDF_ListIteratorOfDeltaList::*)()) &TDF_ListIteratorOfDeltaList::Value, "Non-const Value access");
	cls_TDF_ListIteratorOfDeltaList.def("ChangeValue", (opencascade::handle<TDF_Delta> & (TDF_ListIteratorOfDeltaList::*)() const ) &TDF_ListIteratorOfDeltaList::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DoubleMap.hxx
	py::class_<TDF_GUIDProgIDMap, std::unique_ptr<TDF_GUIDProgIDMap, Deleter<TDF_GUIDProgIDMap>>, NCollection_BaseMap> cls_TDF_GUIDProgIDMap(mod, "TDF_GUIDProgIDMap", "Purpose: The DoubleMap is used to bind pairs (Key1,Key2) and retrieve them in linear time.");
	cls_TDF_GUIDProgIDMap.def(py::init<>());
	cls_TDF_GUIDProgIDMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_GUIDProgIDMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_GUIDProgIDMap.def(py::init([] (const TDF_GUIDProgIDMap &other) {return new TDF_GUIDProgIDMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_GUIDProgIDMap.def("Exchange", (void (TDF_GUIDProgIDMap::*)(TDF_GUIDProgIDMap &)) &TDF_GUIDProgIDMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_GUIDProgIDMap.def("Assign", (TDF_GUIDProgIDMap & (TDF_GUIDProgIDMap::*)(const TDF_GUIDProgIDMap &)) &TDF_GUIDProgIDMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_GUIDProgIDMap.def("assign", (TDF_GUIDProgIDMap & (TDF_GUIDProgIDMap::*)(const TDF_GUIDProgIDMap &)) &TDF_GUIDProgIDMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TDF_GUIDProgIDMap.def("ReSize", (void (TDF_GUIDProgIDMap::*)(const Standard_Integer)) &TDF_GUIDProgIDMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_GUIDProgIDMap.def("Bind", (void (TDF_GUIDProgIDMap::*)(const Standard_GUID &, const TCollection_ExtendedString &)) &TDF_GUIDProgIDMap::Bind, "Bind", py::arg("theKey1"), py::arg("theKey2"));
	cls_TDF_GUIDProgIDMap.def("AreBound", (Standard_Boolean (TDF_GUIDProgIDMap::*)(const Standard_GUID &, const TCollection_ExtendedString &) const ) &TDF_GUIDProgIDMap::AreBound, "* AreBound", py::arg("theKey1"), py::arg("theKey2"));
	cls_TDF_GUIDProgIDMap.def("IsBound1", (Standard_Boolean (TDF_GUIDProgIDMap::*)(const Standard_GUID &) const ) &TDF_GUIDProgIDMap::IsBound1, "IsBound1", py::arg("theKey1"));
	cls_TDF_GUIDProgIDMap.def("IsBound2", (Standard_Boolean (TDF_GUIDProgIDMap::*)(const TCollection_ExtendedString &) const ) &TDF_GUIDProgIDMap::IsBound2, "IsBound2", py::arg("theKey2"));
	cls_TDF_GUIDProgIDMap.def("UnBind1", (Standard_Boolean (TDF_GUIDProgIDMap::*)(const Standard_GUID &)) &TDF_GUIDProgIDMap::UnBind1, "UnBind1", py::arg("theKey1"));
	cls_TDF_GUIDProgIDMap.def("UnBind2", (Standard_Boolean (TDF_GUIDProgIDMap::*)(const TCollection_ExtendedString &)) &TDF_GUIDProgIDMap::UnBind2, "UnBind2", py::arg("theKey2"));
	cls_TDF_GUIDProgIDMap.def("Find1", (const TCollection_ExtendedString & (TDF_GUIDProgIDMap::*)(const Standard_GUID &) const ) &TDF_GUIDProgIDMap::Find1, "Find1", py::arg("theKey1"));
	cls_TDF_GUIDProgIDMap.def("Find2", (const Standard_GUID & (TDF_GUIDProgIDMap::*)(const TCollection_ExtendedString &) const ) &TDF_GUIDProgIDMap::Find2, "Find2", py::arg("theKey2"));
	cls_TDF_GUIDProgIDMap.def("Clear", [](TDF_GUIDProgIDMap &self) -> void { return self.Clear(); });
	cls_TDF_GUIDProgIDMap.def("Clear", (void (TDF_GUIDProgIDMap::*)(const Standard_Boolean)) &TDF_GUIDProgIDMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_GUIDProgIDMap.def("Clear", (void (TDF_GUIDProgIDMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_GUIDProgIDMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_GUIDProgIDMap.def("Size", (Standard_Integer (TDF_GUIDProgIDMap::*)() const ) &TDF_GUIDProgIDMap::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_GUIDProgIDMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DoubleMap.hxx
	py::class_<TDF_LabelDoubleMap, std::unique_ptr<TDF_LabelDoubleMap, Deleter<TDF_LabelDoubleMap>>, NCollection_BaseMap> cls_TDF_LabelDoubleMap(mod, "TDF_LabelDoubleMap", "Purpose: The DoubleMap is used to bind pairs (Key1,Key2) and retrieve them in linear time.");
	cls_TDF_LabelDoubleMap.def(py::init<>());
	cls_TDF_LabelDoubleMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_LabelDoubleMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_LabelDoubleMap.def(py::init([] (const TDF_LabelDoubleMap &other) {return new TDF_LabelDoubleMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_LabelDoubleMap.def("Exchange", (void (TDF_LabelDoubleMap::*)(TDF_LabelDoubleMap &)) &TDF_LabelDoubleMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_LabelDoubleMap.def("Assign", (TDF_LabelDoubleMap & (TDF_LabelDoubleMap::*)(const TDF_LabelDoubleMap &)) &TDF_LabelDoubleMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_LabelDoubleMap.def("assign", (TDF_LabelDoubleMap & (TDF_LabelDoubleMap::*)(const TDF_LabelDoubleMap &)) &TDF_LabelDoubleMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TDF_LabelDoubleMap.def("ReSize", (void (TDF_LabelDoubleMap::*)(const Standard_Integer)) &TDF_LabelDoubleMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_LabelDoubleMap.def("Bind", (void (TDF_LabelDoubleMap::*)(const TDF_Label &, const TDF_Label &)) &TDF_LabelDoubleMap::Bind, "Bind", py::arg("theKey1"), py::arg("theKey2"));
	cls_TDF_LabelDoubleMap.def("AreBound", (Standard_Boolean (TDF_LabelDoubleMap::*)(const TDF_Label &, const TDF_Label &) const ) &TDF_LabelDoubleMap::AreBound, "* AreBound", py::arg("theKey1"), py::arg("theKey2"));
	cls_TDF_LabelDoubleMap.def("IsBound1", (Standard_Boolean (TDF_LabelDoubleMap::*)(const TDF_Label &) const ) &TDF_LabelDoubleMap::IsBound1, "IsBound1", py::arg("theKey1"));
	cls_TDF_LabelDoubleMap.def("IsBound2", (Standard_Boolean (TDF_LabelDoubleMap::*)(const TDF_Label &) const ) &TDF_LabelDoubleMap::IsBound2, "IsBound2", py::arg("theKey2"));
	cls_TDF_LabelDoubleMap.def("UnBind1", (Standard_Boolean (TDF_LabelDoubleMap::*)(const TDF_Label &)) &TDF_LabelDoubleMap::UnBind1, "UnBind1", py::arg("theKey1"));
	cls_TDF_LabelDoubleMap.def("UnBind2", (Standard_Boolean (TDF_LabelDoubleMap::*)(const TDF_Label &)) &TDF_LabelDoubleMap::UnBind2, "UnBind2", py::arg("theKey2"));
	cls_TDF_LabelDoubleMap.def("Find1", (const TDF_Label & (TDF_LabelDoubleMap::*)(const TDF_Label &) const ) &TDF_LabelDoubleMap::Find1, "Find1", py::arg("theKey1"));
	cls_TDF_LabelDoubleMap.def("Find2", (const TDF_Label & (TDF_LabelDoubleMap::*)(const TDF_Label &) const ) &TDF_LabelDoubleMap::Find2, "Find2", py::arg("theKey2"));
	cls_TDF_LabelDoubleMap.def("Clear", [](TDF_LabelDoubleMap &self) -> void { return self.Clear(); });
	cls_TDF_LabelDoubleMap.def("Clear", (void (TDF_LabelDoubleMap::*)(const Standard_Boolean)) &TDF_LabelDoubleMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_LabelDoubleMap.def("Clear", (void (TDF_LabelDoubleMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_LabelDoubleMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_LabelDoubleMap.def("Size", (Standard_Integer (TDF_LabelDoubleMap::*)() const ) &TDF_LabelDoubleMap::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDF_LabelDoubleMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
	py::class_<TDF_LabelIndexedMap, std::unique_ptr<TDF_LabelIndexedMap, Deleter<TDF_LabelIndexedMap>>, NCollection_BaseMap> cls_TDF_LabelIndexedMap(mod, "TDF_LabelIndexedMap", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.");
	cls_TDF_LabelIndexedMap.def(py::init<>());
	cls_TDF_LabelIndexedMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TDF_LabelIndexedMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TDF_LabelIndexedMap.def(py::init([] (const TDF_LabelIndexedMap &other) {return new TDF_LabelIndexedMap(other);}), "Copy constructor", py::arg("other"));
	cls_TDF_LabelIndexedMap.def("cbegin", (TDF_LabelIndexedMap::const_iterator (TDF_LabelIndexedMap::*)() const ) &TDF_LabelIndexedMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TDF_LabelIndexedMap.def("cend", (TDF_LabelIndexedMap::const_iterator (TDF_LabelIndexedMap::*)() const ) &TDF_LabelIndexedMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TDF_LabelIndexedMap.def("Exchange", (void (TDF_LabelIndexedMap::*)(TDF_LabelIndexedMap &)) &TDF_LabelIndexedMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TDF_LabelIndexedMap.def("Assign", (TDF_LabelIndexedMap & (TDF_LabelIndexedMap::*)(const TDF_LabelIndexedMap &)) &TDF_LabelIndexedMap::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TDF_LabelIndexedMap.def("assign", (TDF_LabelIndexedMap & (TDF_LabelIndexedMap::*)(const TDF_LabelIndexedMap &)) &TDF_LabelIndexedMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TDF_LabelIndexedMap.def("ReSize", (void (TDF_LabelIndexedMap::*)(const Standard_Integer)) &TDF_LabelIndexedMap::ReSize, "ReSize", py::arg("N"));
	cls_TDF_LabelIndexedMap.def("Add", (Standard_Integer (TDF_LabelIndexedMap::*)(const TDF_Label &)) &TDF_LabelIndexedMap::Add, "Add", py::arg("theKey1"));
	cls_TDF_LabelIndexedMap.def("Contains", (Standard_Boolean (TDF_LabelIndexedMap::*)(const TDF_Label &) const ) &TDF_LabelIndexedMap::Contains, "Contains", py::arg("theKey1"));
	cls_TDF_LabelIndexedMap.def("Substitute", (void (TDF_LabelIndexedMap::*)(const Standard_Integer, const TDF_Label &)) &TDF_LabelIndexedMap::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
	cls_TDF_LabelIndexedMap.def("Swap", (void (TDF_LabelIndexedMap::*)(const Standard_Integer, const Standard_Integer)) &TDF_LabelIndexedMap::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TDF_LabelIndexedMap.def("RemoveLast", (void (TDF_LabelIndexedMap::*)()) &TDF_LabelIndexedMap::RemoveLast, "RemoveLast");
	cls_TDF_LabelIndexedMap.def("RemoveFromIndex", (void (TDF_LabelIndexedMap::*)(const Standard_Integer)) &TDF_LabelIndexedMap::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TDF_LabelIndexedMap.def("RemoveKey", (Standard_Boolean (TDF_LabelIndexedMap::*)(const TDF_Label &)) &TDF_LabelIndexedMap::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TDF_LabelIndexedMap.def("FindKey", (const TDF_Label & (TDF_LabelIndexedMap::*)(const Standard_Integer) const ) &TDF_LabelIndexedMap::FindKey, "FindKey", py::arg("theKey2"));
	cls_TDF_LabelIndexedMap.def("__call__", (const TDF_Label & (TDF_LabelIndexedMap::*)(const Standard_Integer) const ) &TDF_LabelIndexedMap::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TDF_LabelIndexedMap.def("FindIndex", (Standard_Integer (TDF_LabelIndexedMap::*)(const TDF_Label &) const ) &TDF_LabelIndexedMap::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TDF_LabelIndexedMap.def("Clear", [](TDF_LabelIndexedMap &self) -> void { return self.Clear(); });
	cls_TDF_LabelIndexedMap.def("Clear", (void (TDF_LabelIndexedMap::*)(const Standard_Boolean)) &TDF_LabelIndexedMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TDF_LabelIndexedMap.def("Clear", (void (TDF_LabelIndexedMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TDF_LabelIndexedMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TDF_LabelIndexedMap.def("Size", (Standard_Integer (TDF_LabelIndexedMap::*)() const ) &TDF_LabelIndexedMap::Size, "Size");


}
