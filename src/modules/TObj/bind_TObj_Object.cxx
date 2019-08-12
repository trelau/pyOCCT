/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Transient.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TObj_Persistence.hxx>
#include <Standard_Handle.hxx>
#include <TObj_Model.hxx>
#include <TObj_ObjectIterator.hxx>
#include <Standard_Type.hxx>
#include <TObj_TNameContainer.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TObj_Object.hxx>
#include <TObj_DeletingMode.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_GUID.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfExtendedString.hxx>
#include <TObj_SequenceOfObject.hxx>
#include <TObj_TObject.hxx>

void bind_TObj_Object(py::module &mod){

py::class_<TObj_Object, opencascade::handle<TObj_Object>, Standard_Transient> cls_TObj_Object(mod, "TObj_Object", "Basis class for transient objects in OCAF-based models");

// Constructors

// Fields

// Methods
cls_TObj_Object.def("GetModel", (opencascade::handle<TObj_Model> (TObj_Object::*)() const) &TObj_Object::GetModel, "Returns the model to which the object belongs");
cls_TObj_Object.def("GetChildren", [](TObj_Object &self) -> opencascade::handle<TObj_ObjectIterator> { return self.GetChildren(); });
cls_TObj_Object.def("GetChildren", (opencascade::handle<TObj_ObjectIterator> (TObj_Object::*)(const opencascade::handle<Standard_Type> &) const) &TObj_Object::GetChildren, "Returns iterator for the child objects. This method provides tree-like view of the objects hierarchy. The references to other objects are not considered as children. theType narrows a variety of iterated objects The default implementation search for children on 1 sublavel of the children sub label", py::arg("theType"));
cls_TObj_Object.def("GetChildLabel", (TDF_Label (TObj_Object::*)() const) &TObj_Object::GetChildLabel, "Returns the label under which children are stored");
cls_TObj_Object.def("getChildLabel", (TDF_Label (TObj_Object::*)(const Standard_Integer) const) &TObj_Object::getChildLabel, "Returns the label for child with rank", py::arg("theRank"));
cls_TObj_Object.def("GetLabel", (TDF_Label (TObj_Object::*)() const) &TObj_Object::GetLabel, "Returns the OCAF label on which object`s data are stored");
cls_TObj_Object.def("GetDataLabel", (TDF_Label (TObj_Object::*)() const) &TObj_Object::GetDataLabel, "Returns the label which is the root for data OCAF sub-tree");
cls_TObj_Object.def("GetReferenceLabel", (TDF_Label (TObj_Object::*)() const) &TObj_Object::GetReferenceLabel, "Returns the label which is the root for reference OCAF sub-tree");
cls_TObj_Object.def("GetDictionary", (opencascade::handle<TObj_TNameContainer> (TObj_Object::*)() const) &TObj_Object::GetDictionary, "Returns the map of names of the objects Default implementation returns global Dictionary of the model");
cls_TObj_Object.def("GetName", (opencascade::handle<TCollection_HExtendedString> (TObj_Object::*)() const) &TObj_Object::GetName, "Returns the name of the object (empty string if object has no name)");
cls_TObj_Object.def("GetName", (Standard_Boolean (TObj_Object::*)(TCollection_ExtendedString &) const) &TObj_Object::GetName, "Returns the Standard_True is object has name and returns name to theName", py::arg("theName"));
cls_TObj_Object.def("GetName", (Standard_Boolean (TObj_Object::*)(TCollection_AsciiString &) const) &TObj_Object::GetName, "Returns the Standard_True is object has name and returns name to theName", py::arg("theName"));
cls_TObj_Object.def("SetName", (Standard_Boolean (TObj_Object::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &TObj_Object::SetName, "Sets name of the object. Returns False if theName is not unique.", py::arg("theName"));
cls_TObj_Object.def("SetName", (Standard_Boolean (TObj_Object::*)(const opencascade::handle<TCollection_HAsciiString> &) const) &TObj_Object::SetName, "Sets name of the object. Returns False if theName is not unique.", py::arg("theName"));
cls_TObj_Object.def("SetName", (Standard_Boolean (TObj_Object::*)(const Standard_CString) const) &TObj_Object::SetName, "Sets name of the object. Returns False if theName is not unique.", py::arg("name"));
cls_TObj_Object.def("GetNameForClone", (opencascade::handle<TCollection_HExtendedString> (TObj_Object::*)(const opencascade::handle<TObj_Object> &) const) &TObj_Object::GetNameForClone, "Returns name for copy default implementation returns the same name", py::arg(""));
cls_TObj_Object.def("HasReference", (Standard_Boolean (TObj_Object::*)(const opencascade::handle<TObj_Object> &) const) &TObj_Object::HasReference, "Returns True if object has reference to indicated object", py::arg("theObject"));
cls_TObj_Object.def("GetReferences", [](TObj_Object &self) -> opencascade::handle<TObj_ObjectIterator> { return self.GetReferences(); });
cls_TObj_Object.def("GetReferences", (opencascade::handle<TObj_ObjectIterator> (TObj_Object::*)(const opencascade::handle<Standard_Type> &) const) &TObj_Object::GetReferences, "Returns an Iterator containing objects that compose the this one theType narrows a variety of iterated objects", py::arg("theType"));
cls_TObj_Object.def("RemoveAllReferences", (void (TObj_Object::*)()) &TObj_Object::RemoveAllReferences, "Remove all references to other objects, by removing all reference attributes");
cls_TObj_Object.def("GetBackReferences", [](TObj_Object &self) -> opencascade::handle<TObj_ObjectIterator> { return self.GetBackReferences(); });
cls_TObj_Object.def("GetBackReferences", (opencascade::handle<TObj_ObjectIterator> (TObj_Object::*)(const opencascade::handle<Standard_Type> &) const) &TObj_Object::GetBackReferences, "Returns iterator for the objects which depend on this one. These reffering objects may belong to other models. theType narrows a variety of iterated objects", py::arg("theType"));
cls_TObj_Object.def("AddBackReference", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &)) &TObj_Object::AddBackReference, "Registers another object as being dependent on this one. Stores back references under sublabel 2 (purely transient data, not subject to persistency).", py::arg("theObject"));
cls_TObj_Object.def("RemoveBackReference", [](TObj_Object &self, const opencascade::handle<TObj_Object> & a0) -> void { return self.RemoveBackReference(a0); });
cls_TObj_Object.def("RemoveBackReference", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &, const Standard_Boolean)) &TObj_Object::RemoveBackReference, "Removes information on dependent object (back reference). If theSingleOnly is true only the first back reference is removed in the case of duplicate items.", py::arg("theObject"), py::arg("theSingleOnly"));
cls_TObj_Object.def("RemoveBackReferences", [](TObj_Object &self) -> Standard_Boolean { return self.RemoveBackReferences(); });
cls_TObj_Object.def("RemoveBackReferences", (Standard_Boolean (TObj_Object::*)(const TObj_DeletingMode)) &TObj_Object::RemoveBackReferences, "Removes all back reference by removing references from other to me.", py::arg("theMode"));
cls_TObj_Object.def("ClearBackReferences", (void (TObj_Object::*)()) &TObj_Object::ClearBackReferences, "The default implementation just clear the back references container");
cls_TObj_Object.def("HasBackReferences", (Standard_Boolean (TObj_Object::*)() const) &TObj_Object::HasBackReferences, "Returns TRUE if obejct has 1 or more back references");
cls_TObj_Object.def("ReplaceReference", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &, const opencascade::handle<TObj_Object> &)) &TObj_Object::ReplaceReference, "Replace reference from old object to new object. If it is not possible, may raise exception. If new object is null then simple remove reference to old object.", py::arg("theOldObject"), py::arg("theNewObject"));
cls_TObj_Object.def("GetBadReference", (Standard_Boolean (TObj_Object::*)(const TDF_Label &, TDF_Label &) const) &TObj_Object::GetBadReference, "Return True if this refers to the model theRoot belongs to and a referred label is not a descendant of theRoot. In this case theBadReference returns the currently referred label.", py::arg("theRoot"), py::arg("theBadReference"));
cls_TObj_Object.def("RelocateReferences", [](TObj_Object &self, const TDF_Label & a0, const TDF_Label & a1) -> Standard_Boolean { return self.RelocateReferences(a0, a1); });
cls_TObj_Object.def("RelocateReferences", (Standard_Boolean (TObj_Object::*)(const TDF_Label &, const TDF_Label &, const Standard_Boolean)) &TObj_Object::RelocateReferences, "Make that each reference pointing to a descendant label of theFromRoot to point to an equivalent label under theToRoot. Return False if a resulting reference does not point to an TObj_Object Example: a referred object label = 0:3:24:7:2:7 theFromRoot = 0:3:24 theToRoot = 0:2 a new referred label = 0:2:7:2:7", py::arg("theFromRoot"), py::arg("theToRoot"), py::arg("theUpdateBackRefs"));
cls_TObj_Object.def("CanRemoveReference", (Standard_Boolean (TObj_Object::*)(const opencascade::handle<TObj_Object> &) const) &TObj_Object::CanRemoveReference, "Returns True if the referred object theObject can be deleted without deletion of this object. Default implementation does nothing and returns False.", py::arg("theObject"));
cls_TObj_Object.def("RemoveReference", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &)) &TObj_Object::RemoveReference, "Removes reference to the object by replace reference to NULL object", py::arg("theObject"));
cls_TObj_Object.def("BeforeForgetReference", (void (TObj_Object::*)(const TDF_Label &)) &TObj_Object::BeforeForgetReference, "Invokes from TObj_TReference::BeforeForget(). theLabel - label on that reference become removed Default implementation is empty", py::arg(""));
cls_TObj_Object.def("CanDetach", [](TObj_Object &self) -> Standard_Boolean { return self.CanDetach(); });
cls_TObj_Object.def("CanDetach", (Standard_Boolean (TObj_Object::*)(const TObj_DeletingMode)) &TObj_Object::CanDetach, "Checks if object can be detached with specified mode", py::arg("theMode"));
cls_TObj_Object.def("Detach", [](TObj_Object &self) -> Standard_Boolean { return self.Detach(); });
cls_TObj_Object.def("Detach", (Standard_Boolean (TObj_Object::*)(const TObj_DeletingMode)) &TObj_Object::Detach, "Deletes the object from the model. The dependent objects are either deleted or modified when possible (see description of TObj_DeletingMode enumeration for more details) Returns True if deletion was successful. Checks if object can be deleted. Should be redefined for each specific kind of object", py::arg("theMode"));
cls_TObj_Object.def_static("Detach_", [](const TDF_Label & a0) -> Standard_Boolean { return TObj_Object::Detach(a0); });
cls_TObj_Object.def_static("Detach_", (Standard_Boolean (*)(const TDF_Label &, const TObj_DeletingMode)) &TObj_Object::Detach, "Deletes the object from the label. Checks if object can be deleted. Finds object on the label and detaches it by calling previos method. Returns true if there is no object on the label after detaching", py::arg("theLabel"), py::arg("theMode"));
cls_TObj_Object.def_static("GetObj_", [](const TDF_Label & a0, opencascade::handle<TObj_Object> & a1) -> Standard_Boolean { return TObj_Object::GetObj(a0, a1); });
cls_TObj_Object.def_static("GetObj_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TObj_Object> &, const Standard_Boolean)) &TObj_Object::GetObj, "Returns the Object attached to a given label. Returns False if no object of type TObj_Object is stored on the specified label. If isSuper is true tries to find on the super labels.", py::arg("theLabel"), py::arg("theResult"), py::arg("isSuper"));
cls_TObj_Object.def("GetFatherObject", [](TObj_Object &self) -> opencascade::handle<TObj_Object> { return self.GetFatherObject(); });
cls_TObj_Object.def("GetFatherObject", (opencascade::handle<TObj_Object> (TObj_Object::*)(const opencascade::handle<Standard_Type> &) const) &TObj_Object::GetFatherObject, "Returns the father object, which may be NULL theType gives type of father object to search", py::arg("theType"));
cls_TObj_Object.def("IsAlive", (Standard_Boolean (TObj_Object::*)() const) &TObj_Object::IsAlive, "Checks that object alive in model Default implementation checks that object has TObject attribute at own label.");
cls_TObj_Object.def("Clone", (opencascade::handle<TObj_Object> (TObj_Object::*)(const TDF_Label &, opencascade::handle<TDF_RelocationTable>)) &TObj_Object::Clone, "Copy me to other label theTargetLabel New object will not have all the reference that has me. Coping object with data and childs, but change name by adding string '_copy' As result return handle of new object (null handle is something wrong) NOTE: BackReferences not coping. After clonning all objects it is neccessary to call copy references with the same relocation table", py::arg("theTargetLabel"), py::arg("theRelocTable"));
cls_TObj_Object.def("CopyReferences", (void (TObj_Object::*)(const opencascade::handle<TObj_Object> &, const opencascade::handle<TDF_RelocationTable> &)) &TObj_Object::CopyReferences, "Coping the references. return Standard_False is Target object is different type", py::arg("theTargetObject"), py::arg("theRelocTable"));
cls_TObj_Object.def("CopyChildren", (void (TObj_Object::*)(TDF_Label &, const opencascade::handle<TDF_RelocationTable> &)) &TObj_Object::CopyChildren, "Coping the children from source label to the target.", py::arg("theTargetLabel"), py::arg("theRelocTable"));
cls_TObj_Object.def("GetOrder", (Standard_Integer (TObj_Object::*)() const) &TObj_Object::GetOrder, "returns order of object (or tag of their label if order is not initialised)");
cls_TObj_Object.def("SetOrder", (Standard_Boolean (TObj_Object::*)(const Standard_Integer &)) &TObj_Object::SetOrder, "sets order of object", py::arg("theIndx"));
cls_TObj_Object.def("GetTypeFlags", (Standard_Integer (TObj_Object::*)() const) &TObj_Object::GetTypeFlags, "Returns flags (bitmask) that define properties of objects of that type By default returns flag Visible");
cls_TObj_Object.def("GetFlags", (Standard_Integer (TObj_Object::*)() const) &TObj_Object::GetFlags, "Returns mask of seted flags");
cls_TObj_Object.def("SetFlags", (void (TObj_Object::*)(const Standard_Integer)) &TObj_Object::SetFlags, "Sets flags with defined mask.", py::arg("theMask"));
cls_TObj_Object.def("TestFlags", (Standard_Boolean (TObj_Object::*)(const Standard_Integer) const) &TObj_Object::TestFlags, "tests flags by the mask.", py::arg("theMask"));
cls_TObj_Object.def("ClearFlags", [](TObj_Object &self) -> void { return self.ClearFlags(); });
cls_TObj_Object.def("ClearFlags", (void (TObj_Object::*)(const Standard_Integer)) &TObj_Object::ClearFlags, "clears flags by the mask.", py::arg("theMask"));
cls_TObj_Object.def("AfterRetrieval", (void (TObj_Object::*)()) &TObj_Object::AfterRetrieval, "Preforms updating the links and dependances of the object which are not stored in persistence. Should be redefined if necessary.");
cls_TObj_Object.def("BeforeStoring", (void (TObj_Object::*)()) &TObj_Object::BeforeStoring, "Preforms storing the objects transient fields in OCAF document which were outside transaction mechanism. Default implementation doesnot nothing");
cls_TObj_Object.def_static("get_type_name_", (const char * (*)()) &TObj_Object::get_type_name, "None");
cls_TObj_Object.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_Object::get_type_descriptor, "None");
cls_TObj_Object.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_Object::*)() const) &TObj_Object::DynamicType, "None");

// Enums
py::enum_<TObj_Object::TypeFlags>(cls_TObj_Object, "TypeFlags", "None")
	.value("Visible", TObj_Object::TypeFlags::Visible)
	.export_values();
py::enum_<TObj_Object::ObjectState>(cls_TObj_Object, "ObjectState", "enumeration describing various object state bit flags (see Set/GetFlags())")
	.value("ObjectState_Hidden", TObj_Object::ObjectState::ObjectState_Hidden)
	.value("ObjectState_Saved", TObj_Object::ObjectState::ObjectState_Saved)
	.value("ObjectState_Imported", TObj_Object::ObjectState::ObjectState_Imported)
	.value("ObjectState_ImportedByFile", TObj_Object::ObjectState::ObjectState_ImportedByFile)
	.value("ObjectState_Ordered", TObj_Object::ObjectState::ObjectState_Ordered)
	.export_values();

}