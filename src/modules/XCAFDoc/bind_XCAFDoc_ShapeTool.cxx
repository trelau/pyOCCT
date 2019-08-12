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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TDF_LabelSequence.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_OStream.hxx>
#include <TDF_RelocationTable.hxx>
#include <TColStd_SequenceOfHAsciiString.hxx>
#include <XCAFDoc_GraphNode.hxx>
#include <TDF_AttributeSequence.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <Standard_Type.hxx>
#include <XCAFDoc_DataMapOfShapeLabel.hxx>

void bind_XCAFDoc_ShapeTool(py::module &mod){

py::class_<XCAFDoc_ShapeTool, opencascade::handle<XCAFDoc_ShapeTool>, TDF_Attribute> cls_XCAFDoc_ShapeTool(mod, "XCAFDoc_ShapeTool", "A tool to store shapes in an XDE document in the form of assembly structure, and to maintain this structure. Attribute containing Shapes section of DECAF document. Provide tools for management of Shapes section. The API provided by this class allows to work with this structure regardless of its low-level implementation. All the shapes are stored on child labels of a main label which is XCAFDoc_DocumentTool::LabelShapes(). The label for assembly also has sub-labels, each of which represents the instance of another shape in that assembly (component). Such sub-label stores reference to the label of the original shape in the form of TDataStd_TreeNode with GUID XCAFDoc::ShapeRefGUID(), and its location encapsulated into the NamedShape. For correct work with an XDE document, it is necessary to use methods for analysis and methods for working with shapes. For example: if ( STool->IsAssembly(aLabel) ) { Standard_Boolean subchilds = Standard_False; (default) Standard_Integer nbc = STool->NbComponents (aLabel[,subchilds]); } If subchilds is True, commands also consider sub-levels. By default, only level one is checked. In this example, number of children from the first level of assembly will be returned. Methods for creation and initialization: Constructor: XCAFDoc_ShapeTool::XCAFDoc_ShapeTool() Getting a guid: Standard_GUID GetID (); Creation (if does not exist) of ShapeTool on label L: Handle(XCAFDoc_ShapeTool) XCAFDoc_ShapeTool::Set(const TDF_Label& L) Analyze whether shape is a simple shape or an instance or a component of an assembly or it is an assembly ( methods of analysis). For example: STool->IsShape(aLabel) ; Analyze that the label represents a shape (simple shape, assembly or reference) or STool->IsTopLevel(aLabel); Analyze that the label is a label of a top-level shape. Work with simple shapes, assemblies and instances ( methods for work with shapes). For example: Add shape: Standard_Boolean makeAssembly; // True to interpret a Compound as an Assembly, False to take it as a whole aLabel = STool->AddShape(aShape, makeAssembly); Get shape: TDF_Label aLabel... // A label must be present if (aLabel.IsNull()) { ... no such label : abandon .. } TopoDS_Shape aShape; aShape = STool->GetShape(aLabel); if (aShape.IsNull()) { ... this label is not for a Shape ... } To get a label from shape. Standard_Boolean findInstance = Standard_False; (this is default value) aLabel = STool->FindShape(aShape [,findInstance]); if (aLabel.IsNull()) { ... no label found for this shape ... }");

// Constructors
cls_XCAFDoc_ShapeTool.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_ShapeTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_ShapeTool::GetID, "None");
cls_XCAFDoc_ShapeTool.def_static("Set_", (opencascade::handle<XCAFDoc_ShapeTool> (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::Set, "Create (if not exist) ShapeTool from XCAFDoc on <L>.", py::arg("L"));
cls_XCAFDoc_ShapeTool.def("IsTopLevel", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TDF_Label &) const) &XCAFDoc_ShapeTool::IsTopLevel, "Returns True if the label is a label of top-level shape, as opposed to component of assembly or subshape", py::arg("L"));
cls_XCAFDoc_ShapeTool.def_static("IsFree_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::IsFree, "Returns True if the label is not used by any assembly, i.e. contains sublabels which are assembly components This is relevant only if IsShape() is True (There is no Father TreeNode on this <L>)", py::arg("L"));
cls_XCAFDoc_ShapeTool.def_static("IsShape_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::IsShape, "Returns True if the label represents a shape (simple shape, assembly or reference)", py::arg("L"));
cls_XCAFDoc_ShapeTool.def_static("IsSimpleShape_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::IsSimpleShape, "Returns True if the label is a label of simple shape", py::arg("L"));
cls_XCAFDoc_ShapeTool.def_static("IsReference_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::IsReference, "Return true if <L> is a located instance of other shape i.e. reference", py::arg("L"));
cls_XCAFDoc_ShapeTool.def_static("IsAssembly_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::IsAssembly, "Returns True if the label is a label of assembly, i.e. contains sublabels which are assembly components This is relevant only if IsShape() is True", py::arg("L"));
cls_XCAFDoc_ShapeTool.def_static("IsComponent_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::IsComponent, "Return true if <L> is reference serving as component of assembly", py::arg("L"));
cls_XCAFDoc_ShapeTool.def_static("IsCompound_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::IsCompound, "Returns True if the label is a label of compound, i.e. contains some sublabels This is relevant only if IsShape() is True", py::arg("L"));
cls_XCAFDoc_ShapeTool.def_static("IsSubShape_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::IsSubShape, "Return true if <L> is subshape of the top-level shape", py::arg("L"));
cls_XCAFDoc_ShapeTool.def("IsSubShape", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &) const) &XCAFDoc_ShapeTool::IsSubShape, "Checks whether shape is subshape of shape stored on label shapeL", py::arg("shapeL"), py::arg("sub"));
cls_XCAFDoc_ShapeTool.def("SearchUsingMap", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &, TDF_Label &, const Standard_Boolean, const Standard_Boolean) const) &XCAFDoc_ShapeTool::SearchUsingMap, "None", py::arg("S"), py::arg("L"), py::arg("findWithoutLoc"), py::arg("findSubshape"));
cls_XCAFDoc_ShapeTool.def("Search", [](XCAFDoc_ShapeTool &self, const TopoDS_Shape & a0, TDF_Label & a1) -> Standard_Boolean { return self.Search(a0, a1); });
cls_XCAFDoc_ShapeTool.def("Search", [](XCAFDoc_ShapeTool &self, const TopoDS_Shape & a0, TDF_Label & a1, const Standard_Boolean a2) -> Standard_Boolean { return self.Search(a0, a1, a2); });
cls_XCAFDoc_ShapeTool.def("Search", [](XCAFDoc_ShapeTool &self, const TopoDS_Shape & a0, TDF_Label & a1, const Standard_Boolean a2, const Standard_Boolean a3) -> Standard_Boolean { return self.Search(a0, a1, a2, a3); });
cls_XCAFDoc_ShapeTool.def("Search", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &, TDF_Label &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean) const) &XCAFDoc_ShapeTool::Search, "General tool to find a (sub) shape in the document * If findInstance is True, and S has a non-null location, first tries to find the shape among the top-level shapes with this location * If not found, and findComponent is True, tries to find the shape among the components of assemblies * If not found, tries to find the shape without location among top-level shapes * If not found and findSubshape is True, tries to find a shape as a subshape of top-level simple shapes Returns False if nothing is found", py::arg("S"), py::arg("L"), py::arg("findInstance"), py::arg("findComponent"), py::arg("findSubshape"));
cls_XCAFDoc_ShapeTool.def("FindShape", [](XCAFDoc_ShapeTool &self, const TopoDS_Shape & a0, TDF_Label & a1) -> Standard_Boolean { return self.FindShape(a0, a1); });
cls_XCAFDoc_ShapeTool.def("FindShape", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &, TDF_Label &, const Standard_Boolean) const) &XCAFDoc_ShapeTool::FindShape, "Returns the label corresponding to shape S (searches among top-level shapes, not including subcomponents of assemblies) If findInstance is False (default), searches for the non-located shape (i.e. among original shapes) If findInstance is True, searches for the shape with the same location, including shape instances Return True if <S> is found.", py::arg("S"), py::arg("L"), py::arg("findInstance"));
cls_XCAFDoc_ShapeTool.def("FindShape", [](XCAFDoc_ShapeTool &self, const TopoDS_Shape & a0) -> TDF_Label { return self.FindShape(a0); });
cls_XCAFDoc_ShapeTool.def("FindShape", (TDF_Label (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &, const Standard_Boolean) const) &XCAFDoc_ShapeTool::FindShape, "Does the same as previous method Returns Null label if not found", py::arg("S"), py::arg("findInstance"));
cls_XCAFDoc_ShapeTool.def_static("GetShape_", (Standard_Boolean (*)(const TDF_Label &, TopoDS_Shape &)) &XCAFDoc_ShapeTool::GetShape, "To get TopoDS_Shape from shape's label For component, returns new shape with correct location Returns False if label does not contain shape", py::arg("L"), py::arg("S"));
cls_XCAFDoc_ShapeTool.def_static("GetShape_", (TopoDS_Shape (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::GetShape, "To get TopoDS_Shape from shape's label For component, returns new shape with correct location Returns Null shape if label does not contain shape", py::arg("L"));
cls_XCAFDoc_ShapeTool.def("NewShape", (TDF_Label (XCAFDoc_ShapeTool::*)() const) &XCAFDoc_ShapeTool::NewShape, "Creates new (empty) top-level shape. Initially it holds empty TopoDS_Compound");
cls_XCAFDoc_ShapeTool.def("SetShape", (void (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &)) &XCAFDoc_ShapeTool::SetShape, "Sets representation (TopoDS_Shape) for top-level shape.", py::arg("L"), py::arg("S"));
cls_XCAFDoc_ShapeTool.def("AddShape", [](XCAFDoc_ShapeTool &self, const TopoDS_Shape & a0) -> TDF_Label { return self.AddShape(a0); });
cls_XCAFDoc_ShapeTool.def("AddShape", [](XCAFDoc_ShapeTool &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> TDF_Label { return self.AddShape(a0, a1); });
cls_XCAFDoc_ShapeTool.def("AddShape", (TDF_Label (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &XCAFDoc_ShapeTool::AddShape, "Adds a new top-level (creates and returns a new label) If makeAssembly is True, treats TopAbs_COMPOUND shapes as assemblies (creates assembly structure). NOTE: <makePrepare> replace components without location in assmebly by located components to avoid some problems. If AutoNaming() is True then automatically attaches names.", py::arg("S"), py::arg("makeAssembly"), py::arg("makePrepare"));
cls_XCAFDoc_ShapeTool.def("RemoveShape", [](XCAFDoc_ShapeTool &self, const TDF_Label & a0) -> Standard_Boolean { return self.RemoveShape(a0); });
cls_XCAFDoc_ShapeTool.def("RemoveShape", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TDF_Label &, const Standard_Boolean) const) &XCAFDoc_ShapeTool::RemoveShape, "Removes shape (whole label and all its sublabels) If removeCompletely is true, removes complete shape If removeCompletely is false, removes instance(location) only Returns False (and does nothing) if shape is not free or is not top-level shape", py::arg("L"), py::arg("removeCompletely"));
cls_XCAFDoc_ShapeTool.def("Init", (void (XCAFDoc_ShapeTool::*)()) &XCAFDoc_ShapeTool::Init, "set hasComponents into false");
cls_XCAFDoc_ShapeTool.def_static("SetAutoNaming_", (void (*)(const Standard_Boolean)) &XCAFDoc_ShapeTool::SetAutoNaming, "Sets auto-naming mode to <V>. If True then for added shapes, links, assemblies and SHUO's, the TDataStd_Name attribute is automatically added. For shapes it contains a shape type (e.g. 'SOLID', 'SHELL', etc); for links it has a form '=>[0:1:1:2]' (where a tag is a label containing a shape without a location); for assemblies it is 'ASSEMBLY', and 'SHUO' for SHUO's. This setting is global; it cannot be made a member function as it is used by static methods as well. By default, auto-naming is enabled. See also AutoNaming().", py::arg("V"));
cls_XCAFDoc_ShapeTool.def_static("AutoNaming_", (Standard_Boolean (*)()) &XCAFDoc_ShapeTool::AutoNaming, "Returns current auto-naming mode. See SetAutoNaming() for description.");
cls_XCAFDoc_ShapeTool.def("ComputeShapes", (void (XCAFDoc_ShapeTool::*)(const TDF_Label &)) &XCAFDoc_ShapeTool::ComputeShapes, "recursive", py::arg("L"));
cls_XCAFDoc_ShapeTool.def("ComputeSimpleShapes", (void (XCAFDoc_ShapeTool::*)()) &XCAFDoc_ShapeTool::ComputeSimpleShapes, "Compute a sequence of simple shapes");
cls_XCAFDoc_ShapeTool.def("GetShapes", (void (XCAFDoc_ShapeTool::*)(TDF_LabelSequence &) const) &XCAFDoc_ShapeTool::GetShapes, "Returns a sequence of all top-level shapes", py::arg("Labels"));
cls_XCAFDoc_ShapeTool.def("GetFreeShapes", (void (XCAFDoc_ShapeTool::*)(TDF_LabelSequence &) const) &XCAFDoc_ShapeTool::GetFreeShapes, "Returns a sequence of all top-level shapes which are free (i.e. not referred by any other)", py::arg("FreeLabels"));
cls_XCAFDoc_ShapeTool.def_static("GetUsers_", [](const TDF_Label & a0, TDF_LabelSequence & a1) -> Standard_Integer { return XCAFDoc_ShapeTool::GetUsers(a0, a1); });
cls_XCAFDoc_ShapeTool.def_static("GetUsers_", (Standard_Integer (*)(const TDF_Label &, TDF_LabelSequence &, const Standard_Boolean)) &XCAFDoc_ShapeTool::GetUsers, "Returns list of labels which refer shape L as component Returns number of users (0 if shape is free)", py::arg("L"), py::arg("Labels"), py::arg("getsubchilds"));
cls_XCAFDoc_ShapeTool.def_static("GetLocation_", (TopLoc_Location (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::GetLocation, "Returns location of instance", py::arg("L"));
cls_XCAFDoc_ShapeTool.def_static("GetReferredShape_", (Standard_Boolean (*)(const TDF_Label &, TDF_Label &)) &XCAFDoc_ShapeTool::GetReferredShape, "Returns label which corresponds to a shape referred by L Returns False if label is not reference", py::arg("L"), py::arg("Label"));
cls_XCAFDoc_ShapeTool.def_static("NbComponents_", [](const TDF_Label & a0) -> Standard_Integer { return XCAFDoc_ShapeTool::NbComponents(a0); });
cls_XCAFDoc_ShapeTool.def_static("NbComponents_", (Standard_Integer (*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_ShapeTool::NbComponents, "Returns number of Assembles components", py::arg("L"), py::arg("getsubchilds"));
cls_XCAFDoc_ShapeTool.def_static("GetComponents_", [](const TDF_Label & a0, TDF_LabelSequence & a1) -> Standard_Boolean { return XCAFDoc_ShapeTool::GetComponents(a0, a1); });
cls_XCAFDoc_ShapeTool.def_static("GetComponents_", (Standard_Boolean (*)(const TDF_Label &, TDF_LabelSequence &, const Standard_Boolean)) &XCAFDoc_ShapeTool::GetComponents, "Returns list of components of assembly Returns False if label is not assembly", py::arg("L"), py::arg("Labels"), py::arg("getsubchilds"));
cls_XCAFDoc_ShapeTool.def("AddComponent", (TDF_Label (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TDF_Label &, const TopLoc_Location &) const) &XCAFDoc_ShapeTool::AddComponent, "Adds a component given by its label and location to the assembly Note: assembly must be IsAssembly() or IsSimpleShape()", py::arg("assembly"), py::arg("comp"), py::arg("Loc"));
cls_XCAFDoc_ShapeTool.def("AddComponent", [](XCAFDoc_ShapeTool &self, const TDF_Label & a0, const TopoDS_Shape & a1) -> TDF_Label { return self.AddComponent(a0, a1); });
cls_XCAFDoc_ShapeTool.def("AddComponent", (TDF_Label (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &, const Standard_Boolean)) &XCAFDoc_ShapeTool::AddComponent, "Adds a shape (located) as a component to the assembly If necessary, creates an additional top-level shape for component and return the Label of component. If expand is True and component is Compound, it will be created as assembly also Note: assembly must be IsAssembly() or IsSimpleShape()", py::arg("assembly"), py::arg("comp"), py::arg("expand"));
cls_XCAFDoc_ShapeTool.def("RemoveComponent", (void (XCAFDoc_ShapeTool::*)(const TDF_Label &) const) &XCAFDoc_ShapeTool::RemoveComponent, "Removes a component from its assembly", py::arg("comp"));
cls_XCAFDoc_ShapeTool.def("UpdateAssemblies", (void (XCAFDoc_ShapeTool::*)()) &XCAFDoc_ShapeTool::UpdateAssemblies, "Top-down update for all assembly compounds stored in the document.");
cls_XCAFDoc_ShapeTool.def("FindSubShape", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &, TDF_Label &) const) &XCAFDoc_ShapeTool::FindSubShape, "Finds a label for subshape of shape stored on label shapeL Returns Null label if it is not found", py::arg("shapeL"), py::arg("sub"), py::arg("L"));
cls_XCAFDoc_ShapeTool.def("AddSubShape", (TDF_Label (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &) const) &XCAFDoc_ShapeTool::AddSubShape, "Adds a label for subshape of shape stored on label shapeL Returns Null label if it is not subshape", py::arg("shapeL"), py::arg("sub"));
cls_XCAFDoc_ShapeTool.def("FindMainShapeUsingMap", (TDF_Label (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &) const) &XCAFDoc_ShapeTool::FindMainShapeUsingMap, "None", py::arg("sub"));
cls_XCAFDoc_ShapeTool.def("FindMainShape", (TDF_Label (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &) const) &XCAFDoc_ShapeTool::FindMainShape, "Performs a search among top-level shapes to find the shape containing as subshape Checks only simple shapes, and returns the first found label (which should be the only one for valid model)", py::arg("sub"));
cls_XCAFDoc_ShapeTool.def_static("GetSubShapes_", (Standard_Boolean (*)(const TDF_Label &, TDF_LabelSequence &)) &XCAFDoc_ShapeTool::GetSubShapes, "Returns list of labels identifying subshapes of the given shape Returns False if no subshapes are placed on that label", py::arg("L"), py::arg("Labels"));
cls_XCAFDoc_ShapeTool.def("BaseLabel", (TDF_Label (XCAFDoc_ShapeTool::*)() const) &XCAFDoc_ShapeTool::BaseLabel, "returns the label under which shapes are stored");
cls_XCAFDoc_ShapeTool.def("Dump", (Standard_OStream & (XCAFDoc_ShapeTool::*)(Standard_OStream &, const Standard_Boolean) const) &XCAFDoc_ShapeTool::Dump, "None", py::arg("theDumpLog"), py::arg("deep"));
cls_XCAFDoc_ShapeTool.def("Dump", (Standard_OStream & (XCAFDoc_ShapeTool::*)(Standard_OStream &) const) &XCAFDoc_ShapeTool::Dump, "None", py::arg("theDumpLog"));
cls_XCAFDoc_ShapeTool.def_static("DumpShape_", [](Standard_OStream & a0, const TDF_Label & a1) -> void { return XCAFDoc_ShapeTool::DumpShape(a0, a1); });
cls_XCAFDoc_ShapeTool.def_static("DumpShape_", [](Standard_OStream & a0, const TDF_Label & a1, const Standard_Integer a2) -> void { return XCAFDoc_ShapeTool::DumpShape(a0, a1, a2); });
cls_XCAFDoc_ShapeTool.def_static("DumpShape_", (void (*)(Standard_OStream &, const TDF_Label &, const Standard_Integer, const Standard_Boolean)) &XCAFDoc_ShapeTool::DumpShape, "Print to ostream <theDumpLog> type of shape found on <L> label and the entry of <L>, with <level> tabs before. If <deep>, print also TShape and Location addresses", py::arg("theDumpLog"), py::arg("L"), py::arg("level"), py::arg("deep"));
cls_XCAFDoc_ShapeTool.def("ID", (const Standard_GUID & (XCAFDoc_ShapeTool::*)() const) &XCAFDoc_ShapeTool::ID, "None");
cls_XCAFDoc_ShapeTool.def("Restore", (void (XCAFDoc_ShapeTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_ShapeTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_ShapeTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_ShapeTool::*)() const) &XCAFDoc_ShapeTool::NewEmpty, "None");
cls_XCAFDoc_ShapeTool.def("Paste", (void (XCAFDoc_ShapeTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_ShapeTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_ShapeTool.def_static("IsExternRef_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_ShapeTool::IsExternRef, "Returns True if the label is a label of external references, i.e. there are some reference on the no-step files, which are described in document only their names", py::arg("L"));
cls_XCAFDoc_ShapeTool.def("SetExternRefs", (TDF_Label (XCAFDoc_ShapeTool::*)(const TColStd_SequenceOfHAsciiString &) const) &XCAFDoc_ShapeTool::SetExternRefs, "Sets the names of references on the no-step files", py::arg("SHAS"));
cls_XCAFDoc_ShapeTool.def("SetExternRefs", (void (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TColStd_SequenceOfHAsciiString &) const) &XCAFDoc_ShapeTool::SetExternRefs, "Sets the names of references on the no-step files", py::arg("L"), py::arg("SHAS"));
cls_XCAFDoc_ShapeTool.def_static("GetExternRefs_", (void (*)(const TDF_Label &, TColStd_SequenceOfHAsciiString &)) &XCAFDoc_ShapeTool::GetExternRefs, "Gets the names of references on the no-step files", py::arg("L"), py::arg("SHAS"));
cls_XCAFDoc_ShapeTool.def("SetSHUO", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TDF_LabelSequence &, opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_ShapeTool::SetSHUO, "Sets the SHUO structure between upper_usage and next_usage create multy-level (if number of labels > 2) SHUO from first to last Initialise out <MainSHUOAttr> by main upper_usage SHUO attribute. Returns FALSE if some of labels in not component label", py::arg("Labels"), py::arg("MainSHUOAttr"));
cls_XCAFDoc_ShapeTool.def_static("GetSHUO_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_ShapeTool::GetSHUO, "Returns founded SHUO GraphNode attribute <aSHUOAttr> Returns false in other case", py::arg("SHUOLabel"), py::arg("aSHUOAttr"));
cls_XCAFDoc_ShapeTool.def_static("GetAllComponentSHUO_", (Standard_Boolean (*)(const TDF_Label &, TDF_AttributeSequence &)) &XCAFDoc_ShapeTool::GetAllComponentSHUO, "Returns founded SHUO GraphNodes of indicated component Returns false in other case", py::arg("CompLabel"), py::arg("SHUOAttrs"));
cls_XCAFDoc_ShapeTool.def_static("GetSHUOUpperUsage_", (Standard_Boolean (*)(const TDF_Label &, TDF_LabelSequence &)) &XCAFDoc_ShapeTool::GetSHUOUpperUsage, "Returns the sequence of labels of SHUO attributes, which is upper_usage for this next_usage SHUO attribute (that indicated by label) NOTE: returns upper_usages only on one level (not recurse) NOTE: do not clear the sequence before filling", py::arg("NextUsageL"), py::arg("Labels"));
cls_XCAFDoc_ShapeTool.def_static("GetSHUONextUsage_", (Standard_Boolean (*)(const TDF_Label &, TDF_LabelSequence &)) &XCAFDoc_ShapeTool::GetSHUONextUsage, "Returns the sequence of labels of SHUO attributes, which is next_usage for this upper_usage SHUO attribute (that indicated by label) NOTE: returns next_usages only on one level (not recurse) NOTE: do not clear the sequence before filling", py::arg("UpperUsageL"), py::arg("Labels"));
cls_XCAFDoc_ShapeTool.def("RemoveSHUO", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TDF_Label &) const) &XCAFDoc_ShapeTool::RemoveSHUO, "Remove SHUO from component sublabel, remove all dependencies on other SHUO. Returns FALSE if cannot remove SHUO dependencies. NOTE: remove any styles that associated with this SHUO.", py::arg("SHUOLabel"));
cls_XCAFDoc_ShapeTool.def("FindComponent", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &, TDF_LabelSequence &) const) &XCAFDoc_ShapeTool::FindComponent, "Serach the path of labels in the document, that corresponds the component from any assembly Try to search the sequence of labels with location that produce this shape as component of any assembly NOTE: Clear sequence of labels before filling", py::arg("theShape"), py::arg("Labels"));
cls_XCAFDoc_ShapeTool.def("GetSHUOInstance", (TopoDS_Shape (XCAFDoc_ShapeTool::*)(const opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_ShapeTool::GetSHUOInstance, "Search for the component shape that styled by shuo Returns null shape if no any shape is found.", py::arg("theSHUO"));
cls_XCAFDoc_ShapeTool.def("SetInstanceSHUO", (opencascade::handle<XCAFDoc_GraphNode> (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &) const) &XCAFDoc_ShapeTool::SetInstanceSHUO, "Search for the component shape by labelks path and set SHUO structure for founded label structure Returns null attribute if no component in any assembly found.", py::arg("theShape"));
cls_XCAFDoc_ShapeTool.def("GetAllSHUOInstances", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const opencascade::handle<XCAFDoc_GraphNode> &, TopTools_SequenceOfShape &) const) &XCAFDoc_ShapeTool::GetAllSHUOInstances, "Seaching for component shapes that styled by shuo Returns empty sequence of shape if no any shape is found.", py::arg("theSHUO"), py::arg("theSHUOShapeSeq"));
cls_XCAFDoc_ShapeTool.def_static("FindSHUO_", (Standard_Boolean (*)(const TDF_LabelSequence &, opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_ShapeTool::FindSHUO, "Searchs the SHUO by labels of components from upper_usage componet to next_usage Returns null attribute if no SHUO found", py::arg("Labels"), py::arg("theSHUOAttr"));
cls_XCAFDoc_ShapeTool.def("Expand", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TDF_Label &)) &XCAFDoc_ShapeTool::Expand, "Convert Shape (compound/compsolid/shell/wire) to assembly", py::arg("Shape"));
cls_XCAFDoc_ShapeTool.def("makeSubShape", (void (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &, const TopLoc_Location &)) &XCAFDoc_ShapeTool::makeSubShape, "Make subshape for Part from Shape", py::arg("thePart"), py::arg("theShape"), py::arg("theLoc"));
cls_XCAFDoc_ShapeTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ShapeTool::get_type_name, "None");
cls_XCAFDoc_ShapeTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ShapeTool::get_type_descriptor, "None");
cls_XCAFDoc_ShapeTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ShapeTool::*)() const) &XCAFDoc_ShapeTool::DynamicType, "None");

// Enums

}