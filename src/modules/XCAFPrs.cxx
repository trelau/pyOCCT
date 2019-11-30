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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <XCAFPrs_Style.hxx>
#include <Quantity_ColorRGBAHasher.hxx>
#include <Quantity_ColorHasher.hxx>
#include <Standard_OStream.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <XCAFPrs_IndexedDataMapOfShapeStyle.hxx>
#include <NCollection_DataMap.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <XCAFPrs_DataMapOfStyleTransient.hxx>
#include <TDF_Label.hxx>
#include <TopLoc_Location.hxx>
#include <XCAFPrs_Driver.hxx>
#include <XCAFPrs.hxx>
#include <AIS_ColoredShape.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_Std.hxx>
#include <XCAFPrs_AISObject.hxx>
#include <Standard_Type.hxx>
#include <XCAFPrs_DataMapOfStyleShape.hxx>
#include <TCollection_AsciiString.hxx>
#include <TDF_ChildIterator.hxx>
#include <XCAFPrs_DocumentNode.hxx>
#include <XCAFPrs_DocumentExplorer.hxx>
#include <TDocStd_Document.hxx>
#include <TDF_LabelSequence.hxx>
#include <Standard_OutOfRange.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include <NCollection_Sequence.hxx>
#include <NCollection_Vector.hxx>
#include <XCAFPrs_DocumentIdIterator.hxx>
#include <TPrsStd_Driver.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Standard_GUID.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(XCAFPrs, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.AIS");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.XCAFDoc");
py::module::import("OCCT.TPrsStd");

// CLASS: XCAFPRS_STYLE
py::class_<XCAFPrs_Style> cls_XCAFPrs_Style(mod, "XCAFPrs_Style", "Represents a set of styling settings applicable to a (sub)shape");

// Constructors
cls_XCAFPrs_Style.def(py::init<>());

// Methods
// cls_XCAFPrs_Style.def_static("operator new_", (void * (*)(size_t)) &XCAFPrs_Style::operator new, "None", py::arg("theSize"));
// cls_XCAFPrs_Style.def_static("operator delete_", (void (*)(void *)) &XCAFPrs_Style::operator delete, "None", py::arg("theAddress"));
// cls_XCAFPrs_Style.def_static("operator new[]_", (void * (*)(size_t)) &XCAFPrs_Style::operator new[], "None", py::arg("theSize"));
// cls_XCAFPrs_Style.def_static("operator delete[]_", (void (*)(void *)) &XCAFPrs_Style::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFPrs_Style.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFPrs_Style::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFPrs_Style.def_static("operator delete_", (void (*)(void *, void *)) &XCAFPrs_Style::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFPrs_Style.def("IsSetColorSurf", (Standard_Boolean (XCAFPrs_Style::*)() const) &XCAFPrs_Style::IsSetColorSurf, "Return TRUE if surface color has been defined.");
cls_XCAFPrs_Style.def("GetColorSurf", (const Quantity_Color & (XCAFPrs_Style::*)() const) &XCAFPrs_Style::GetColorSurf, "Return surface color.");
cls_XCAFPrs_Style.def("SetColorSurf", (void (XCAFPrs_Style::*)(const Quantity_Color &)) &XCAFPrs_Style::SetColorSurf, "Set surface color.", py::arg("theColor"));
cls_XCAFPrs_Style.def("GetColorSurfRGBA", (const Quantity_ColorRGBA & (XCAFPrs_Style::*)() const) &XCAFPrs_Style::GetColorSurfRGBA, "Return surface color.");
cls_XCAFPrs_Style.def("SetColorSurf", (void (XCAFPrs_Style::*)(const Quantity_ColorRGBA &)) &XCAFPrs_Style::SetColorSurf, "Set surface color.", py::arg("theColor"));
cls_XCAFPrs_Style.def("UnSetColorSurf", (void (XCAFPrs_Style::*)()) &XCAFPrs_Style::UnSetColorSurf, "Manage surface color setting");
cls_XCAFPrs_Style.def("IsSetColorCurv", (Standard_Boolean (XCAFPrs_Style::*)() const) &XCAFPrs_Style::IsSetColorCurv, "Return TRUE if curve color has been defined.");
cls_XCAFPrs_Style.def("GetColorCurv", (const Quantity_Color & (XCAFPrs_Style::*)() const) &XCAFPrs_Style::GetColorCurv, "Return curve color.");
cls_XCAFPrs_Style.def("SetColorCurv", (void (XCAFPrs_Style::*)(const Quantity_Color &)) &XCAFPrs_Style::SetColorCurv, "Set curve color.", py::arg("col"));
cls_XCAFPrs_Style.def("UnSetColorCurv", (void (XCAFPrs_Style::*)()) &XCAFPrs_Style::UnSetColorCurv, "Manage curve color setting");
cls_XCAFPrs_Style.def("SetVisibility", (void (XCAFPrs_Style::*)(const Standard_Boolean)) &XCAFPrs_Style::SetVisibility, "Assign visibility.", py::arg("theVisibility"));
cls_XCAFPrs_Style.def("IsVisible", (Standard_Boolean (XCAFPrs_Style::*)() const) &XCAFPrs_Style::IsVisible, "Manage visibility.");
cls_XCAFPrs_Style.def("IsEqual", (Standard_Boolean (XCAFPrs_Style::*)(const XCAFPrs_Style &) const) &XCAFPrs_Style::IsEqual, "Returns True if styles are the same Methods for using Style as key in maps", py::arg("theOther"));
cls_XCAFPrs_Style.def("__eq__", (Standard_Boolean (XCAFPrs_Style::*)(const XCAFPrs_Style &) const) &XCAFPrs_Style::operator==, py::is_operator(), "Returns True if styles are the same.", py::arg("theOther"));
cls_XCAFPrs_Style.def_static("HashCode_", (Standard_Integer (*)(const XCAFPrs_Style &, const Standard_Integer)) &XCAFPrs_Style::HashCode, "Computes a hash code for the given set of styling settings, in the range [1, theUpperBound]", py::arg("theStyle"), py::arg("theUpperBound"));
cls_XCAFPrs_Style.def_static("IsEqual_", (Standard_Boolean (*)(const XCAFPrs_Style &, const XCAFPrs_Style &)) &XCAFPrs_Style::IsEqual, "Returns True when the two keys are the same.", py::arg("theS1"), py::arg("theS2"));
cls_XCAFPrs_Style.def("DumpJson", [](XCAFPrs_Style &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_XCAFPrs_Style.def("DumpJson", (void (XCAFPrs_Style::*)(Standard_OStream &, const Standard_Integer) const) &XCAFPrs_Style::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));

// TYPEDEF: XCAFPRS_INDEXEDDATAMAPOFSHAPESTYLE
bind_NCollection_IndexedDataMap<TopoDS_Shape, XCAFPrs_Style, TopTools_ShapeMapHasher>(mod, "XCAFPrs_IndexedDataMapOfShapeStyle", py::module_local(false));

// TYPEDEF: XCAFPRS_DATAMAPITERATOROFINDEXEDDATAMAPOFSHAPESTYLE

// TYPEDEF: XCAFPRS_DATAMAPOFSTYLETRANSIENT
bind_NCollection_DataMap<XCAFPrs_Style, opencascade::handle<Standard_Transient>, XCAFPrs_Style>(mod, "XCAFPrs_DataMapOfStyleTransient", py::module_local(false));

// TYPEDEF: XCAFPRS_DATAMAPITERATOROFDATAMAPOFSTYLETRANSIENT

// CLASS: XCAFPRS
py::class_<XCAFPrs> cls_XCAFPrs(mod, "XCAFPrs", "Presentation (visualiation, selection etc.) tools for DECAF documents");

// Constructors
cls_XCAFPrs.def(py::init<>());

// Methods
// cls_XCAFPrs.def_static("operator new_", (void * (*)(size_t)) &XCAFPrs::operator new, "None", py::arg("theSize"));
// cls_XCAFPrs.def_static("operator delete_", (void (*)(void *)) &XCAFPrs::operator delete, "None", py::arg("theAddress"));
// cls_XCAFPrs.def_static("operator new[]_", (void * (*)(size_t)) &XCAFPrs::operator new[], "None", py::arg("theSize"));
// cls_XCAFPrs.def_static("operator delete[]_", (void (*)(void *)) &XCAFPrs::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFPrs.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFPrs::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFPrs.def_static("operator delete_", (void (*)(void *, void *)) &XCAFPrs::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFPrs.def_static("CollectStyleSettings_", [](const TDF_Label & a0, const TopLoc_Location & a1, XCAFPrs_IndexedDataMapOfShapeStyle & a2) -> void { return XCAFPrs::CollectStyleSettings(a0, a1, a2); });
cls_XCAFPrs.def_static("CollectStyleSettings_", (void (*)(const TDF_Label &, const TopLoc_Location &, XCAFPrs_IndexedDataMapOfShapeStyle &, const Quantity_ColorRGBA &)) &XCAFPrs::CollectStyleSettings, "Collect styles defined for shape on label L and its components and subshapes and fills a map of shape - style correspondence The location <loc> is for internal use, it should be Null location for external call", py::arg("L"), py::arg("loc"), py::arg("settings"), py::arg("theLayerColor"));
cls_XCAFPrs.def_static("SetViewNameMode_", (void (*)(const Standard_Boolean)) &XCAFPrs::SetViewNameMode, "Set ViewNameMode for indicate display names or not.", py::arg("viewNameMode"));
cls_XCAFPrs.def_static("GetViewNameMode_", (Standard_Boolean (*)()) &XCAFPrs::GetViewNameMode, "None");

// CLASS: XCAFPRS_AISOBJECT
py::class_<XCAFPrs_AISObject, opencascade::handle<XCAFPrs_AISObject>, AIS_ColoredShape> cls_XCAFPrs_AISObject(mod, "XCAFPrs_AISObject", "Implements AIS_InteractiveObject functionality for shape in DECAF document.");

// Constructors
cls_XCAFPrs_AISObject.def(py::init<const TDF_Label &>(), py::arg("theLabel"));

// Methods
cls_XCAFPrs_AISObject.def("GetLabel", (const TDF_Label & (XCAFPrs_AISObject::*)() const) &XCAFPrs_AISObject::GetLabel, "Returns the label which was visualised by this presentation");
cls_XCAFPrs_AISObject.def("SetLabel", (void (XCAFPrs_AISObject::*)(const TDF_Label &)) &XCAFPrs_AISObject::SetLabel, "Assign the label to this presentation (but does not mark it outdated with SetToUpdate()).", py::arg("theLabel"));
cls_XCAFPrs_AISObject.def("DispatchStyles", [](XCAFPrs_AISObject &self) -> void { return self.DispatchStyles(); });
cls_XCAFPrs_AISObject.def("DispatchStyles", (void (XCAFPrs_AISObject::*)(const Standard_Boolean)) &XCAFPrs_AISObject::DispatchStyles, "Fetch the Shape from associated Label and fill the map of sub-shapes styles. By default, this method is called implicitly within first ::Compute(). Application might call this method explicitly to manipulate styles afterwards.", py::arg("theToSyncStyles"));
cls_XCAFPrs_AISObject.def("SetMaterial", (void (XCAFPrs_AISObject::*)(const Graphic3d_MaterialAspect &)) &XCAFPrs_AISObject::SetMaterial, "Sets the material aspect. This method assigns the new default material without overriding XDE styles. Re-computation of existing presentation is not required after calling this method.", py::arg("theMaterial"));
cls_XCAFPrs_AISObject.def_static("get_type_name_", (const char * (*)()) &XCAFPrs_AISObject::get_type_name, "None");
cls_XCAFPrs_AISObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFPrs_AISObject::get_type_descriptor, "None");
cls_XCAFPrs_AISObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFPrs_AISObject::*)() const) &XCAFPrs_AISObject::DynamicType, "None");

// TYPEDEF: XCAFPRS_DATAMAPOFSTYLESHAPE
bind_NCollection_DataMap<XCAFPrs_Style, TopoDS_Shape, XCAFPrs_Style>(mod, "XCAFPrs_DataMapOfStyleShape", py::module_local(false));

// TYPEDEF: XCAFPRS_DATAMAPITERATOROFDATAMAPOFSTYLESHAPE

// CLASS: XCAFPRS_DOCUMENTNODE
py::class_<XCAFPrs_DocumentNode> cls_XCAFPrs_DocumentNode(mod, "XCAFPrs_DocumentNode", "Structure defining document node.");

// Constructors
cls_XCAFPrs_DocumentNode.def(py::init<>());

// Fields
cls_XCAFPrs_DocumentNode.def_readwrite("Id", &XCAFPrs_DocumentNode::Id, "string identifier");
cls_XCAFPrs_DocumentNode.def_readwrite("Label", &XCAFPrs_DocumentNode::Label, "label in the document");
cls_XCAFPrs_DocumentNode.def_readwrite("RefLabel", &XCAFPrs_DocumentNode::RefLabel, "reference label in the document");
cls_XCAFPrs_DocumentNode.def_readwrite("Style", &XCAFPrs_DocumentNode::Style, "node style");
cls_XCAFPrs_DocumentNode.def_readwrite("Location", &XCAFPrs_DocumentNode::Location, "node global transformation");
cls_XCAFPrs_DocumentNode.def_readwrite("LocalTrsf", &XCAFPrs_DocumentNode::LocalTrsf, "node transformation relative to parent");
cls_XCAFPrs_DocumentNode.def_readwrite("ChildIter", &XCAFPrs_DocumentNode::ChildIter, "child iterator");
cls_XCAFPrs_DocumentNode.def_readwrite("IsAssembly", &XCAFPrs_DocumentNode::IsAssembly, "flag indicating that this label is assembly");

// TYPEDEF: XCAFPRS_DOCUMENTEXPLORERFLAGS

// CLASS: XCAFPRS_DOCUMENTEXPLORER
py::class_<XCAFPrs_DocumentExplorer> cls_XCAFPrs_DocumentExplorer(mod, "XCAFPrs_DocumentExplorer", "Document iterator through shape nodes.");

// Constructors
cls_XCAFPrs_DocumentExplorer.def(py::init<>());
cls_XCAFPrs_DocumentExplorer.def(py::init<const opencascade::handle<TDocStd_Document> &, const XCAFPrs_DocumentExplorerFlags>(), py::arg("theDocument"), py::arg("theFlags"));
cls_XCAFPrs_DocumentExplorer.def(py::init<const opencascade::handle<TDocStd_Document> &, const XCAFPrs_DocumentExplorerFlags, const XCAFPrs_Style &>(), py::arg("theDocument"), py::arg("theFlags"), py::arg("theDefStyle"));
cls_XCAFPrs_DocumentExplorer.def(py::init<const opencascade::handle<TDocStd_Document> &, const TDF_LabelSequence &, const XCAFPrs_DocumentExplorerFlags>(), py::arg("theDocument"), py::arg("theRoots"), py::arg("theFlags"));
cls_XCAFPrs_DocumentExplorer.def(py::init<const opencascade::handle<TDocStd_Document> &, const TDF_LabelSequence &, const XCAFPrs_DocumentExplorerFlags, const XCAFPrs_Style &>(), py::arg("theDocument"), py::arg("theRoots"), py::arg("theFlags"), py::arg("theDefStyle"));

// Methods
cls_XCAFPrs_DocumentExplorer.def_static("DefineChildId_", (TCollection_AsciiString (*)(const TDF_Label &, const TCollection_AsciiString &)) &XCAFPrs_DocumentExplorer::DefineChildId, "Construct a unique string identifier for the given label. The identifier is a concatenation of label entries (TDF_Tool::Entry() with tailing '.') of hierarchy from parent to child joined via '/' and looking like this: This generation scheme also allows finding originating labels using TDF_Tool::Label(). The tailing dot simplifies parent equality check.", py::arg("theLabel"), py::arg("theParentId"));
cls_XCAFPrs_DocumentExplorer.def_static("FindLabelFromPathId_", (TDF_Label (*)(const opencascade::handle<TDocStd_Document> &, const TCollection_AsciiString &, TopLoc_Location &, TopLoc_Location &)) &XCAFPrs_DocumentExplorer::FindLabelFromPathId, "Find a shape entity based on a text identifier constructed from OCAF labels defining full path.", py::arg("theDocument"), py::arg("theId"), py::arg("theParentLocation"), py::arg("theLocation"));
cls_XCAFPrs_DocumentExplorer.def_static("FindLabelFromPathId_", (TDF_Label (*)(const opencascade::handle<TDocStd_Document> &, const TCollection_AsciiString &, TopLoc_Location &)) &XCAFPrs_DocumentExplorer::FindLabelFromPathId, "Find a shape entity based on a text identifier constructed from OCAF labels defining full path.", py::arg("theDocument"), py::arg("theId"), py::arg("theLocation"));
cls_XCAFPrs_DocumentExplorer.def_static("FindShapeFromPathId_", (TopoDS_Shape (*)(const opencascade::handle<TDocStd_Document> &, const TCollection_AsciiString &)) &XCAFPrs_DocumentExplorer::FindShapeFromPathId, "Find a shape entity based on a text identifier constructed from OCAF labels defining full path.", py::arg("theDocument"), py::arg("theId"));
cls_XCAFPrs_DocumentExplorer.def("Init", [](XCAFPrs_DocumentExplorer &self, const opencascade::handle<TDocStd_Document> & a0, const TDF_Label & a1, const XCAFPrs_DocumentExplorerFlags a2) -> void { return self.Init(a0, a1, a2); });
cls_XCAFPrs_DocumentExplorer.def("Init", (void (XCAFPrs_DocumentExplorer::*)(const opencascade::handle<TDocStd_Document> &, const TDF_Label &, const XCAFPrs_DocumentExplorerFlags, const XCAFPrs_Style &)) &XCAFPrs_DocumentExplorer::Init, "Initialize the iterator from a single root shape in the document.", py::arg("theDocument"), py::arg("theRoot"), py::arg("theFlags"), py::arg("theDefStyle"));
cls_XCAFPrs_DocumentExplorer.def("Init", [](XCAFPrs_DocumentExplorer &self, const opencascade::handle<TDocStd_Document> & a0, const TDF_LabelSequence & a1, const XCAFPrs_DocumentExplorerFlags a2) -> void { return self.Init(a0, a1, a2); });
cls_XCAFPrs_DocumentExplorer.def("Init", (void (XCAFPrs_DocumentExplorer::*)(const opencascade::handle<TDocStd_Document> &, const TDF_LabelSequence &, const XCAFPrs_DocumentExplorerFlags, const XCAFPrs_Style &)) &XCAFPrs_DocumentExplorer::Init, "Initialize the iterator from the list of root shapes in the document.", py::arg("theDocument"), py::arg("theRoots"), py::arg("theFlags"), py::arg("theDefStyle"));
cls_XCAFPrs_DocumentExplorer.def("More", (Standard_Boolean (XCAFPrs_DocumentExplorer::*)() const) &XCAFPrs_DocumentExplorer::More, "Return TRUE if iterator points to the valid node.");
cls_XCAFPrs_DocumentExplorer.def("Current", (const XCAFPrs_DocumentNode & (XCAFPrs_DocumentExplorer::*)() const) &XCAFPrs_DocumentExplorer::Current, "Return current position.");
cls_XCAFPrs_DocumentExplorer.def("ChangeCurrent", (XCAFPrs_DocumentNode & (XCAFPrs_DocumentExplorer::*)()) &XCAFPrs_DocumentExplorer::ChangeCurrent, "Return current position.");
cls_XCAFPrs_DocumentExplorer.def("Current", (const XCAFPrs_DocumentNode & (XCAFPrs_DocumentExplorer::*)(Standard_Integer) const) &XCAFPrs_DocumentExplorer::Current, "Return current position within specified assembly depth.", py::arg("theDepth"));
cls_XCAFPrs_DocumentExplorer.def("CurrentDepth", (Standard_Integer (XCAFPrs_DocumentExplorer::*)() const) &XCAFPrs_DocumentExplorer::CurrentDepth, "Return depth of the current node in hierarchy, starting from 0. Zero means Root label.");
cls_XCAFPrs_DocumentExplorer.def("Next", (void (XCAFPrs_DocumentExplorer::*)()) &XCAFPrs_DocumentExplorer::Next, "Go to the next node.");

// CLASS: XCAFPRS_DOCUMENTIDITERATOR
py::class_<XCAFPrs_DocumentIdIterator> cls_XCAFPrs_DocumentIdIterator(mod, "XCAFPrs_DocumentIdIterator", "Auxiliary tool for iterating through Path identification string.");

// Constructors
cls_XCAFPrs_DocumentIdIterator.def(py::init<const TCollection_AsciiString &>(), py::arg("thePath"));

// Methods
cls_XCAFPrs_DocumentIdIterator.def("More", (bool (XCAFPrs_DocumentIdIterator::*)() const) &XCAFPrs_DocumentIdIterator::More, "Return TRUE if iterator points to a value.");
cls_XCAFPrs_DocumentIdIterator.def("Value", (const TCollection_AsciiString & (XCAFPrs_DocumentIdIterator::*)() const) &XCAFPrs_DocumentIdIterator::Value, "Return current value.");
cls_XCAFPrs_DocumentIdIterator.def("Next", (void (XCAFPrs_DocumentIdIterator::*)()) &XCAFPrs_DocumentIdIterator::Next, "Find the next value.");

// CLASS: XCAFPRS_DRIVER
py::class_<XCAFPrs_Driver, opencascade::handle<XCAFPrs_Driver>, TPrsStd_Driver> cls_XCAFPrs_Driver(mod, "XCAFPrs_Driver", "Implements a driver for presentation of shapes in DECAF document. Its the only purpose is to initialize and return XCAFPrs_AISObject object on request");

// Constructors
cls_XCAFPrs_Driver.def(py::init<>());

// Methods
cls_XCAFPrs_Driver.def("Update", (Standard_Boolean (XCAFPrs_Driver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &XCAFPrs_Driver::Update, "None", py::arg("L"), py::arg("ais"));
cls_XCAFPrs_Driver.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFPrs_Driver::GetID, "returns GUID of the driver");
cls_XCAFPrs_Driver.def_static("get_type_name_", (const char * (*)()) &XCAFPrs_Driver::get_type_name, "None");
cls_XCAFPrs_Driver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFPrs_Driver::get_type_descriptor, "None");
cls_XCAFPrs_Driver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFPrs_Driver::*)() const) &XCAFPrs_Driver::DynamicType, "None");


}
