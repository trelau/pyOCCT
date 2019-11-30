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
#include <TCollection_ExtendedString.hxx>
#include <XCAFDoc_ColorType.hxx>
#include <NCollection_DataMap.hxx>
#include <TopoDS_Shape.hxx>
#include <TDF_Label.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <XCAFDoc_DataMapOfShapeLabel.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_DimTolTool.hxx>
#include <Standard_GUID.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelSequence.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TCollection_HAsciiString.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TDF_LabelMapHasher.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <Standard.hxx>
#include <XCAFDoc.hxx>
#include <XCAFDoc_Area.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_ListOfAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <XCAFDoc_AssemblyItemId.hxx>
#include <XCAFDoc_AssemblyItemRef.hxx>
#include <XCAFDoc_Centroid.hxx>
#include <gp_Pnt.hxx>
#include <XCAFDoc_ClippingPlaneTool.hxx>
#include <gp_Pln.hxx>
#include <XCAFDoc_Color.hxx>
#include <Quantity_Color.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Quantity_NameOfColor.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include <XCAFDoc_Datum.hxx>
#include <XCAFDimTolObjects_DatumObject.hxx>
#include <XCAFDoc_Dimension.hxx>
#include <XCAFDimTolObjects_DimensionObject.hxx>
#include <XCAFDoc_DimTol.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <TDocStd_Document.hxx>
#include <XCAFDoc_LayerTool.hxx>
#include <XCAFDoc_MaterialTool.hxx>
#include <XCAFDoc_ViewTool.hxx>
#include <XCAFDoc_NotesTool.hxx>
#include <TDataStd_Name.hxx>
#include <XCAFDoc_Editor.hxx>
#include <XCAFDoc_GeomTolerance.hxx>
#include <XCAFDimTolObjects_GeomToleranceObject.hxx>
#include <NCollection_Sequence.hxx>
#include <XCAFDoc_GraphNode.hxx>
#include <XCAFDoc_GraphNodeSequence.hxx>
#include <TDF_DataSet.hxx>
#include <TColStd_HSequenceOfExtendedString.hxx>
#include <XCAFDoc_Location.hxx>
#include <TopLoc_Location.hxx>
#include <XCAFDoc_Material.hxx>
#include <XCAFDoc_Note.hxx>
#include <XCAFNoteObjects_NoteObject.hxx>
#include <XCAFDoc_NoteComment.hxx>
#include <XCAFDoc_NoteBalloon.hxx>
#include <XCAFDoc_NoteBinData.hxx>
#include <OSD_File.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <XCAFDoc_PartId.hxx>
#include <XCAFDoc_ShapeMapTool.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TColStd_SequenceOfHAsciiString.hxx>
#include <TDF_AttributeSequence.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TDataStd_NamedData.hxx>
#include <XCAFDoc_View.hxx>
#include <XCAFView_Object.hxx>
#include <XCAFDoc_Volume.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(XCAFDoc, mod) {

py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.XCAFDimTolObjects");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.TDataStd");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.XCAFNoteObjects");
py::module::import("OCCT.OSD");
py::module::import("OCCT.XCAFView");

// ENUM: XCAFDOC_COLORTYPE
py::enum_<XCAFDoc_ColorType>(mod, "XCAFDoc_ColorType", "Defines types of color assignments Color of shape is defined following way in dependance with type of color. If type of color is XCAFDoc_ColorGen - then this color defines default color for surfaces and curves. If for shape color with types XCAFDoc_ColorSurf or XCAFDoc_ColorCurv is specified then such color overrides generic color. simple color color of surfaces color of curves")
	.value("XCAFDoc_ColorGen", XCAFDoc_ColorType::XCAFDoc_ColorGen)
	.value("XCAFDoc_ColorSurf", XCAFDoc_ColorType::XCAFDoc_ColorSurf)
	.value("XCAFDoc_ColorCurv", XCAFDoc_ColorType::XCAFDoc_ColorCurv)
	.export_values();


// TYPEDEF: XCAFDOC_DATAMAPOFSHAPELABEL
bind_NCollection_DataMap<TopoDS_Shape, TDF_Label, TopTools_ShapeMapHasher>(mod, "XCAFDoc_DataMapOfShapeLabel", py::module_local(false));

// TYPEDEF: XCAFDOC_DATAMAPITERATOROFDATAMAPOFSHAPELABEL

// CLASS: XCAFDOC_DIMTOLTOOL
py::class_<XCAFDoc_DimTolTool, opencascade::handle<XCAFDoc_DimTolTool>, TDF_Attribute> cls_XCAFDoc_DimTolTool(mod, "XCAFDoc_DimTolTool", "Attribute containing GD&T section of XCAF document. Provide tools for GD&T section management.");

// Constructors
cls_XCAFDoc_DimTolTool.def(py::init<>());

// Methods
cls_XCAFDoc_DimTolTool.def_static("Set_", (opencascade::handle<XCAFDoc_DimTolTool> (*)(const TDF_Label &)) &XCAFDoc_DimTolTool::Set, "Creates (if not exist) DimTolTool attribute.", py::arg("L"));
cls_XCAFDoc_DimTolTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_DimTolTool::GetID, "Returns the standard GD&T tool GUID.");
cls_XCAFDoc_DimTolTool.def("BaseLabel", (TDF_Label (XCAFDoc_DimTolTool::*)() const) &XCAFDoc_DimTolTool::BaseLabel, "Returns the label under which GD&T table is stored.");
cls_XCAFDoc_DimTolTool.def("ShapeTool", (const opencascade::handle<XCAFDoc_ShapeTool> & (XCAFDoc_DimTolTool::*)()) &XCAFDoc_DimTolTool::ShapeTool, "Returns internal XCAFDoc_ShapeTool tool");
cls_XCAFDoc_DimTolTool.def("IsDimension", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &) const) &XCAFDoc_DimTolTool::IsDimension, "Returns True if the label belongs to a GD&T table and is a Dimension definition.", py::arg("theLab"));
cls_XCAFDoc_DimTolTool.def("GetDimensionLabels", (void (XCAFDoc_DimTolTool::*)(TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetDimensionLabels, "Returns a sequence of Dimension labels currently stored in the GD&T table.", py::arg("theLabels"));
cls_XCAFDoc_DimTolTool.def("SetDimension", (void (XCAFDoc_DimTolTool::*)(const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_DimTolTool::SetDimension, "Sets a dimension to sequences target labels.", py::arg("theFirstLS"), py::arg("theSecondLS"), py::arg("theDimL"));
cls_XCAFDoc_DimTolTool.def("SetDimension", (void (XCAFDoc_DimTolTool::*)(const TDF_Label &, const TDF_Label &, const TDF_Label &) const) &XCAFDoc_DimTolTool::SetDimension, "Sets a dimension to target labels.", py::arg("theFirstL"), py::arg("theSecondL"), py::arg("theDimL"));
cls_XCAFDoc_DimTolTool.def("SetDimension", (void (XCAFDoc_DimTolTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_DimTolTool::SetDimension, "Sets a dimension to the target label.", py::arg("theL"), py::arg("theDimL"));
cls_XCAFDoc_DimTolTool.def("GetRefDimensionLabels", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetRefDimensionLabels, "Returns all Dimension labels defined for theShapeL.", py::arg("theShapeL"), py::arg("theDimensions"));
cls_XCAFDoc_DimTolTool.def("AddDimension", (TDF_Label (XCAFDoc_DimTolTool::*)()) &XCAFDoc_DimTolTool::AddDimension, "Adds a dimension definition to the GD&T table and returns its label.");
cls_XCAFDoc_DimTolTool.def("IsGeomTolerance", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &) const) &XCAFDoc_DimTolTool::IsGeomTolerance, "Returns True if the label belongs to the GD&T table and is a dimension tolerance.", py::arg("theLab"));
cls_XCAFDoc_DimTolTool.def("GetGeomToleranceLabels", (void (XCAFDoc_DimTolTool::*)(TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetGeomToleranceLabels, "Returns a sequence of Tolerance labels currently stored in the GD&T table.", py::arg("theLabels"));
cls_XCAFDoc_DimTolTool.def("SetGeomTolerance", (void (XCAFDoc_DimTolTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_DimTolTool::SetGeomTolerance, "Sets a geometry tolerance from theGeomTolL to theL label. Checks if theGeomTolL is a geometry tolerance definition first.", py::arg("theL"), py::arg("theGeomTolL"));
cls_XCAFDoc_DimTolTool.def("SetGeomTolerance", (void (XCAFDoc_DimTolTool::*)(const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_DimTolTool::SetGeomTolerance, "Sets a geometry tolerance from theGeomTolL to sequence of labels theL. Checks if theGeomTolL is a geometry tolerance definition first.", py::arg("theL"), py::arg("theGeomTolL"));
cls_XCAFDoc_DimTolTool.def("GetRefGeomToleranceLabels", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetRefGeomToleranceLabels, "Returns all GeomTolerance labels defined for theShapeL.", py::arg("theShapeL"), py::arg("theDimTols"));
cls_XCAFDoc_DimTolTool.def("AddGeomTolerance", (TDF_Label (XCAFDoc_DimTolTool::*)()) &XCAFDoc_DimTolTool::AddGeomTolerance, "Adds a GeomTolerance definition to the GD&T table and returns its label.");
cls_XCAFDoc_DimTolTool.def("IsDimTol", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &) const) &XCAFDoc_DimTolTool::IsDimTol, "Returns True if theLab belongs to the GD&T table and is a dmension tolerance.", py::arg("theLab"));
cls_XCAFDoc_DimTolTool.def("GetDimTolLabels", (void (XCAFDoc_DimTolTool::*)(TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetDimTolLabels, "Returns a sequence of D&GTs currently stored in the GD&T table.", py::arg("Labels"));
cls_XCAFDoc_DimTolTool.def("FindDimTol", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, TDF_Label &) const) &XCAFDoc_DimTolTool::FindDimTol, "Finds a dimension tolerance definition in the GD&T table sutisfying the specified kind, values, name and description and returns its label if found. Returns False if dimension tolerance is not found in DGTtable.", py::arg("theKind"), py::arg("theVal"), py::arg("theName"), py::arg("theDescription"), py::arg("lab"));
cls_XCAFDoc_DimTolTool.def("FindDimTol", (TDF_Label (XCAFDoc_DimTolTool::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_DimTolTool::FindDimTol, "Finds a dimension tolerance in the GD&T table sutisfying the specified kind, values, name and description and returns its label if found (or Null label else).", py::arg("theKind"), py::arg("theVal"), py::arg("theName"), py::arg("theDescription"));
cls_XCAFDoc_DimTolTool.def("AddDimTol", (TDF_Label (XCAFDoc_DimTolTool::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_DimTolTool::AddDimTol, "Adds a a dimension tolerance definition with the specified kind, value, name and description to the GD&T table and returns its label.", py::arg("theKind"), py::arg("theVal"), py::arg("theName"), py::arg("theDescription"));
cls_XCAFDoc_DimTolTool.def("SetDimTol", (void (XCAFDoc_DimTolTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_DimTolTool::SetDimTol, "Sets existing dimension tolerance to theL label.", py::arg("theL"), py::arg("theDimTolL"));
cls_XCAFDoc_DimTolTool.def("SetDimTol", (TDF_Label (XCAFDoc_DimTolTool::*)(const TDF_Label &, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_DimTolTool::SetDimTol, "Creates a dimension tolerance and sets it to theL label.", py::arg("theL"), py::arg("theKind"), py::arg("theVal"), py::arg("theName"), py::arg("theDescription"));
cls_XCAFDoc_DimTolTool.def("GetRefShapeLabel", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &, TDF_LabelSequence &, TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetRefShapeLabel, "Gets all shape labels reffered by theL label of the GD&T table. Returns False if there are no shape labels added to the sequences.", py::arg("theL"), py::arg("theShapeLFirst"), py::arg("theShapeLSecond"));
cls_XCAFDoc_DimTolTool.def("GetDimTol", [](XCAFDoc_DimTolTool &self, const TDF_Label & theDimTolL, Standard_Integer & theKind, opencascade::handle<TColStd_HArray1OfReal> & theVal, opencascade::handle<TCollection_HAsciiString> & theName, opencascade::handle<TCollection_HAsciiString> & theDescription){ Standard_Boolean rv = self.GetDimTol(theDimTolL, theKind, theVal, theName, theDescription); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theKind); }, "Returns dimension tolerance assigned to theDimTolL label. Returns False if no such dimension tolerance is assigned.", py::arg("theDimTolL"), py::arg("theKind"), py::arg("theVal"), py::arg("theName"), py::arg("theDescription"));
cls_XCAFDoc_DimTolTool.def("IsDatum", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &) const) &XCAFDoc_DimTolTool::IsDatum, "Returns True if label belongs to the GD&T table and is a Datum definition.", py::arg("lab"));
cls_XCAFDoc_DimTolTool.def("GetDatumLabels", (void (XCAFDoc_DimTolTool::*)(TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetDatumLabels, "Returns a sequence of Datums currently stored in the GD&T table.", py::arg("Labels"));
cls_XCAFDoc_DimTolTool.def("FindDatum", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, TDF_Label &) const) &XCAFDoc_DimTolTool::FindDatum, "Finds a datum sutisfying the specified name, description and identification and returns its label if found.", py::arg("theName"), py::arg("theDescription"), py::arg("theIdentification"), py::arg("lab"));
cls_XCAFDoc_DimTolTool.def("AddDatum", (TDF_Label (XCAFDoc_DimTolTool::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_DimTolTool::AddDatum, "Adds a datum definition to the GD&T table and returns its label.", py::arg("theName"), py::arg("theDescription"), py::arg("theIdentification"));
cls_XCAFDoc_DimTolTool.def("AddDatum", (TDF_Label (XCAFDoc_DimTolTool::*)()) &XCAFDoc_DimTolTool::AddDatum, "Adds a datum definition to the GD&T table and returns its label.");
cls_XCAFDoc_DimTolTool.def("SetDatum", (void (XCAFDoc_DimTolTool::*)(const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_DimTolTool::SetDatum, "Sets a datum to the sequence of shape labels.", py::arg("theShapeLabels"), py::arg("theDatumL"));
cls_XCAFDoc_DimTolTool.def("SetDatum", (void (XCAFDoc_DimTolTool::*)(const TDF_Label &, const TDF_Label &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_DimTolTool::SetDatum, "Sets a datum to theL label and binds it with theTolerL label. A datum with the specified name, description and identification is created if it isn't found in the GD&T table.", py::arg("theL"), py::arg("theTolerL"), py::arg("theName"), py::arg("theDescription"), py::arg("theIdentification"));
cls_XCAFDoc_DimTolTool.def("SetDatumToGeomTol", (void (XCAFDoc_DimTolTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_DimTolTool::SetDatumToGeomTol, "Sets a datum from theDatumL label to theToletL label.", py::arg("theDatumL"), py::arg("theTolerL"));
cls_XCAFDoc_DimTolTool.def("GetDatum", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &, opencascade::handle<TCollection_HAsciiString> &, opencascade::handle<TCollection_HAsciiString> &, opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_DimTolTool::GetDatum, "Returns datum assigned to theDatumL label. Returns False if no such datum is assigned.", py::arg("theDatumL"), py::arg("theName"), py::arg("theDescription"), py::arg("theIdentification"));
cls_XCAFDoc_DimTolTool.def("GetDatumOfTolerLabels", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetDatumOfTolerLabels, "Returns all Datum labels defined for theDimTolL label.", py::arg("theDimTolL"), py::arg("theDatums"));
cls_XCAFDoc_DimTolTool.def("GetDatumWithObjectOfTolerLabels", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetDatumWithObjectOfTolerLabels, "Returns all Datum labels with XCAFDimTolObjects_DatumObject defined for label theDimTolL.", py::arg("theDimTolL"), py::arg("theDatums"));
cls_XCAFDoc_DimTolTool.def("GetTolerOfDatumLabels", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetTolerOfDatumLabels, "Returns all GeomToleranses labels defined for theDatumL label.", py::arg("theDatumL"), py::arg("theTols"));
cls_XCAFDoc_DimTolTool.def("GetRefDatumLabel", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_DimTolTool::GetRefDatumLabel, "Returns Datum label defined for theShapeL label.", py::arg("theShapeL"), py::arg("theDatum"));
cls_XCAFDoc_DimTolTool.def("IsLocked", (Standard_Boolean (XCAFDoc_DimTolTool::*)(const TDF_Label &) const) &XCAFDoc_DimTolTool::IsLocked, "Returns true if the given GDT is marked as locked.", py::arg("theViewL"));
cls_XCAFDoc_DimTolTool.def("Lock", (void (XCAFDoc_DimTolTool::*)(const TDF_Label &) const) &XCAFDoc_DimTolTool::Lock, "Mark the given GDT as locked.", py::arg("theViewL"));
cls_XCAFDoc_DimTolTool.def("GetGDTPresentations", (void (XCAFDoc_DimTolTool::*)(NCollection_IndexedDataMap<TDF_Label, TopoDS_Shape, TDF_LabelMapHasher> &) const) &XCAFDoc_DimTolTool::GetGDTPresentations, "fill the map GDT label -> shape presentation", py::arg("theGDTLabelToShape"));
cls_XCAFDoc_DimTolTool.def("SetGDTPresentations", (void (XCAFDoc_DimTolTool::*)(NCollection_IndexedDataMap<TDF_Label, TopoDS_Shape, TDF_LabelMapHasher> &)) &XCAFDoc_DimTolTool::SetGDTPresentations, "Set shape presentation for GDT labels according to given map (theGDTLabelToPrs) theGDTLabelToPrsName map is an additional argument, can be used to set presentation names. If label is not in the theGDTLabelToPrsName map, the presentation name will be empty", py::arg("theGDTLabelToPrs"));
cls_XCAFDoc_DimTolTool.def("Unlock", (void (XCAFDoc_DimTolTool::*)(const TDF_Label &) const) &XCAFDoc_DimTolTool::Unlock, "Unlock the given GDT.", py::arg("theViewL"));
cls_XCAFDoc_DimTolTool.def("ID", (const Standard_GUID & (XCAFDoc_DimTolTool::*)() const) &XCAFDoc_DimTolTool::ID, "None");
cls_XCAFDoc_DimTolTool.def("Restore", (void (XCAFDoc_DimTolTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_DimTolTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_DimTolTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_DimTolTool::*)() const) &XCAFDoc_DimTolTool::NewEmpty, "None");
cls_XCAFDoc_DimTolTool.def("Paste", (void (XCAFDoc_DimTolTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_DimTolTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_DimTolTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_DimTolTool::get_type_name, "None");
cls_XCAFDoc_DimTolTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_DimTolTool::get_type_descriptor, "None");
cls_XCAFDoc_DimTolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_DimTolTool::*)() const) &XCAFDoc_DimTolTool::DynamicType, "None");

// CLASS: XCAFDOC
py::class_<XCAFDoc> cls_XCAFDoc(mod, "XCAFDoc", "Definition of general structure of DECAF document and tools to work with it");

// Constructors
cls_XCAFDoc.def(py::init<>());

// Methods
// cls_XCAFDoc.def_static("operator new_", (void * (*)(size_t)) &XCAFDoc::operator new, "None", py::arg("theSize"));
// cls_XCAFDoc.def_static("operator delete_", (void (*)(void *)) &XCAFDoc::operator delete, "None", py::arg("theAddress"));
// cls_XCAFDoc.def_static("operator new[]_", (void * (*)(size_t)) &XCAFDoc::operator new[], "None", py::arg("theSize"));
// cls_XCAFDoc.def_static("operator delete[]_", (void (*)(void *)) &XCAFDoc::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFDoc.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFDoc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFDoc.def_static("operator delete_", (void (*)(void *, void *)) &XCAFDoc::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFDoc.def_static("AssemblyGUID_", (const Standard_GUID & (*)()) &XCAFDoc::AssemblyGUID, "class for containing GraphNodes. Returns GUID for UAttribute identifying assembly");
cls_XCAFDoc.def_static("ShapeRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::ShapeRefGUID, "Returns GUID for TreeNode representing assembly link");
cls_XCAFDoc.def_static("ColorRefGUID_", (const Standard_GUID & (*)(const XCAFDoc_ColorType)) &XCAFDoc::ColorRefGUID, "Return GUIDs for TreeNode representing specified types of colors", py::arg("type"));
cls_XCAFDoc.def_static("DimTolRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::DimTolRefGUID, "Return GUIDs for TreeNode representing specified types of DGT");
cls_XCAFDoc.def_static("DimensionRefFirstGUID_", (const Standard_GUID & (*)()) &XCAFDoc::DimensionRefFirstGUID, "Return GUIDs for TreeNode representing specified types of Dimension");
cls_XCAFDoc.def_static("DimensionRefSecondGUID_", (const Standard_GUID & (*)()) &XCAFDoc::DimensionRefSecondGUID, "Return GUIDs for TreeNode representing specified types of Dimension");
cls_XCAFDoc.def_static("GeomToleranceRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::GeomToleranceRefGUID, "Return GUIDs for TreeNode representing specified types of GeomTolerance");
cls_XCAFDoc.def_static("DatumRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::DatumRefGUID, "Return GUIDs for TreeNode representing specified types of datum");
cls_XCAFDoc.def_static("DatumTolRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::DatumTolRefGUID, "Return GUIDs for TreeNode representing connections Datum-Toler");
cls_XCAFDoc.def_static("LayerRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::LayerRefGUID, "None");
cls_XCAFDoc.def_static("MaterialRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::MaterialRefGUID, "None");
cls_XCAFDoc.def_static("NoteRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::NoteRefGUID, "Return GUIDs for representing notes");
cls_XCAFDoc.def_static("InvisibleGUID_", (const Standard_GUID & (*)()) &XCAFDoc::InvisibleGUID, "None");
cls_XCAFDoc.def_static("ColorByLayerGUID_", (const Standard_GUID & (*)()) &XCAFDoc::ColorByLayerGUID, "None");
cls_XCAFDoc.def_static("ExternRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::ExternRefGUID, "Returns GUID for UAttribute identifying external reference on no-step file");
cls_XCAFDoc.def_static("SHUORefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::SHUORefGUID, "Returns GUID for UAttribute identifying specified higher usage occurrence");
cls_XCAFDoc.def_static("ViewRefGUID_", (const Standard_GUID & (*)()) &XCAFDoc::ViewRefGUID, "Return GUIDs for TreeNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefShapeGUID_", (const Standard_GUID & (*)()) &XCAFDoc::ViewRefShapeGUID, "Return GUIDs for TreeNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefGDTGUID_", (const Standard_GUID & (*)()) &XCAFDoc::ViewRefGDTGUID, "Return GUIDs for TreeNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefPlaneGUID_", (const Standard_GUID & (*)()) &XCAFDoc::ViewRefPlaneGUID, "Return GUIDs for TreeNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefNoteGUID_", (const Standard_GUID & (*)()) &XCAFDoc::ViewRefNoteGUID, "Return GUIDs for GraphNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefAnnotationGUID_", (const Standard_GUID & (*)()) &XCAFDoc::ViewRefAnnotationGUID, "None");
cls_XCAFDoc.def_static("LockGUID_", (const Standard_GUID & (*)()) &XCAFDoc::LockGUID, "Returns GUID for UAttribute identifying lock flag");

// CLASS: XCAFDOC_AREA
py::class_<XCAFDoc_Area, opencascade::handle<XCAFDoc_Area>, TDF_Attribute> cls_XCAFDoc_Area(mod, "XCAFDoc_Area", "attribute to store area");

// Constructors
cls_XCAFDoc_Area.def(py::init<>());

// Methods
cls_XCAFDoc_Area.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Area::GetID, "None");
cls_XCAFDoc_Area.def("ID", (const Standard_GUID & (XCAFDoc_Area::*)() const) &XCAFDoc_Area::ID, "None");
cls_XCAFDoc_Area.def("Set", (void (XCAFDoc_Area::*)(const Standard_Real)) &XCAFDoc_Area::Set, "Sets a value of volume", py::arg("vol"));
cls_XCAFDoc_Area.def_static("Set_", (opencascade::handle<XCAFDoc_Area> (*)(const TDF_Label &, const Standard_Real)) &XCAFDoc_Area::Set, "Find, or create, an Area attribute and set its value", py::arg("label"), py::arg("area"));
cls_XCAFDoc_Area.def("Get", (Standard_Real (XCAFDoc_Area::*)() const) &XCAFDoc_Area::Get, "None");
cls_XCAFDoc_Area.def_static("Get_", [](const TDF_Label & label, Standard_Real & area){ Standard_Boolean rv = XCAFDoc_Area::Get(label, area); return std::tuple<Standard_Boolean, Standard_Real &>(rv, area); }, "Returns volume of area as argument and succes status returns false if no such attribute at the <label>", py::arg("label"), py::arg("area"));
cls_XCAFDoc_Area.def("Restore", (void (XCAFDoc_Area::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Area::Restore, "None", py::arg("With"));
cls_XCAFDoc_Area.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Area::*)() const) &XCAFDoc_Area::NewEmpty, "None");
cls_XCAFDoc_Area.def("Paste", (void (XCAFDoc_Area::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Area::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Area.def("Dump", (Standard_OStream & (XCAFDoc_Area::*)(Standard_OStream &) const) &XCAFDoc_Area::Dump, "None", py::arg("anOS"));
cls_XCAFDoc_Area.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Area::get_type_name, "None");
cls_XCAFDoc_Area.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Area::get_type_descriptor, "None");
cls_XCAFDoc_Area.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Area::*)() const) &XCAFDoc_Area::DynamicType, "None");

// CLASS: XCAFDOC_ASSEMBLYITEMID
py::class_<XCAFDoc_AssemblyItemId> cls_XCAFDoc_AssemblyItemId(mod, "XCAFDoc_AssemblyItemId", "Unique item identifier in the hierarchical product structure. A full path to an assembly component in the 'part-of' graph starting from the root node.");

// Constructors
cls_XCAFDoc_AssemblyItemId.def(py::init<>());
cls_XCAFDoc_AssemblyItemId.def(py::init<const TColStd_ListOfAsciiString &>(), py::arg("thePath"));
cls_XCAFDoc_AssemblyItemId.def(py::init<const TCollection_AsciiString &>(), py::arg("theString"));

// Methods
cls_XCAFDoc_AssemblyItemId.def("Init", (void (XCAFDoc_AssemblyItemId::*)(const TColStd_ListOfAsciiString &)) &XCAFDoc_AssemblyItemId::Init, "Initializes the item ID from a list of strings, where every string is a label entry.", py::arg("thePath"));
cls_XCAFDoc_AssemblyItemId.def("Init", (void (XCAFDoc_AssemblyItemId::*)(const TCollection_AsciiString &)) &XCAFDoc_AssemblyItemId::Init, "Initializes the item ID from a formatted path, where label entries are separated by '/' symbol.", py::arg("theString"));
cls_XCAFDoc_AssemblyItemId.def("IsNull", (Standard_Boolean (XCAFDoc_AssemblyItemId::*)() const) &XCAFDoc_AssemblyItemId::IsNull, "Returns true if the full path is empty, otherwise - false.");
cls_XCAFDoc_AssemblyItemId.def("Nullify", (void (XCAFDoc_AssemblyItemId::*)()) &XCAFDoc_AssemblyItemId::Nullify, "Clears the full path.");
cls_XCAFDoc_AssemblyItemId.def("IsChild", (Standard_Boolean (XCAFDoc_AssemblyItemId::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_AssemblyItemId::IsChild, "Checks if this item is a child of the given item.", py::arg("theOther"));
cls_XCAFDoc_AssemblyItemId.def("IsDirectChild", (Standard_Boolean (XCAFDoc_AssemblyItemId::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_AssemblyItemId::IsDirectChild, "Checks if this item is a direct child of the given item.", py::arg("theOther"));
cls_XCAFDoc_AssemblyItemId.def("IsEqual", (Standard_Boolean (XCAFDoc_AssemblyItemId::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_AssemblyItemId::IsEqual, "Checks for item IDs equality.", py::arg("theOther"));
cls_XCAFDoc_AssemblyItemId.def("GetPath", (const TColStd_ListOfAsciiString & (XCAFDoc_AssemblyItemId::*)() const) &XCAFDoc_AssemblyItemId::GetPath, "Returns the full path as a list of label entries.");
cls_XCAFDoc_AssemblyItemId.def("ToString", (TCollection_AsciiString (XCAFDoc_AssemblyItemId::*)() const) &XCAFDoc_AssemblyItemId::ToString, "Returns the full pass as a formatted string.");

// CLASS: XCAFDOC_ASSEMBLYITEMREF
py::class_<XCAFDoc_AssemblyItemRef, opencascade::handle<XCAFDoc_AssemblyItemRef>, TDF_Attribute> cls_XCAFDoc_AssemblyItemRef(mod, "XCAFDoc_AssemblyItemRef", "An attribute that describes a weak reference to an assembly item or to a subshape or to an assembly label attribute.");

// Constructors
cls_XCAFDoc_AssemblyItemRef.def(py::init<>());

// Methods
cls_XCAFDoc_AssemblyItemRef.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_AssemblyItemRef::get_type_name, "None");
cls_XCAFDoc_AssemblyItemRef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_AssemblyItemRef::get_type_descriptor, "None");
cls_XCAFDoc_AssemblyItemRef.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::DynamicType, "None");
cls_XCAFDoc_AssemblyItemRef.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_AssemblyItemRef::GetID, "None");
cls_XCAFDoc_AssemblyItemRef.def_static("Get_", (opencascade::handle<XCAFDoc_AssemblyItemRef> (*)(const TDF_Label &)) &XCAFDoc_AssemblyItemRef::Get, "Finds a reference attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_AssemblyItemRef.def_static("Set_", (opencascade::handle<XCAFDoc_AssemblyItemRef> (*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &)) &XCAFDoc_AssemblyItemRef::Set, "Create (if not exist) a reference to an assembly item.", py::arg("theLabel"), py::arg("theItemId"));
cls_XCAFDoc_AssemblyItemRef.def_static("Set_", (opencascade::handle<XCAFDoc_AssemblyItemRef> (*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, const Standard_GUID &)) &XCAFDoc_AssemblyItemRef::Set, "Create (if not exist) a reference to an assembly item's label attribute.", py::arg("theLabel"), py::arg("theItemId"), py::arg("theGUID"));
cls_XCAFDoc_AssemblyItemRef.def_static("Set_", (opencascade::handle<XCAFDoc_AssemblyItemRef> (*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, const Standard_Integer)) &XCAFDoc_AssemblyItemRef::Set, "Create (if not exist) a reference to an assembly item's subshape.", py::arg("theLabel"), py::arg("theItemId"), py::arg("theShapeIndex"));
cls_XCAFDoc_AssemblyItemRef.def("IsOrphan", (Standard_Boolean (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::IsOrphan, "Checks if the reference points to a really existing item in XDE document.");
cls_XCAFDoc_AssemblyItemRef.def("HasExtraRef", (Standard_Boolean (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::HasExtraRef, "Checks if the reference points on an item's shapeindex or attribute.");
cls_XCAFDoc_AssemblyItemRef.def("IsGUID", (Standard_Boolean (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::IsGUID, "Checks is the reference points to an item's attribute.");
cls_XCAFDoc_AssemblyItemRef.def("IsSubshapeIndex", (Standard_Boolean (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::IsSubshapeIndex, "Checks is the reference points to an item's subshape.");
cls_XCAFDoc_AssemblyItemRef.def("GetGUID", (Standard_GUID (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::GetGUID, "Returns the assembly item's attribute that the reference points to. If the reference doesn't point to an attribute, returns an empty GUID.");
cls_XCAFDoc_AssemblyItemRef.def("GetSubshapeIndex", (Standard_Integer (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::GetSubshapeIndex, "Returns the assembly item's subshape that the reference points to. If the reference doesn't point to a subshape, returns 0.");
cls_XCAFDoc_AssemblyItemRef.def("GetItem", (const XCAFDoc_AssemblyItemId & (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::GetItem, "Returns the assembly item ID that the reference points to.");
cls_XCAFDoc_AssemblyItemRef.def("SetItem", (void (XCAFDoc_AssemblyItemRef::*)(const XCAFDoc_AssemblyItemId &)) &XCAFDoc_AssemblyItemRef::SetItem, "Sets the assembly item ID that the reference points to. Extra reference data (if any) will be cleared.", py::arg("theItemId"));
cls_XCAFDoc_AssemblyItemRef.def("SetItem", (void (XCAFDoc_AssemblyItemRef::*)(const TColStd_ListOfAsciiString &)) &XCAFDoc_AssemblyItemRef::SetItem, "Sets the assembly item ID from a list of label entries that the reference points to. Extra reference data (if any) will be cleared.", py::arg("thePath"));
cls_XCAFDoc_AssemblyItemRef.def("SetItem", (void (XCAFDoc_AssemblyItemRef::*)(const TCollection_AsciiString &)) &XCAFDoc_AssemblyItemRef::SetItem, "Sets the assembly item ID from a formatted path that the reference points to. Extra reference data (if any) will be cleared.", py::arg("theString"));
cls_XCAFDoc_AssemblyItemRef.def("SetGUID", (void (XCAFDoc_AssemblyItemRef::*)(const Standard_GUID &)) &XCAFDoc_AssemblyItemRef::SetGUID, "Sets the assembly item's label attribute that the reference points to. The base assembly item will not change.", py::arg("theAttrGUID"));
cls_XCAFDoc_AssemblyItemRef.def("SetSubshapeIndex", (void (XCAFDoc_AssemblyItemRef::*)(Standard_Integer)) &XCAFDoc_AssemblyItemRef::SetSubshapeIndex, "Sets the assembly item's subshape that the reference points to. The base assembly item will not change.", py::arg("theShapeIndex"));
cls_XCAFDoc_AssemblyItemRef.def("ClearExtraRef", (void (XCAFDoc_AssemblyItemRef::*)()) &XCAFDoc_AssemblyItemRef::ClearExtraRef, "Reverts the reference to empty state.");
cls_XCAFDoc_AssemblyItemRef.def("ID", (const Standard_GUID & (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::ID, "None");
cls_XCAFDoc_AssemblyItemRef.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::NewEmpty, "None");
cls_XCAFDoc_AssemblyItemRef.def("Restore", (void (XCAFDoc_AssemblyItemRef::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_AssemblyItemRef::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_AssemblyItemRef.def("Paste", (void (XCAFDoc_AssemblyItemRef::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_AssemblyItemRef::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_AssemblyItemRef.def("Dump", (Standard_OStream & (XCAFDoc_AssemblyItemRef::*)(Standard_OStream &) const) &XCAFDoc_AssemblyItemRef::Dump, "None", py::arg("theOS"));

// CLASS: XCAFDOC_CENTROID
py::class_<XCAFDoc_Centroid, opencascade::handle<XCAFDoc_Centroid>, TDF_Attribute> cls_XCAFDoc_Centroid(mod, "XCAFDoc_Centroid", "attribute to store centroid");

// Constructors
cls_XCAFDoc_Centroid.def(py::init<>());

// Methods
cls_XCAFDoc_Centroid.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Centroid::GetID, "None");
cls_XCAFDoc_Centroid.def_static("Set_", (opencascade::handle<XCAFDoc_Centroid> (*)(const TDF_Label &, const gp_Pnt &)) &XCAFDoc_Centroid::Set, "Find, or create, a Location attribute and set it's value the Location attribute is returned. Location methods ===============", py::arg("label"), py::arg("pnt"));
cls_XCAFDoc_Centroid.def("Set", (void (XCAFDoc_Centroid::*)(const gp_Pnt &)) &XCAFDoc_Centroid::Set, "None", py::arg("pnt"));
cls_XCAFDoc_Centroid.def("Get", (gp_Pnt (XCAFDoc_Centroid::*)() const) &XCAFDoc_Centroid::Get, "None");
cls_XCAFDoc_Centroid.def_static("Get_", (Standard_Boolean (*)(const TDF_Label &, gp_Pnt &)) &XCAFDoc_Centroid::Get, "Returns point as argument returns false if no such attribute at the <label>", py::arg("label"), py::arg("pnt"));
cls_XCAFDoc_Centroid.def("ID", (const Standard_GUID & (XCAFDoc_Centroid::*)() const) &XCAFDoc_Centroid::ID, "None");
cls_XCAFDoc_Centroid.def("Restore", (void (XCAFDoc_Centroid::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Centroid::Restore, "None", py::arg("With"));
cls_XCAFDoc_Centroid.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Centroid::*)() const) &XCAFDoc_Centroid::NewEmpty, "None");
cls_XCAFDoc_Centroid.def("Paste", (void (XCAFDoc_Centroid::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Centroid::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Centroid.def("Dump", (Standard_OStream & (XCAFDoc_Centroid::*)(Standard_OStream &) const) &XCAFDoc_Centroid::Dump, "None", py::arg("anOS"));
cls_XCAFDoc_Centroid.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Centroid::get_type_name, "None");
cls_XCAFDoc_Centroid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Centroid::get_type_descriptor, "None");
cls_XCAFDoc_Centroid.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Centroid::*)() const) &XCAFDoc_Centroid::DynamicType, "None");

// CLASS: XCAFDOC_CLIPPINGPLANETOOL
py::class_<XCAFDoc_ClippingPlaneTool, opencascade::handle<XCAFDoc_ClippingPlaneTool>, TDF_Attribute> cls_XCAFDoc_ClippingPlaneTool(mod, "XCAFDoc_ClippingPlaneTool", "Provide tool for management of ClippingPlane section of document. Provide tool to store, retrieve, remove and modify clipping planes. Each clipping plane consists of gp_Pln and its name.");

// Constructors
cls_XCAFDoc_ClippingPlaneTool.def(py::init<>());

// Methods
cls_XCAFDoc_ClippingPlaneTool.def_static("Set_", (opencascade::handle<XCAFDoc_ClippingPlaneTool> (*)(const TDF_Label &)) &XCAFDoc_ClippingPlaneTool::Set, "Creates (if not exist) ClippingPlaneTool.", py::arg("theLabel"));
cls_XCAFDoc_ClippingPlaneTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_ClippingPlaneTool::GetID, "None");
cls_XCAFDoc_ClippingPlaneTool.def("BaseLabel", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)() const) &XCAFDoc_ClippingPlaneTool::BaseLabel, "returns the label under which ClippingPlanes are stored");
cls_XCAFDoc_ClippingPlaneTool.def("IsClippingPlane", (Standard_Boolean (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &) const) &XCAFDoc_ClippingPlaneTool::IsClippingPlane, "Returns True if label belongs to a ClippingPlane table and is a ClippingPlane definition", py::arg("theLabel"));
cls_XCAFDoc_ClippingPlaneTool.def("GetClippingPlane", [](XCAFDoc_ClippingPlaneTool &self, const TDF_Label & theLabel, gp_Pln & thePlane, TCollection_ExtendedString & theName, Standard_Boolean & theCapping){ Standard_Boolean rv = self.GetClippingPlane(theLabel, thePlane, theName, theCapping); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theCapping); }, "Returns ClippingPlane defined by label lab Returns False if the label is not in ClippingPlane table or does not define a ClippingPlane", py::arg("theLabel"), py::arg("thePlane"), py::arg("theName"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("GetClippingPlane", [](XCAFDoc_ClippingPlaneTool &self, const TDF_Label & theLabel, gp_Pln & thePlane, opencascade::handle<TCollection_HAsciiString> & theName, Standard_Boolean & theCapping){ Standard_Boolean rv = self.GetClippingPlane(theLabel, thePlane, theName, theCapping); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theCapping); }, "Returns ClippingPlane defined by label lab Returns False if the label is not in ClippingPlane table or does not define a ClippingPlane", py::arg("theLabel"), py::arg("thePlane"), py::arg("theName"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("AddClippingPlane", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)(const gp_Pln, const TCollection_ExtendedString, const Standard_Boolean) const) &XCAFDoc_ClippingPlaneTool::AddClippingPlane, "Adds a clipping plane definition to a ClippingPlane table and returns its label (returns existing label if the same clipping plane is already defined)", py::arg("thePlane"), py::arg("theName"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("AddClippingPlane", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)(const gp_Pln, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean) const) &XCAFDoc_ClippingPlaneTool::AddClippingPlane, "Adds a clipping plane definition to a ClippingPlane table and returns its label (returns existing label if the same clipping plane is already defined)", py::arg("thePlane"), py::arg("theName"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("AddClippingPlane", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)(const gp_Pln, const TCollection_ExtendedString) const) &XCAFDoc_ClippingPlaneTool::AddClippingPlane, "Adds a clipping plane definition to a ClippingPlane table and returns its label (returns existing label if the same clipping plane is already defined)", py::arg("thePlane"), py::arg("theName"));
cls_XCAFDoc_ClippingPlaneTool.def("AddClippingPlane", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)(const gp_Pln, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_ClippingPlaneTool::AddClippingPlane, "Adds a clipping plane definition to a ClippingPlane table and returns its label (returns existing label if the same clipping plane is already defined)", py::arg("thePlane"), py::arg("theName"));
cls_XCAFDoc_ClippingPlaneTool.def("RemoveClippingPlane", (Standard_Boolean (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &) const) &XCAFDoc_ClippingPlaneTool::RemoveClippingPlane, "Removes clipping plane from the ClippingPlane table Return false and do nothing if clipping plane is referenced in at least one View", py::arg("theLabel"));
cls_XCAFDoc_ClippingPlaneTool.def("GetClippingPlanes", (void (XCAFDoc_ClippingPlaneTool::*)(TDF_LabelSequence &) const) &XCAFDoc_ClippingPlaneTool::GetClippingPlanes, "Returns a sequence of clipping planes currently stored in the ClippingPlane table", py::arg("Labels"));
cls_XCAFDoc_ClippingPlaneTool.def("UpdateClippingPlane", (void (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &, const gp_Pln, const TCollection_ExtendedString) const) &XCAFDoc_ClippingPlaneTool::UpdateClippingPlane, "Sets new value of plane and name to the given clipping plane label or do nothing, if the given label is not a clipping plane label", py::arg("theLabelL"), py::arg("thePlane"), py::arg("theName"));
cls_XCAFDoc_ClippingPlaneTool.def("SetCapping", (void (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_ClippingPlaneTool::SetCapping, "Set new value of capping for given clipping plane label", py::arg("theClippingPlaneL"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("GetCapping", (Standard_Boolean (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &) const) &XCAFDoc_ClippingPlaneTool::GetCapping, "Get capping value for given clipping plane label Return capping value", py::arg("theClippingPlaneL"));
cls_XCAFDoc_ClippingPlaneTool.def("GetCapping", [](XCAFDoc_ClippingPlaneTool &self, const TDF_Label & theClippingPlaneL, Standard_Boolean & theCapping){ Standard_Boolean rv = self.GetCapping(theClippingPlaneL, theCapping); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theCapping); }, "Get capping value for given clipping plane label Return true if Label is valid abd capping is exist.", py::arg("theClippingPlaneL"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("ID", (const Standard_GUID & (XCAFDoc_ClippingPlaneTool::*)() const) &XCAFDoc_ClippingPlaneTool::ID, "None");
cls_XCAFDoc_ClippingPlaneTool.def("Restore", (void (XCAFDoc_ClippingPlaneTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_ClippingPlaneTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_ClippingPlaneTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_ClippingPlaneTool::*)() const) &XCAFDoc_ClippingPlaneTool::NewEmpty, "None");
cls_XCAFDoc_ClippingPlaneTool.def("Paste", (void (XCAFDoc_ClippingPlaneTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_ClippingPlaneTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_ClippingPlaneTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ClippingPlaneTool::get_type_name, "None");
cls_XCAFDoc_ClippingPlaneTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ClippingPlaneTool::get_type_descriptor, "None");
cls_XCAFDoc_ClippingPlaneTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ClippingPlaneTool::*)() const) &XCAFDoc_ClippingPlaneTool::DynamicType, "None");

// CLASS: XCAFDOC_COLOR
py::class_<XCAFDoc_Color, opencascade::handle<XCAFDoc_Color>, TDF_Attribute> cls_XCAFDoc_Color(mod, "XCAFDoc_Color", "attribute to store color");

// Constructors
cls_XCAFDoc_Color.def(py::init<>());

// Methods
cls_XCAFDoc_Color.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Color::GetID, "None");
cls_XCAFDoc_Color.def_static("Set_", (opencascade::handle<XCAFDoc_Color> (*)(const TDF_Label &, const Quantity_Color &)) &XCAFDoc_Color::Set, "None", py::arg("label"), py::arg("C"));
cls_XCAFDoc_Color.def_static("Set_", (opencascade::handle<XCAFDoc_Color> (*)(const TDF_Label &, const Quantity_ColorRGBA &)) &XCAFDoc_Color::Set, "None", py::arg("label"), py::arg("C"));
cls_XCAFDoc_Color.def_static("Set_", (opencascade::handle<XCAFDoc_Color> (*)(const TDF_Label &, const Quantity_NameOfColor)) &XCAFDoc_Color::Set, "None", py::arg("label"), py::arg("C"));
cls_XCAFDoc_Color.def_static("Set_", [](const TDF_Label & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> opencascade::handle<XCAFDoc_Color> { return XCAFDoc_Color::Set(a0, a1, a2, a3); });
cls_XCAFDoc_Color.def_static("Set_", (opencascade::handle<XCAFDoc_Color> (*)(const TDF_Label &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &XCAFDoc_Color::Set, "Find, or create, a Color attribute and set it's value the Color attribute is returned.", py::arg("label"), py::arg("R"), py::arg("G"), py::arg("B"), py::arg("alpha"));
cls_XCAFDoc_Color.def("Set", (void (XCAFDoc_Color::*)(const Quantity_Color &)) &XCAFDoc_Color::Set, "None", py::arg("C"));
cls_XCAFDoc_Color.def("Set", (void (XCAFDoc_Color::*)(const Quantity_ColorRGBA &)) &XCAFDoc_Color::Set, "None", py::arg("C"));
cls_XCAFDoc_Color.def("Set", (void (XCAFDoc_Color::*)(const Quantity_NameOfColor)) &XCAFDoc_Color::Set, "None", py::arg("C"));
cls_XCAFDoc_Color.def("Set", [](XCAFDoc_Color &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Set(a0, a1, a2); });
cls_XCAFDoc_Color.def("Set", (void (XCAFDoc_Color::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &XCAFDoc_Color::Set, "None", py::arg("R"), py::arg("G"), py::arg("B"), py::arg("alpha"));
cls_XCAFDoc_Color.def("GetColor", (const Quantity_Color & (XCAFDoc_Color::*)() const) &XCAFDoc_Color::GetColor, "None");
cls_XCAFDoc_Color.def("GetColorRGBA", (const Quantity_ColorRGBA & (XCAFDoc_Color::*)() const) &XCAFDoc_Color::GetColorRGBA, "None");
cls_XCAFDoc_Color.def("GetNOC", (Quantity_NameOfColor (XCAFDoc_Color::*)() const) &XCAFDoc_Color::GetNOC, "None");
cls_XCAFDoc_Color.def("GetRGB", [](XCAFDoc_Color &self, Standard_Real & R, Standard_Real & G, Standard_Real & B){ self.GetRGB(R, G, B); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(R, G, B); }, "None", py::arg("R"), py::arg("G"), py::arg("B"));
cls_XCAFDoc_Color.def("GetAlpha", (Standard_ShortReal (XCAFDoc_Color::*)() const) &XCAFDoc_Color::GetAlpha, "None");
cls_XCAFDoc_Color.def("ID", (const Standard_GUID & (XCAFDoc_Color::*)() const) &XCAFDoc_Color::ID, "None");
cls_XCAFDoc_Color.def("Restore", (void (XCAFDoc_Color::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Color::Restore, "None", py::arg("With"));
cls_XCAFDoc_Color.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Color::*)() const) &XCAFDoc_Color::NewEmpty, "None");
cls_XCAFDoc_Color.def("Paste", (void (XCAFDoc_Color::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Color::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Color.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Color::get_type_name, "None");
cls_XCAFDoc_Color.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Color::get_type_descriptor, "None");
cls_XCAFDoc_Color.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Color::*)() const) &XCAFDoc_Color::DynamicType, "None");

// CLASS: XCAFDOC_COLORTOOL
py::class_<XCAFDoc_ColorTool, opencascade::handle<XCAFDoc_ColorTool>, TDF_Attribute> cls_XCAFDoc_ColorTool(mod, "XCAFDoc_ColorTool", "Provides tools to store and retrieve attributes (colors) of TopoDS_Shape in and from TDocStd_Document A Document is intended to hold different attributes of ONE shape and it's sub-shapes Provide tools for management of Colors section of document.");

// Constructors
cls_XCAFDoc_ColorTool.def(py::init<>());

// Methods
cls_XCAFDoc_ColorTool.def_static("Set_", (opencascade::handle<XCAFDoc_ColorTool> (*)(const TDF_Label &)) &XCAFDoc_ColorTool::Set, "Creates (if not exist) ColorTool.", py::arg("L"));
cls_XCAFDoc_ColorTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_ColorTool::GetID, "None");
cls_XCAFDoc_ColorTool.def("BaseLabel", (TDF_Label (XCAFDoc_ColorTool::*)() const) &XCAFDoc_ColorTool::BaseLabel, "returns the label under which colors are stored");
cls_XCAFDoc_ColorTool.def("ShapeTool", (const opencascade::handle<XCAFDoc_ShapeTool> & (XCAFDoc_ColorTool::*)()) &XCAFDoc_ColorTool::ShapeTool, "Returns internal XCAFDoc_ShapeTool tool");
cls_XCAFDoc_ColorTool.def("IsColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &) const) &XCAFDoc_ColorTool::IsColor, "Returns True if label belongs to a colortable and is a color definition", py::arg("lab"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, Quantity_Color &) const) &XCAFDoc_ColorTool::GetColor, "Returns color defined by label lab Returns False if the label is not in colortable or does not define a color", py::arg("lab"), py::arg("col"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, Quantity_ColorRGBA &) const) &XCAFDoc_ColorTool::GetColor, "Returns color defined by label lab Returns False if the label is not in colortable or does not define a color", py::arg("lab"), py::arg("col"));
cls_XCAFDoc_ColorTool.def("FindColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const Quantity_Color &, TDF_Label &) const) &XCAFDoc_ColorTool::FindColor, "Finds a color definition in a colortable and returns its label if found Returns False if color is not found in colortable", py::arg("col"), py::arg("lab"));
cls_XCAFDoc_ColorTool.def("FindColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const Quantity_ColorRGBA &, TDF_Label &) const) &XCAFDoc_ColorTool::FindColor, "Finds a color definition in a colortable and returns its label if found Returns False if color is not found in colortable", py::arg("col"), py::arg("lab"));
cls_XCAFDoc_ColorTool.def("FindColor", (TDF_Label (XCAFDoc_ColorTool::*)(const Quantity_Color &) const) &XCAFDoc_ColorTool::FindColor, "Finds a color definition in a colortable and returns its label if found (or Null label else)", py::arg("col"));
cls_XCAFDoc_ColorTool.def("FindColor", (TDF_Label (XCAFDoc_ColorTool::*)(const Quantity_ColorRGBA &) const) &XCAFDoc_ColorTool::FindColor, "Finds a color definition in a colortable and returns its label if found (or Null label else)", py::arg("col"));
cls_XCAFDoc_ColorTool.def("AddColor", (TDF_Label (XCAFDoc_ColorTool::*)(const Quantity_Color &) const) &XCAFDoc_ColorTool::AddColor, "Adds a color definition to a colortable and returns its label (returns existing label if the same color is already defined)", py::arg("col"));
cls_XCAFDoc_ColorTool.def("AddColor", (TDF_Label (XCAFDoc_ColorTool::*)(const Quantity_ColorRGBA &) const) &XCAFDoc_ColorTool::AddColor, "Adds a color definition to a colortable and returns its label (returns existing label if the same color is already defined)", py::arg("col"));
cls_XCAFDoc_ColorTool.def("RemoveColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &) const) &XCAFDoc_ColorTool::RemoveColor, "Removes color from the colortable", py::arg("lab"));
cls_XCAFDoc_ColorTool.def("GetColors", (void (XCAFDoc_ColorTool::*)(TDF_LabelSequence &) const) &XCAFDoc_ColorTool::GetColors, "Returns a sequence of colors currently stored in the colortable", py::arg("Labels"));
cls_XCAFDoc_ColorTool.def("SetColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const TDF_Label &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color defined by <colorL>. Color of shape is defined following way in dependance with type of color. If type of color is XCAFDoc_ColorGen - then this color defines default color for surfaces and curves. If for shape color with types XCAFDoc_ColorSurf or XCAFDoc_ColorCurv is specified then such color overrides generic color.", py::arg("L"), py::arg("colorL"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("SetColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const Quantity_Color &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color <Color> in the colortable Adds a color as necessary", py::arg("L"), py::arg("Color"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("SetColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const Quantity_ColorRGBA &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color <Color> in the colortable Adds a color as necessary", py::arg("L"), py::arg("Color"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("UnSetColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::UnSetColor, "Removes a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color", py::arg("L"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("IsSet", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::IsSet, "Returns True if label <L> has a color assignment of the type <type>", py::arg("L"), py::arg("type"));
cls_XCAFDoc_ColorTool.def_static("GetColor_", (Standard_Boolean (*)(const TDF_Label &, const XCAFDoc_ColorType, TDF_Label &)) &XCAFDoc_ColorTool::GetColor, "Returns label with color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("L"), py::arg("type"), py::arg("colorL"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, const XCAFDoc_ColorType, Quantity_Color &)) &XCAFDoc_ColorTool::GetColor, "Returns color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("L"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, const XCAFDoc_ColorType, Quantity_ColorRGBA &)) &XCAFDoc_ColorTool::GetColor, "Returns color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("L"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("SetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const TDF_Label &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color defined by <colorL> Returns False if cannot find a label for shape S", py::arg("S"), py::arg("colorL"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("SetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const Quantity_Color &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color <Color> in the colortable Adds a color as necessary Returns False if cannot find a label for shape S", py::arg("S"), py::arg("Color"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("SetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const Quantity_ColorRGBA &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color <Color> in the colortable Adds a color as necessary Returns False if cannot find a label for shape S", py::arg("S"), py::arg("Color"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("UnSetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::UnSetColor, "Removes a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color Returns True if such link existed", py::arg("S"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("IsSet", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::IsSet, "Returns True if label <L> has a color assignment of the type <type>", py::arg("S"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, TDF_Label &)) &XCAFDoc_ColorTool::GetColor, "Returns label with color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("S"), py::arg("type"), py::arg("colorL"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, Quantity_Color &)) &XCAFDoc_ColorTool::GetColor, "Returns color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("S"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, Quantity_ColorRGBA &)) &XCAFDoc_ColorTool::GetColor, "Returns color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("S"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("IsVisible", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &) const) &XCAFDoc_ColorTool::IsVisible, "Return TRUE if object on this label is visible, FALSE if invisible.", py::arg("L"));
cls_XCAFDoc_ColorTool.def("SetVisibility", [](XCAFDoc_ColorTool &self, const TDF_Label & a0) -> void { return self.SetVisibility(a0); });
cls_XCAFDoc_ColorTool.def("SetVisibility", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_ColorTool::SetVisibility, "Set the visibility of object on label. Do nothing if there no any object. Set UAttribute with corresponding GUID.", py::arg("shapeLabel"), py::arg("isvisible"));
cls_XCAFDoc_ColorTool.def("IsColorByLayer", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &) const) &XCAFDoc_ColorTool::IsColorByLayer, "Return TRUE if object color defined by its Layer, FALSE if not.", py::arg("L"));
cls_XCAFDoc_ColorTool.def("SetColorByLayer", [](XCAFDoc_ColorTool &self, const TDF_Label & a0) -> void { return self.SetColorByLayer(a0); });
cls_XCAFDoc_ColorTool.def("SetColorByLayer", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_ColorTool::SetColorByLayer, "Set the Color defined by Layer flag on label. Do nothing if there no any object. Set UAttribute with corresponding GUID.", py::arg("shapeLabel"), py::arg("isColorByLayer"));
cls_XCAFDoc_ColorTool.def("SetInstanceColor", [](XCAFDoc_ColorTool &self, const TopoDS_Shape & a0, const XCAFDoc_ColorType a1, const Quantity_Color & a2) -> Standard_Boolean { return self.SetInstanceColor(a0, a1, a2); });
cls_XCAFDoc_ColorTool.def("SetInstanceColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, const Quantity_Color &, const Standard_Boolean)) &XCAFDoc_ColorTool::SetInstanceColor, "Sets the color of component that styled with SHUO structure Returns FALSE if no sush component found NOTE: create SHUO structeure if it is necessary and if <isCreateSHUO>", py::arg("theShape"), py::arg("type"), py::arg("color"), py::arg("isCreateSHUO"));
cls_XCAFDoc_ColorTool.def("SetInstanceColor", [](XCAFDoc_ColorTool &self, const TopoDS_Shape & a0, const XCAFDoc_ColorType a1, const Quantity_ColorRGBA & a2) -> Standard_Boolean { return self.SetInstanceColor(a0, a1, a2); });
cls_XCAFDoc_ColorTool.def("SetInstanceColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, const Quantity_ColorRGBA &, const Standard_Boolean)) &XCAFDoc_ColorTool::SetInstanceColor, "Sets the color of component that styled with SHUO structure Returns FALSE if no sush component found NOTE: create SHUO structeure if it is necessary and if <isCreateSHUO>", py::arg("theShape"), py::arg("type"), py::arg("color"), py::arg("isCreateSHUO"));
cls_XCAFDoc_ColorTool.def("GetInstanceColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, Quantity_Color &)) &XCAFDoc_ColorTool::GetInstanceColor, "Gets the color of component that styled with SHUO structure Returns FALSE if no sush component or color type", py::arg("theShape"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("GetInstanceColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, Quantity_ColorRGBA &)) &XCAFDoc_ColorTool::GetInstanceColor, "Gets the color of component that styled with SHUO structure Returns FALSE if no sush component or color type", py::arg("theShape"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("IsInstanceVisible", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &)) &XCAFDoc_ColorTool::IsInstanceVisible, "Gets the visibility status of component that styled with SHUO structure Returns FALSE if no sush component", py::arg("theShape"));
cls_XCAFDoc_ColorTool.def("ReverseChainsOfTreeNodes", (Standard_Boolean (XCAFDoc_ColorTool::*)()) &XCAFDoc_ColorTool::ReverseChainsOfTreeNodes, "Reverses order in chains of TreeNodes (from Last to First) under each Color Label since we became to use function ::Prepend() instead of ::Append() in method SetColor() for acceleration");
cls_XCAFDoc_ColorTool.def("ID", (const Standard_GUID & (XCAFDoc_ColorTool::*)() const) &XCAFDoc_ColorTool::ID, "None");
cls_XCAFDoc_ColorTool.def("Restore", (void (XCAFDoc_ColorTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_ColorTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_ColorTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_ColorTool::*)() const) &XCAFDoc_ColorTool::NewEmpty, "None");
cls_XCAFDoc_ColorTool.def("Paste", (void (XCAFDoc_ColorTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_ColorTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_ColorTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ColorTool::get_type_name, "None");
cls_XCAFDoc_ColorTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ColorTool::get_type_descriptor, "None");
cls_XCAFDoc_ColorTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ColorTool::*)() const) &XCAFDoc_ColorTool::DynamicType, "None");

// CLASS: XCAFDOC_DATUM
py::class_<XCAFDoc_Datum, opencascade::handle<XCAFDoc_Datum>, TDF_Attribute> cls_XCAFDoc_Datum(mod, "XCAFDoc_Datum", "attribute to store datum");

// Constructors
cls_XCAFDoc_Datum.def(py::init<>());

// Methods
cls_XCAFDoc_Datum.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Datum::GetID, "None");
cls_XCAFDoc_Datum.def_static("Set_", (opencascade::handle<XCAFDoc_Datum> (*)(const TDF_Label &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_Datum::Set, "None", py::arg("label"), py::arg("aName"), py::arg("aDescription"), py::arg("anIdentification"));
cls_XCAFDoc_Datum.def_static("Set_", (opencascade::handle<XCAFDoc_Datum> (*)(const TDF_Label &)) &XCAFDoc_Datum::Set, "None", py::arg("theLabel"));
cls_XCAFDoc_Datum.def("Set", (void (XCAFDoc_Datum::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_Datum::Set, "None", py::arg("aName"), py::arg("aDescription"), py::arg("anIdentification"));
cls_XCAFDoc_Datum.def("GetName", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::GetName, "None");
cls_XCAFDoc_Datum.def("GetDescription", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::GetDescription, "None");
cls_XCAFDoc_Datum.def("GetIdentification", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::GetIdentification, "None");
cls_XCAFDoc_Datum.def("GetObject", (opencascade::handle<XCAFDimTolObjects_DatumObject> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::GetObject, "Returns dimension object data taken from the paren's label and its sub-labels.");
cls_XCAFDoc_Datum.def("SetObject", (void (XCAFDoc_Datum::*)(const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDoc_Datum::SetObject, "Updates parent's label and its sub-labels with data taken from theDatumObject. Old data associated with the label will be lost.", py::arg("theDatumObject"));
cls_XCAFDoc_Datum.def("ID", (const Standard_GUID & (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::ID, "None");
cls_XCAFDoc_Datum.def("Restore", (void (XCAFDoc_Datum::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Datum::Restore, "None", py::arg("With"));
cls_XCAFDoc_Datum.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::NewEmpty, "None");
cls_XCAFDoc_Datum.def("Paste", (void (XCAFDoc_Datum::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Datum::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Datum.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Datum::get_type_name, "None");
cls_XCAFDoc_Datum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Datum::get_type_descriptor, "None");
cls_XCAFDoc_Datum.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::DynamicType, "None");

// CLASS: XCAFDOC_DIMENSION
py::class_<XCAFDoc_Dimension, opencascade::handle<XCAFDoc_Dimension>, TDF_Attribute> cls_XCAFDoc_Dimension(mod, "XCAFDoc_Dimension", "Attribute that identifies a dimension in the GD&T table. Its parent label is used as a container to store data provided by XCAFDimTolObjects_DimensionObject.");

// Constructors
cls_XCAFDoc_Dimension.def(py::init<>());

// Methods
cls_XCAFDoc_Dimension.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Dimension::GetID, "None");
cls_XCAFDoc_Dimension.def_static("Set_", (opencascade::handle<XCAFDoc_Dimension> (*)(const TDF_Label &)) &XCAFDoc_Dimension::Set, "None", py::arg("theLabel"));
cls_XCAFDoc_Dimension.def("ID", (const Standard_GUID & (XCAFDoc_Dimension::*)() const) &XCAFDoc_Dimension::ID, "None");
cls_XCAFDoc_Dimension.def("Restore", (void (XCAFDoc_Dimension::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Dimension::Restore, "None", py::arg("With"));
cls_XCAFDoc_Dimension.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Dimension::*)() const) &XCAFDoc_Dimension::NewEmpty, "None");
cls_XCAFDoc_Dimension.def("Paste", (void (XCAFDoc_Dimension::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Dimension::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Dimension.def("SetObject", (void (XCAFDoc_Dimension::*)(const opencascade::handle<XCAFDimTolObjects_DimensionObject> &)) &XCAFDoc_Dimension::SetObject, "Updates parent's label and its sub-labels with data taken from theDimensionObject. Old data associated with the label will be lost.", py::arg("theDimensionObject"));
cls_XCAFDoc_Dimension.def("GetObject", (opencascade::handle<XCAFDimTolObjects_DimensionObject> (XCAFDoc_Dimension::*)() const) &XCAFDoc_Dimension::GetObject, "Returns dimension object data taken from the paren's label and its sub-labels.");
cls_XCAFDoc_Dimension.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Dimension::get_type_name, "None");
cls_XCAFDoc_Dimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Dimension::get_type_descriptor, "None");
cls_XCAFDoc_Dimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Dimension::*)() const) &XCAFDoc_Dimension::DynamicType, "None");

// CLASS: XCAFDOC_DIMTOL
py::class_<XCAFDoc_DimTol, opencascade::handle<XCAFDoc_DimTol>, TDF_Attribute> cls_XCAFDoc_DimTol(mod, "XCAFDoc_DimTol", "attribute to store dimension and tolerance");

// Constructors
cls_XCAFDoc_DimTol.def(py::init<>());

// Methods
cls_XCAFDoc_DimTol.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_DimTol::GetID, "None");
cls_XCAFDoc_DimTol.def_static("Set_", (opencascade::handle<XCAFDoc_DimTol> (*)(const TDF_Label &, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_DimTol::Set, "None", py::arg("label"), py::arg("kind"), py::arg("aVal"), py::arg("aName"), py::arg("aDescription"));
cls_XCAFDoc_DimTol.def("Set", (void (XCAFDoc_DimTol::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_DimTol::Set, "None", py::arg("kind"), py::arg("aVal"), py::arg("aName"), py::arg("aDescription"));
cls_XCAFDoc_DimTol.def("GetKind", (Standard_Integer (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::GetKind, "None");
cls_XCAFDoc_DimTol.def("GetVal", (opencascade::handle<TColStd_HArray1OfReal> (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::GetVal, "None");
cls_XCAFDoc_DimTol.def("GetName", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::GetName, "None");
cls_XCAFDoc_DimTol.def("GetDescription", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::GetDescription, "None");
cls_XCAFDoc_DimTol.def("ID", (const Standard_GUID & (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::ID, "None");
cls_XCAFDoc_DimTol.def("Restore", (void (XCAFDoc_DimTol::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_DimTol::Restore, "None", py::arg("With"));
cls_XCAFDoc_DimTol.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::NewEmpty, "None");
cls_XCAFDoc_DimTol.def("Paste", (void (XCAFDoc_DimTol::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_DimTol::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_DimTol.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_DimTol::get_type_name, "None");
cls_XCAFDoc_DimTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_DimTol::get_type_descriptor, "None");
cls_XCAFDoc_DimTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_DimTol::*)() const) &XCAFDoc_DimTol::DynamicType, "None");

// CLASS: XCAFDOC_DOCUMENTTOOL
py::class_<XCAFDoc_DocumentTool, opencascade::handle<XCAFDoc_DocumentTool>, TDF_Attribute> cls_XCAFDoc_DocumentTool(mod, "XCAFDoc_DocumentTool", "Defines sections structure of an XDE document. attribute marking CAF document as being DECAF document. Creates the sections structure of the document.");

// Constructors
cls_XCAFDoc_DocumentTool.def(py::init<>());

// Methods
cls_XCAFDoc_DocumentTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_DocumentTool::GetID, "None");
cls_XCAFDoc_DocumentTool.def_static("Set_", [](const TDF_Label & a0) -> opencascade::handle<XCAFDoc_DocumentTool> { return XCAFDoc_DocumentTool::Set(a0); });
cls_XCAFDoc_DocumentTool.def_static("Set_", (opencascade::handle<XCAFDoc_DocumentTool> (*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_DocumentTool::Set, "Create (if not exist) DocumentTool attribute on 0.1 label if <IsAcces> is true, else on <L> label. This label will be returned by DocLabel(); If the attribute is already set it won't be reset on <L> even if <IsAcces> is false. ColorTool and ShapeTool attributes are also set by this method.", py::arg("L"), py::arg("IsAcces"));
cls_XCAFDoc_DocumentTool.def_static("IsXCAFDocument_", (Standard_Boolean (*)(const opencascade::handle<TDocStd_Document> &)) &XCAFDoc_DocumentTool::IsXCAFDocument, "None", py::arg("Doc"));
cls_XCAFDoc_DocumentTool.def_static("DocLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::DocLabel, "Returns label where the DocumentTool attribute is or 0.1 if DocumentTool is not yet set.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ShapesLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ShapesLabel, "Returns sub-label of DocLabel() with tag 1.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ColorsLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ColorsLabel, "Returns sub-label of DocLabel() with tag 2.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("LayersLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::LayersLabel, "Returns sub-label of DocLabel() with tag 3.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("DGTsLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::DGTsLabel, "Returns sub-label of DocLabel() with tag 4.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("MaterialsLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::MaterialsLabel, "Returns sub-label of DocLabel() with tag 5.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ViewsLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ViewsLabel, "Returns sub-label of DocLabel() with tag 7.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ClippingPlanesLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ClippingPlanesLabel, "Returns sub-label of DocLabel() with tag 8.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("NotesLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::NotesLabel, "Returns sub-label of DocLabel() with tag 9.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ShapeTool_", (opencascade::handle<XCAFDoc_ShapeTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ShapeTool, "Creates (if it does not exist) ShapeTool attribute on ShapesLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ColorTool_", (opencascade::handle<XCAFDoc_ColorTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ColorTool, "Creates (if it does not exist) ColorTool attribute on ColorsLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("LayerTool_", (opencascade::handle<XCAFDoc_LayerTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::LayerTool, "Creates (if it does not exist) LayerTool attribute on LayersLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("DimTolTool_", (opencascade::handle<XCAFDoc_DimTolTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::DimTolTool, "Creates (if it does not exist) DimTolTool attribute on DGTsLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("MaterialTool_", (opencascade::handle<XCAFDoc_MaterialTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::MaterialTool, "Creates (if it does not exist) DimTolTool attribute on DGTsLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ViewTool_", (opencascade::handle<XCAFDoc_ViewTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ViewTool, "Creates (if it does not exist) ViewTool attribute on ViewsLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ClippingPlaneTool_", (opencascade::handle<XCAFDoc_ClippingPlaneTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ClippingPlaneTool, "Creates (if it does not exist) ClippingPlaneTool attribute on ClippingPlanesLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("NotesTool_", (opencascade::handle<XCAFDoc_NotesTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::NotesTool, "Creates (if it does not exist) NotesTool attribute on NotesLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def("Init", (void (XCAFDoc_DocumentTool::*)() const) &XCAFDoc_DocumentTool::Init, "to be called when reading this attribute from file");
cls_XCAFDoc_DocumentTool.def("ID", (const Standard_GUID & (XCAFDoc_DocumentTool::*)() const) &XCAFDoc_DocumentTool::ID, "None");
cls_XCAFDoc_DocumentTool.def("Restore", (void (XCAFDoc_DocumentTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_DocumentTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_DocumentTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_DocumentTool::*)() const) &XCAFDoc_DocumentTool::NewEmpty, "None");
cls_XCAFDoc_DocumentTool.def("Paste", (void (XCAFDoc_DocumentTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_DocumentTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_DocumentTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_DocumentTool::get_type_name, "None");
cls_XCAFDoc_DocumentTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_DocumentTool::get_type_descriptor, "None");
cls_XCAFDoc_DocumentTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_DocumentTool::*)() const) &XCAFDoc_DocumentTool::DynamicType, "None");

// CLASS: XCAFDOC_EDITOR
py::class_<XCAFDoc_Editor> cls_XCAFDoc_Editor(mod, "XCAFDoc_Editor", "Tool for edit structure of document.");

// Constructors
cls_XCAFDoc_Editor.def(py::init<>());

// Methods
// cls_XCAFDoc_Editor.def_static("operator new_", (void * (*)(size_t)) &XCAFDoc_Editor::operator new, "None", py::arg("theSize"));
// cls_XCAFDoc_Editor.def_static("operator delete_", (void (*)(void *)) &XCAFDoc_Editor::operator delete, "None", py::arg("theAddress"));
// cls_XCAFDoc_Editor.def_static("operator new[]_", (void * (*)(size_t)) &XCAFDoc_Editor::operator new[], "None", py::arg("theSize"));
// cls_XCAFDoc_Editor.def_static("operator delete[]_", (void (*)(void *)) &XCAFDoc_Editor::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFDoc_Editor.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFDoc_Editor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFDoc_Editor.def_static("operator delete_", (void (*)(void *, void *)) &XCAFDoc_Editor::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFDoc_Editor.def_static("Expand_", [](const TDF_Label & a0, const TDF_Label & a1) -> Standard_Boolean { return XCAFDoc_Editor::Expand(a0, a1); });
cls_XCAFDoc_Editor.def_static("Expand_", (Standard_Boolean (*)(const TDF_Label &, const TDF_Label &, const Standard_Boolean)) &XCAFDoc_Editor::Expand, "Convert Shape (compound/compsolid/shell/wire) to assembly. Only compounds expanded recursively", py::arg("Doc"), py::arg("Shape"), py::arg("recursively"));
cls_XCAFDoc_Editor.def_static("Expand_", [](const TDF_Label & a0) -> Standard_Boolean { return XCAFDoc_Editor::Expand(a0); });
cls_XCAFDoc_Editor.def_static("Expand_", (Standard_Boolean (*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_Editor::Expand, "Convert all compounds in Doc to assembly", py::arg("Doc"), py::arg("recursively"));

// CLASS: XCAFDOC_GEOMTOLERANCE
py::class_<XCAFDoc_GeomTolerance, opencascade::handle<XCAFDoc_GeomTolerance>, TDF_Attribute> cls_XCAFDoc_GeomTolerance(mod, "XCAFDoc_GeomTolerance", "Attribute to store dimension and tolerance");

// Constructors
cls_XCAFDoc_GeomTolerance.def(py::init<>());
// cls_XCAFDoc_GeomTolerance.def(py::init<const opencascade::handle<XCAFDoc_GeomTolerance> &>(), py::arg("theObj"));

// Methods
cls_XCAFDoc_GeomTolerance.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_GeomTolerance::GetID, "None");
cls_XCAFDoc_GeomTolerance.def_static("Set_", (opencascade::handle<XCAFDoc_GeomTolerance> (*)(const TDF_Label &)) &XCAFDoc_GeomTolerance::Set, "None", py::arg("theLabel"));
cls_XCAFDoc_GeomTolerance.def("SetObject", (void (XCAFDoc_GeomTolerance::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDoc_GeomTolerance::SetObject, "Updates parent's label and its sub-labels with data taken from theGeomToleranceObject. Old data associated with the label will be lost.", py::arg("theGeomToleranceObject"));
cls_XCAFDoc_GeomTolerance.def("GetObject", (opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> (XCAFDoc_GeomTolerance::*)() const) &XCAFDoc_GeomTolerance::GetObject, "Returns geometry tolerance object data taken from the paren's label and its sub-labels.");
cls_XCAFDoc_GeomTolerance.def("ID", (const Standard_GUID & (XCAFDoc_GeomTolerance::*)() const) &XCAFDoc_GeomTolerance::ID, "None");
cls_XCAFDoc_GeomTolerance.def("Restore", (void (XCAFDoc_GeomTolerance::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_GeomTolerance::Restore, "None", py::arg("With"));
cls_XCAFDoc_GeomTolerance.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_GeomTolerance::*)() const) &XCAFDoc_GeomTolerance::NewEmpty, "None");
cls_XCAFDoc_GeomTolerance.def("Paste", (void (XCAFDoc_GeomTolerance::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_GeomTolerance::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_GeomTolerance.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_GeomTolerance::get_type_name, "None");
cls_XCAFDoc_GeomTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_GeomTolerance::get_type_descriptor, "None");
cls_XCAFDoc_GeomTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_GeomTolerance::*)() const) &XCAFDoc_GeomTolerance::DynamicType, "None");

// TYPEDEF: XCAFDOC_GRAPHNODESEQUENCE
bind_NCollection_Sequence<opencascade::handle<XCAFDoc_GraphNode> >(mod, "XCAFDoc_GraphNodeSequence", py::module_local(false));

// CLASS: XCAFDOC_GRAPHNODE
py::class_<XCAFDoc_GraphNode, opencascade::handle<XCAFDoc_GraphNode>, TDF_Attribute> cls_XCAFDoc_GraphNode(mod, "XCAFDoc_GraphNode", "This attribute allow user multirelation tree of labels. This GraphNode is experimental Graph that not control looping and redundance. Attribute containg sequence of father's and child's labels. Provide create and work with Graph in XCAFDocument.");

// Constructors
cls_XCAFDoc_GraphNode.def(py::init<>());

// Methods
cls_XCAFDoc_GraphNode.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::Find, "class methods working on the node =================================== Shortcut to search a Graph node attribute with default GraphID. Returns true if found.", py::arg("L"), py::arg("G"));
cls_XCAFDoc_GraphNode.def_static("Set_", (opencascade::handle<XCAFDoc_GraphNode> (*)(const TDF_Label &)) &XCAFDoc_GraphNode::Set, "Finds or Creates a GraphNode attribute on the label <L> with the default Graph ID, returned by the method <GetDefaultGraphID>. Returns the created/found GraphNode attribute.", py::arg("L"));
cls_XCAFDoc_GraphNode.def_static("Set_", (opencascade::handle<XCAFDoc_GraphNode> (*)(const TDF_Label &, const Standard_GUID &)) &XCAFDoc_GraphNode::Set, "Finds or Creates a GraphNode attribute on the label <L>, with an explicit tree ID. <ExplicitGraphID> is the ID returned by <TDF_Attribute::ID> method. Returns the found/created GraphNode attribute.", py::arg("L"), py::arg("ExplicitGraphID"));
cls_XCAFDoc_GraphNode.def_static("GetDefaultGraphID_", (const Standard_GUID & (*)()) &XCAFDoc_GraphNode::GetDefaultGraphID, "returns a default Graph ID. this ID is used by the <Set> method without explicit tree ID. Instance methods: ================");
cls_XCAFDoc_GraphNode.def("SetGraphID", (void (XCAFDoc_GraphNode::*)(const Standard_GUID &)) &XCAFDoc_GraphNode::SetGraphID, "None", py::arg("explicitID"));
cls_XCAFDoc_GraphNode.def("SetFather", (Standard_Integer (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::SetFather, "Set GraphNode <F> as father of me and returns index of <F> in Sequence that containing Fathers GraphNodes. return index of <F> from GraphNodeSequnece", py::arg("F"));
cls_XCAFDoc_GraphNode.def("SetChild", (Standard_Integer (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::SetChild, "Set GraphNode <Ch> as child of me and returns index of <Ch> in Sequence that containing Children GraphNodes. return index of <Ch> from GraphNodeSequnece", py::arg("Ch"));
cls_XCAFDoc_GraphNode.def("UnSetFather", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::UnSetFather, "Remove <F> from Fathers GraphNodeSequence. and remove link between father and child.", py::arg("F"));
cls_XCAFDoc_GraphNode.def("UnSetFather", (void (XCAFDoc_GraphNode::*)(const Standard_Integer)) &XCAFDoc_GraphNode::UnSetFather, "Remove Father GraphNode by index from Fathers GraphNodeSequence. and remove link between father and child.", py::arg("Findex"));
cls_XCAFDoc_GraphNode.def("UnSetChild", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::UnSetChild, "Remove <Ch> from GraphNodeSequence. and remove link between father and child.", py::arg("Ch"));
cls_XCAFDoc_GraphNode.def("UnSetChild", (void (XCAFDoc_GraphNode::*)(const Standard_Integer)) &XCAFDoc_GraphNode::UnSetChild, "Remove Child GraphNode by index from Children GraphNodeSequence. and remove link between father and child.", py::arg("Chindex"));
cls_XCAFDoc_GraphNode.def("GetFather", (opencascade::handle<XCAFDoc_GraphNode> (XCAFDoc_GraphNode::*)(const Standard_Integer) const) &XCAFDoc_GraphNode::GetFather, "Return GraphNode by index from GraphNodeSequence.", py::arg("Findex"));
cls_XCAFDoc_GraphNode.def("GetChild", (opencascade::handle<XCAFDoc_GraphNode> (XCAFDoc_GraphNode::*)(const Standard_Integer) const) &XCAFDoc_GraphNode::GetChild, "Return GraphNode by index from GraphNodeSequence.", py::arg("Chindex"));
cls_XCAFDoc_GraphNode.def("FatherIndex", (Standard_Integer (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_GraphNode::FatherIndex, "Return index of <F>, or zero if there is no such Graphnode.", py::arg("F"));
cls_XCAFDoc_GraphNode.def("ChildIndex", (Standard_Integer (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_GraphNode::ChildIndex, "Return index of <Ch>, or zero if there is no such Graphnode.", py::arg("Ch"));
cls_XCAFDoc_GraphNode.def("IsFather", (Standard_Boolean (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_GraphNode::IsFather, "returns TRUE if <me> is father of <Ch>.", py::arg("Ch"));
cls_XCAFDoc_GraphNode.def("IsChild", (Standard_Boolean (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_GraphNode::IsChild, "returns TRUE if <me> is child of <F>.", py::arg("F"));
cls_XCAFDoc_GraphNode.def("NbFathers", (Standard_Integer (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::NbFathers, "return Number of Fathers GraphNodes.");
cls_XCAFDoc_GraphNode.def("NbChildren", (Standard_Integer (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::NbChildren, "return Number of Childrens GraphNodes. Implementation of Attribute methods: ===================================");
cls_XCAFDoc_GraphNode.def("ID", (const Standard_GUID & (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::ID, "Returns the Graph ID (default or explicit one depending onthe Set method used).");
cls_XCAFDoc_GraphNode.def("Restore", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_GraphNode::Restore, "None", py::arg("with"));
cls_XCAFDoc_GraphNode.def("Paste", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_GraphNode::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_GraphNode.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::NewEmpty, "None");
cls_XCAFDoc_GraphNode.def("References", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<TDF_DataSet> &) const) &XCAFDoc_GraphNode::References, "None", py::arg("aDataSet"));
cls_XCAFDoc_GraphNode.def("Dump", (Standard_OStream & (XCAFDoc_GraphNode::*)(Standard_OStream &) const) &XCAFDoc_GraphNode::Dump, "None", py::arg("anOS"));
cls_XCAFDoc_GraphNode.def("BeforeForget", (void (XCAFDoc_GraphNode::*)()) &XCAFDoc_GraphNode::BeforeForget, "None");
cls_XCAFDoc_GraphNode.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_GraphNode::get_type_name, "None");
cls_XCAFDoc_GraphNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_GraphNode::get_type_descriptor, "None");
cls_XCAFDoc_GraphNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::DynamicType, "None");

// CLASS: XCAFDOC_LAYERTOOL
py::class_<XCAFDoc_LayerTool, opencascade::handle<XCAFDoc_LayerTool>, TDF_Attribute> cls_XCAFDoc_LayerTool(mod, "XCAFDoc_LayerTool", "Provides tools to store and retrieve attributes (Layers) of TopoDS_Shape in and from TDocStd_Document A Document is intended to hold different attributes of ONE shape and it's sub-shapes Provide tools for management of Layers section of document.");

// Constructors
cls_XCAFDoc_LayerTool.def(py::init<>());

// Methods
cls_XCAFDoc_LayerTool.def_static("Set_", (opencascade::handle<XCAFDoc_LayerTool> (*)(const TDF_Label &)) &XCAFDoc_LayerTool::Set, "Creates (if not exist) LayerTool.", py::arg("L"));
cls_XCAFDoc_LayerTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_LayerTool::GetID, "None");
cls_XCAFDoc_LayerTool.def("BaseLabel", (TDF_Label (XCAFDoc_LayerTool::*)() const) &XCAFDoc_LayerTool::BaseLabel, "returns the label under which Layers are stored");
cls_XCAFDoc_LayerTool.def("ShapeTool", (const opencascade::handle<XCAFDoc_ShapeTool> & (XCAFDoc_LayerTool::*)()) &XCAFDoc_LayerTool::ShapeTool, "Returns internal XCAFDoc_ShapeTool tool");
cls_XCAFDoc_LayerTool.def("IsLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &) const) &XCAFDoc_LayerTool::IsLayer, "Returns True if label belongs to a Layertable and is a Layer definition", py::arg("lab"));
cls_XCAFDoc_LayerTool.def("GetLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::GetLayer, "Returns Layer defined by label lab Returns False if the label is not in Layertable or does not define a Layer", py::arg("lab"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("FindLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TCollection_ExtendedString &, TDF_Label &) const) &XCAFDoc_LayerTool::FindLayer, "Finds a Layer definition in a Layertable and returns its label if found Returns False if Layer is not found in Layertable", py::arg("aLayer"), py::arg("lab"));
cls_XCAFDoc_LayerTool.def("FindLayer", (TDF_Label (XCAFDoc_LayerTool::*)(const TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::FindLayer, "Finds a Layer definition in a Layertable and returns its label if found (or Null label else)", py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("AddLayer", (TDF_Label (XCAFDoc_LayerTool::*)(const TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::AddLayer, "Adds a Layer definition to a Layertable and returns its label (returns existing label if the same Layer is already defined)", py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("RemoveLayer", (void (XCAFDoc_LayerTool::*)(const TDF_Label &) const) &XCAFDoc_LayerTool::RemoveLayer, "Removes Layer from the Layertable", py::arg("lab"));
cls_XCAFDoc_LayerTool.def("GetLayerLabels", (void (XCAFDoc_LayerTool::*)(TDF_LabelSequence &) const) &XCAFDoc_LayerTool::GetLayerLabels, "Returns a sequence of Layers currently stored in the Layertable", py::arg("Labels"));
cls_XCAFDoc_LayerTool.def("SetLayer", [](XCAFDoc_LayerTool &self, const TDF_Label & a0, const TDF_Label & a1) -> void { return self.SetLayer(a0, a1); });
cls_XCAFDoc_LayerTool.def("SetLayer", (void (XCAFDoc_LayerTool::*)(const TDF_Label &, const TDF_Label &, const Standard_Boolean) const) &XCAFDoc_LayerTool::SetLayer, "Sets a link from label <L> to Layer defined by <LayerL> optional parametr <shapeInOneLayer> show could shape be in number of layers or only in one.", py::arg("L"), py::arg("LayerL"), py::arg("shapeInOneLayer"));
cls_XCAFDoc_LayerTool.def("SetLayer", [](XCAFDoc_LayerTool &self, const TDF_Label & a0, const TCollection_ExtendedString & a1) -> void { return self.SetLayer(a0, a1); });
cls_XCAFDoc_LayerTool.def("SetLayer", (void (XCAFDoc_LayerTool::*)(const TDF_Label &, const TCollection_ExtendedString &, const Standard_Boolean) const) &XCAFDoc_LayerTool::SetLayer, "Sets a link from label <L> to Layer <aLayer> in the Layertable Adds a Layer as necessary optional parametr <shapeInOneLayer> show could shape be in number of layers or only in one.", py::arg("L"), py::arg("aLayer"), py::arg("shapeInOneLayer"));
cls_XCAFDoc_LayerTool.def("UnSetLayers", (void (XCAFDoc_LayerTool::*)(const TDF_Label &) const) &XCAFDoc_LayerTool::UnSetLayers, "Removes a link from label <L> to all layers", py::arg("L"));
cls_XCAFDoc_LayerTool.def("UnSetOneLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, const TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::UnSetOneLayer, "Remove link from label <L> and Layer <aLayer>. returns FALSE if no such layer.", py::arg("L"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("UnSetOneLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_LayerTool::UnSetOneLayer, "Remove link from label <L> and Layer <aLayerL>. returns FALSE if <aLayerL> is not a layer label.", py::arg("L"), py::arg("aLayerL"));
cls_XCAFDoc_LayerTool.def("IsSet", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, const TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::IsSet, "Returns True if label <L> has a Layer assosiated with the <aLayer>.", py::arg("L"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("IsSet", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_LayerTool::IsSet, "Returns True if label <L> has a Layer assosiated with the <aLayerL> label.", py::arg("L"), py::arg("aLayerL"));
cls_XCAFDoc_LayerTool.def("GetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, opencascade::handle<TColStd_HSequenceOfExtendedString> &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of strings <aLayerS> that assosiated with label <L>.", py::arg("L"), py::arg("aLayerS"));
cls_XCAFDoc_LayerTool.def("GetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, TDF_LabelSequence &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of labels <aLayerSL> that assosiated with label <L>.", py::arg("L"), py::arg("aLayerLS"));
cls_XCAFDoc_LayerTool.def("GetLayers", (opencascade::handle<TColStd_HSequenceOfExtendedString> (XCAFDoc_LayerTool::*)(const TDF_Label &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of strings that assosiated with label <L>.", py::arg("L"));
cls_XCAFDoc_LayerTool.def("GetShapesOfLayer", (void (XCAFDoc_LayerTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_LayerTool::GetShapesOfLayer, "Return sequanese of shape labels that assigned with layers to <ShLabels>.", py::arg("layerL"), py::arg("ShLabels"));
cls_XCAFDoc_LayerTool.def("IsVisible", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &) const) &XCAFDoc_LayerTool::IsVisible, "Return TRUE if layer is visible, FALSE if invisible.", py::arg("layerL"));
cls_XCAFDoc_LayerTool.def("SetVisibility", [](XCAFDoc_LayerTool &self, const TDF_Label & a0) -> void { return self.SetVisibility(a0); });
cls_XCAFDoc_LayerTool.def("SetVisibility", (void (XCAFDoc_LayerTool::*)(const TDF_Label &, const Standard_Boolean) const) &XCAFDoc_LayerTool::SetVisibility, "Set the visibility of layer. If layer is invisible when on it's layer will set UAttribute with corresponding GUID.", py::arg("layerL"), py::arg("isvisible"));
cls_XCAFDoc_LayerTool.def("SetLayer", [](XCAFDoc_LayerTool &self, const TopoDS_Shape & a0, const TDF_Label & a1) -> Standard_Boolean { return self.SetLayer(a0, a1); });
cls_XCAFDoc_LayerTool.def("SetLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TDF_Label &, const Standard_Boolean)) &XCAFDoc_LayerTool::SetLayer, "Sets a link from label that containig shape <Sh> with layer that situated at label <LayerL>. optional parametr <shapeInOneLayer> show could shape be in number of layers or only in one. return FALSE if no such shape <Sh> or label <LayerL>", py::arg("Sh"), py::arg("LayerL"), py::arg("shapeInOneLayer"));
cls_XCAFDoc_LayerTool.def("SetLayer", [](XCAFDoc_LayerTool &self, const TopoDS_Shape & a0, const TCollection_ExtendedString & a1) -> Standard_Boolean { return self.SetLayer(a0, a1); });
cls_XCAFDoc_LayerTool.def("SetLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TCollection_ExtendedString &, const Standard_Boolean)) &XCAFDoc_LayerTool::SetLayer, "Sets a link from label that containig shape <Sh> with layer <aLayer>. Add <aLayer> to LayerTable if nessesery. optional parametr <shapeInOneLayer> show could shape be in number of layers or only in one. return FALSE if no such shape <Sh>.", py::arg("Sh"), py::arg("aLayer"), py::arg("shapeInOneLayer"));
cls_XCAFDoc_LayerTool.def("UnSetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &)) &XCAFDoc_LayerTool::UnSetLayers, "Remove link between shape <Sh> and all Layers at LayerTable. return FALSE if no such shape <Sh> in XCAF Document.", py::arg("Sh"));
cls_XCAFDoc_LayerTool.def("UnSetOneLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TCollection_ExtendedString &)) &XCAFDoc_LayerTool::UnSetOneLayer, "Remove link between shape <Sh> and layer <aLayer>. returns FALSE if no such layer <aLayer> or shape <Sh>.", py::arg("Sh"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("UnSetOneLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TDF_Label &)) &XCAFDoc_LayerTool::UnSetOneLayer, "Remove link between shape <Sh> and layer <aLayerL>. returns FALSE if no such layer <aLayerL> or shape <Sh>.", py::arg("Sh"), py::arg("aLayerL"));
cls_XCAFDoc_LayerTool.def("IsSet", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TCollection_ExtendedString &)) &XCAFDoc_LayerTool::IsSet, "Returns True if shape <Sh> has a Layer assosiated with the <aLayer>.", py::arg("Sh"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("IsSet", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TDF_Label &)) &XCAFDoc_LayerTool::IsSet, "Returns True if shape <Sh> has a Layer assosiated with the <aLayerL>.", py::arg("Sh"), py::arg("aLayerL"));
cls_XCAFDoc_LayerTool.def("GetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, opencascade::handle<TColStd_HSequenceOfExtendedString> &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of strings <aLayerS> that assosiated with shape <Sh>.", py::arg("Sh"), py::arg("aLayerS"));
cls_XCAFDoc_LayerTool.def("GetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, TDF_LabelSequence &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of labels <aLayerLS> that assosiated with shape <Sh>.", py::arg("Sh"), py::arg("aLayerLS"));
cls_XCAFDoc_LayerTool.def("GetLayers", (opencascade::handle<TColStd_HSequenceOfExtendedString> (XCAFDoc_LayerTool::*)(const TopoDS_Shape &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of strings that assosiated with shape <Sh>.", py::arg("Sh"));
cls_XCAFDoc_LayerTool.def("ID", (const Standard_GUID & (XCAFDoc_LayerTool::*)() const) &XCAFDoc_LayerTool::ID, "None");
cls_XCAFDoc_LayerTool.def("Restore", (void (XCAFDoc_LayerTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_LayerTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_LayerTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_LayerTool::*)() const) &XCAFDoc_LayerTool::NewEmpty, "None");
cls_XCAFDoc_LayerTool.def("Paste", (void (XCAFDoc_LayerTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_LayerTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_LayerTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_LayerTool::get_type_name, "None");
cls_XCAFDoc_LayerTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_LayerTool::get_type_descriptor, "None");
cls_XCAFDoc_LayerTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_LayerTool::*)() const) &XCAFDoc_LayerTool::DynamicType, "None");

// CLASS: XCAFDOC_LOCATION
py::class_<XCAFDoc_Location, opencascade::handle<XCAFDoc_Location>, TDF_Attribute> cls_XCAFDoc_Location(mod, "XCAFDoc_Location", "attribute to store TopLoc_Location");

// Constructors
cls_XCAFDoc_Location.def(py::init<>());

// Methods
cls_XCAFDoc_Location.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Location::GetID, "None");
cls_XCAFDoc_Location.def_static("Set_", (opencascade::handle<XCAFDoc_Location> (*)(const TDF_Label &, const TopLoc_Location &)) &XCAFDoc_Location::Set, "Find, or create, a Location attribute and set it's value the Location attribute is returned. Location methods ===============", py::arg("label"), py::arg("Loc"));
cls_XCAFDoc_Location.def("Set", (void (XCAFDoc_Location::*)(const TopLoc_Location &)) &XCAFDoc_Location::Set, "None", py::arg("Loc"));
cls_XCAFDoc_Location.def("Get", (const TopLoc_Location & (XCAFDoc_Location::*)() const) &XCAFDoc_Location::Get, "Returns True if there is a reference on the same label");
cls_XCAFDoc_Location.def("ID", (const Standard_GUID & (XCAFDoc_Location::*)() const) &XCAFDoc_Location::ID, "None");
cls_XCAFDoc_Location.def("Restore", (void (XCAFDoc_Location::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Location::Restore, "None", py::arg("With"));
cls_XCAFDoc_Location.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Location::*)() const) &XCAFDoc_Location::NewEmpty, "None");
cls_XCAFDoc_Location.def("Paste", (void (XCAFDoc_Location::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Location::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Location.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Location::get_type_name, "None");
cls_XCAFDoc_Location.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Location::get_type_descriptor, "None");
cls_XCAFDoc_Location.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Location::*)() const) &XCAFDoc_Location::DynamicType, "None");

// CLASS: XCAFDOC_MATERIAL
py::class_<XCAFDoc_Material, opencascade::handle<XCAFDoc_Material>, TDF_Attribute> cls_XCAFDoc_Material(mod, "XCAFDoc_Material", "attribute to store material");

// Constructors
cls_XCAFDoc_Material.def(py::init<>());

// Methods
cls_XCAFDoc_Material.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Material::GetID, "None");
cls_XCAFDoc_Material.def_static("Set_", (opencascade::handle<XCAFDoc_Material> (*)(const TDF_Label &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_Material::Set, "None", py::arg("label"), py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_Material.def("Set", (void (XCAFDoc_Material::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_Material::Set, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_Material.def("GetName", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetName, "None");
cls_XCAFDoc_Material.def("GetDescription", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetDescription, "None");
cls_XCAFDoc_Material.def("GetDensity", (Standard_Real (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetDensity, "None");
cls_XCAFDoc_Material.def("GetDensName", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetDensName, "None");
cls_XCAFDoc_Material.def("GetDensValType", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetDensValType, "None");
cls_XCAFDoc_Material.def("ID", (const Standard_GUID & (XCAFDoc_Material::*)() const) &XCAFDoc_Material::ID, "None");
cls_XCAFDoc_Material.def("Restore", (void (XCAFDoc_Material::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Material::Restore, "None", py::arg("With"));
cls_XCAFDoc_Material.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::NewEmpty, "None");
cls_XCAFDoc_Material.def("Paste", (void (XCAFDoc_Material::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Material::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Material.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Material::get_type_name, "None");
cls_XCAFDoc_Material.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Material::get_type_descriptor, "None");
cls_XCAFDoc_Material.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Material::*)() const) &XCAFDoc_Material::DynamicType, "None");

// CLASS: XCAFDOC_MATERIALTOOL
py::class_<XCAFDoc_MaterialTool, opencascade::handle<XCAFDoc_MaterialTool>, TDF_Attribute> cls_XCAFDoc_MaterialTool(mod, "XCAFDoc_MaterialTool", "Provides tools to store and retrieve attributes (materials) of TopoDS_Shape in and from TDocStd_Document A Document is intended to hold different attributes of ONE shape and it's sub-shapes Provide tools for management of Materialss section of document.");

// Constructors
cls_XCAFDoc_MaterialTool.def(py::init<>());

// Methods
cls_XCAFDoc_MaterialTool.def_static("Set_", (opencascade::handle<XCAFDoc_MaterialTool> (*)(const TDF_Label &)) &XCAFDoc_MaterialTool::Set, "Creates (if not exist) MaterialTool.", py::arg("L"));
cls_XCAFDoc_MaterialTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_MaterialTool::GetID, "None");
cls_XCAFDoc_MaterialTool.def("BaseLabel", (TDF_Label (XCAFDoc_MaterialTool::*)() const) &XCAFDoc_MaterialTool::BaseLabel, "returns the label under which colors are stored");
cls_XCAFDoc_MaterialTool.def("ShapeTool", (const opencascade::handle<XCAFDoc_ShapeTool> & (XCAFDoc_MaterialTool::*)()) &XCAFDoc_MaterialTool::ShapeTool, "Returns internal XCAFDoc_ShapeTool tool");
cls_XCAFDoc_MaterialTool.def("IsMaterial", (Standard_Boolean (XCAFDoc_MaterialTool::*)(const TDF_Label &) const) &XCAFDoc_MaterialTool::IsMaterial, "Returns True if label belongs to a material table and is a Material definition", py::arg("lab"));
cls_XCAFDoc_MaterialTool.def("GetMaterialLabels", (void (XCAFDoc_MaterialTool::*)(TDF_LabelSequence &) const) &XCAFDoc_MaterialTool::GetMaterialLabels, "Returns a sequence of materials currently stored in the material table", py::arg("Labels"));
cls_XCAFDoc_MaterialTool.def("AddMaterial", (TDF_Label (XCAFDoc_MaterialTool::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_MaterialTool::AddMaterial, "Adds a Material definition to a table and returns its label", py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_MaterialTool.def("SetMaterial", (void (XCAFDoc_MaterialTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_MaterialTool::SetMaterial, "Sets a link with GUID", py::arg("L"), py::arg("MatL"));
cls_XCAFDoc_MaterialTool.def("SetMaterial", (void (XCAFDoc_MaterialTool::*)(const TDF_Label &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_MaterialTool::SetMaterial, "Sets a link with GUID Adds a Material as necessary", py::arg("L"), py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_MaterialTool.def("GetMaterial", [](XCAFDoc_MaterialTool &self, const TDF_Label & MatL, opencascade::handle<TCollection_HAsciiString> & aName, opencascade::handle<TCollection_HAsciiString> & aDescription, Standard_Real & aDensity, opencascade::handle<TCollection_HAsciiString> & aDensName, opencascade::handle<TCollection_HAsciiString> & aDensValType){ Standard_Boolean rv = self.GetMaterial(MatL, aName, aDescription, aDensity, aDensName, aDensValType); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aDensity); }, "Returns Material assigned to <MatL> Returns False if no such Material is assigned", py::arg("MatL"), py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_MaterialTool.def_static("GetDensityForShape_", (Standard_Real (*)(const TDF_Label &)) &XCAFDoc_MaterialTool::GetDensityForShape, "Find referred material and return density from it if no material --> return 0", py::arg("ShapeL"));
cls_XCAFDoc_MaterialTool.def("ID", (const Standard_GUID & (XCAFDoc_MaterialTool::*)() const) &XCAFDoc_MaterialTool::ID, "None");
cls_XCAFDoc_MaterialTool.def("Restore", (void (XCAFDoc_MaterialTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_MaterialTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_MaterialTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_MaterialTool::*)() const) &XCAFDoc_MaterialTool::NewEmpty, "None");
cls_XCAFDoc_MaterialTool.def("Paste", (void (XCAFDoc_MaterialTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_MaterialTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_MaterialTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_MaterialTool::get_type_name, "None");
cls_XCAFDoc_MaterialTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_MaterialTool::get_type_descriptor, "None");
cls_XCAFDoc_MaterialTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_MaterialTool::*)() const) &XCAFDoc_MaterialTool::DynamicType, "None");

// CLASS: XCAFDOC_NOTE
py::class_<XCAFDoc_Note, opencascade::handle<XCAFDoc_Note>, TDF_Attribute> cls_XCAFDoc_Note(mod, "XCAFDoc_Note", "A base note attribute. Any note contains the name of the user created the note and the creation timestamp.");

// Methods
cls_XCAFDoc_Note.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Note::get_type_name, "None");
cls_XCAFDoc_Note.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Note::get_type_descriptor, "None");
cls_XCAFDoc_Note.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Note::*)() const) &XCAFDoc_Note::DynamicType, "None");
cls_XCAFDoc_Note.def_static("IsMine_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_Note::IsMine, "Checks if the given label represents a note.", py::arg("theLabel"));
cls_XCAFDoc_Note.def_static("Get_", (opencascade::handle<XCAFDoc_Note> (*)(const TDF_Label &)) &XCAFDoc_Note::Get, "Finds a reference attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_Note.def("Set", (void (XCAFDoc_Note::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_Note::Set, "Sets the user name and the timestamp of the note.", py::arg("theUserName"), py::arg("theTimeStamp"));
cls_XCAFDoc_Note.def("UserName", (const TCollection_ExtendedString & (XCAFDoc_Note::*)() const) &XCAFDoc_Note::UserName, "Returns the user name, who created the note.");
cls_XCAFDoc_Note.def("TimeStamp", (const TCollection_ExtendedString & (XCAFDoc_Note::*)() const) &XCAFDoc_Note::TimeStamp, "Returns the timestamp of the note.");
cls_XCAFDoc_Note.def("IsOrphan", (Standard_Boolean (XCAFDoc_Note::*)() const) &XCAFDoc_Note::IsOrphan, "Checks if the note isn't linked to annotated items.");
cls_XCAFDoc_Note.def("GetObject", (opencascade::handle<XCAFNoteObjects_NoteObject> (XCAFDoc_Note::*)() const) &XCAFDoc_Note::GetObject, "Returns auxiliary data object");
cls_XCAFDoc_Note.def("SetObject", (void (XCAFDoc_Note::*)(const opencascade::handle<XCAFNoteObjects_NoteObject> &)) &XCAFDoc_Note::SetObject, "Updates auxiliary data", py::arg("theObject"));
cls_XCAFDoc_Note.def("Restore", (void (XCAFDoc_Note::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Note::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_Note.def("Paste", (void (XCAFDoc_Note::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Note::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_Note.def("Dump", (Standard_OStream & (XCAFDoc_Note::*)(Standard_OStream &) const) &XCAFDoc_Note::Dump, "None", py::arg("theOS"));

// CLASS: XCAFDOC_NOTECOMMENT
py::class_<XCAFDoc_NoteComment, opencascade::handle<XCAFDoc_NoteComment>, XCAFDoc_Note> cls_XCAFDoc_NoteComment(mod, "XCAFDoc_NoteComment", "A comment note attribute. Contains a textual comment.");

// Constructors
cls_XCAFDoc_NoteComment.def(py::init<>());

// Methods
cls_XCAFDoc_NoteComment.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_NoteComment::get_type_name, "None");
cls_XCAFDoc_NoteComment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_NoteComment::get_type_descriptor, "None");
cls_XCAFDoc_NoteComment.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_NoteComment::*)() const) &XCAFDoc_NoteComment::DynamicType, "None");
cls_XCAFDoc_NoteComment.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_NoteComment::GetID, "Returns default attribute GUID");
cls_XCAFDoc_NoteComment.def_static("Get_", (opencascade::handle<XCAFDoc_NoteComment> (*)(const TDF_Label &)) &XCAFDoc_NoteComment::Get, "Finds a reference attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_NoteComment.def_static("Set_", (opencascade::handle<XCAFDoc_NoteComment> (*)(const TDF_Label &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_NoteComment::Set, "Create (if not exist) a comment note on the given label.", py::arg("theLabel"), py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theComment"));
cls_XCAFDoc_NoteComment.def("Set", (void (XCAFDoc_NoteComment::*)(const TCollection_ExtendedString &)) &XCAFDoc_NoteComment::Set, "Sets the comment text.", py::arg("theComment"));
cls_XCAFDoc_NoteComment.def("Comment", (const TCollection_ExtendedString & (XCAFDoc_NoteComment::*)() const) &XCAFDoc_NoteComment::Comment, "Returns the comment text.");
cls_XCAFDoc_NoteComment.def("ID", (const Standard_GUID & (XCAFDoc_NoteComment::*)() const) &XCAFDoc_NoteComment::ID, "None");
cls_XCAFDoc_NoteComment.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_NoteComment::*)() const) &XCAFDoc_NoteComment::NewEmpty, "None");
cls_XCAFDoc_NoteComment.def("Restore", (void (XCAFDoc_NoteComment::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_NoteComment::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_NoteComment.def("Paste", (void (XCAFDoc_NoteComment::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_NoteComment::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_NoteComment.def("Dump", (Standard_OStream & (XCAFDoc_NoteComment::*)(Standard_OStream &) const) &XCAFDoc_NoteComment::Dump, "None", py::arg("theOS"));

// CLASS: XCAFDOC_NOTEBALLOON
py::class_<XCAFDoc_NoteBalloon, opencascade::handle<XCAFDoc_NoteBalloon>, XCAFDoc_NoteComment> cls_XCAFDoc_NoteBalloon(mod, "XCAFDoc_NoteBalloon", "A comment note attribute. Contains a textual comment.");

// Constructors
cls_XCAFDoc_NoteBalloon.def(py::init<>());

// Methods
cls_XCAFDoc_NoteBalloon.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_NoteBalloon::get_type_name, "None");
cls_XCAFDoc_NoteBalloon.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_NoteBalloon::get_type_descriptor, "None");
cls_XCAFDoc_NoteBalloon.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_NoteBalloon::*)() const) &XCAFDoc_NoteBalloon::DynamicType, "None");
cls_XCAFDoc_NoteBalloon.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_NoteBalloon::GetID, "Returns default attribute GUID");
cls_XCAFDoc_NoteBalloon.def_static("Get_", (opencascade::handle<XCAFDoc_NoteBalloon> (*)(const TDF_Label &)) &XCAFDoc_NoteBalloon::Get, "Finds a reference attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_NoteBalloon.def_static("Set_", (opencascade::handle<XCAFDoc_NoteBalloon> (*)(const TDF_Label &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_NoteBalloon::Set, "Create (if not exist) a comment note on the given label.", py::arg("theLabel"), py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theComment"));
cls_XCAFDoc_NoteBalloon.def("ID", (const Standard_GUID & (XCAFDoc_NoteBalloon::*)() const) &XCAFDoc_NoteBalloon::ID, "None");
cls_XCAFDoc_NoteBalloon.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_NoteBalloon::*)() const) &XCAFDoc_NoteBalloon::NewEmpty, "None");

// CLASS: XCAFDOC_NOTEBINDATA
py::class_<XCAFDoc_NoteBinData, opencascade::handle<XCAFDoc_NoteBinData>, XCAFDoc_Note> cls_XCAFDoc_NoteBinData(mod, "XCAFDoc_NoteBinData", "None");

// Constructors
cls_XCAFDoc_NoteBinData.def(py::init<>());

// Methods
cls_XCAFDoc_NoteBinData.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_NoteBinData::get_type_name, "None");
cls_XCAFDoc_NoteBinData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_NoteBinData::get_type_descriptor, "None");
cls_XCAFDoc_NoteBinData.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::DynamicType, "None");
cls_XCAFDoc_NoteBinData.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_NoteBinData::GetID, "Returns default attribute GUID");
cls_XCAFDoc_NoteBinData.def_static("Get_", (opencascade::handle<XCAFDoc_NoteBinData> (*)(const TDF_Label &)) &XCAFDoc_NoteBinData::Get, "Finds a binary data attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_NoteBinData.def_static("Set_", (opencascade::handle<XCAFDoc_NoteBinData> (*)(const TDF_Label &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, OSD_File &)) &XCAFDoc_NoteBinData::Set, "Create (if not exist) a binary note with data loaded from a binary file.", py::arg("theLabel"), py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theFile"));
cls_XCAFDoc_NoteBinData.def_static("Set_", (opencascade::handle<XCAFDoc_NoteBinData> (*)(const TDF_Label &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const opencascade::handle<TColStd_HArray1OfByte> &)) &XCAFDoc_NoteBinData::Set, "Create (if not exist) a binary note byte data array.", py::arg("theLabel"), py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theData"));
cls_XCAFDoc_NoteBinData.def("Set", (Standard_Boolean (XCAFDoc_NoteBinData::*)(const TCollection_ExtendedString &, const TCollection_AsciiString &, OSD_File &)) &XCAFDoc_NoteBinData::Set, "Sets title, MIME type and data from a binary file.", py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theFile"));
cls_XCAFDoc_NoteBinData.def("Set", (void (XCAFDoc_NoteBinData::*)(const TCollection_ExtendedString &, const TCollection_AsciiString &, const opencascade::handle<TColStd_HArray1OfByte> &)) &XCAFDoc_NoteBinData::Set, "Sets title, MIME type and data from a byte array.", py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theData"));
cls_XCAFDoc_NoteBinData.def("Title", (const TCollection_ExtendedString & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::Title, "Returns the note title.");
cls_XCAFDoc_NoteBinData.def("MIMEtype", (const TCollection_AsciiString & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::MIMEtype, "Returns data MIME type.");
cls_XCAFDoc_NoteBinData.def("Size", (Standard_Integer (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::Size, "Size of data in bytes.");
cls_XCAFDoc_NoteBinData.def("Data", (const opencascade::handle<TColStd_HArray1OfByte> & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::Data, "Returns byte data array.");
cls_XCAFDoc_NoteBinData.def("ID", (const Standard_GUID & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::ID, "None");
cls_XCAFDoc_NoteBinData.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::NewEmpty, "None");
cls_XCAFDoc_NoteBinData.def("Restore", (void (XCAFDoc_NoteBinData::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_NoteBinData::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_NoteBinData.def("Paste", (void (XCAFDoc_NoteBinData::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_NoteBinData::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_NoteBinData.def("Dump", (Standard_OStream & (XCAFDoc_NoteBinData::*)(Standard_OStream &) const) &XCAFDoc_NoteBinData::Dump, "None", py::arg("theOS"));

// CLASS: XCAFDOC_NOTESTOOL
py::class_<XCAFDoc_NotesTool, opencascade::handle<XCAFDoc_NotesTool>, TDF_Attribute> cls_XCAFDoc_NotesTool(mod, "XCAFDoc_NotesTool", "A tool to annotate items in the hierarchical product structure. There are two basic entities, which operates the notes tool: notes and annotated items. A note is a user defined data structure derived from the notes hive. An annotated item is represented by attribute attached to a separate label under the annotated items hive. Notes are linked with annotated items by means of attribute. Notes play parent roles and annotated items - child roles.");

// Constructors
cls_XCAFDoc_NotesTool.def(py::init<>());

// Methods
cls_XCAFDoc_NotesTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_NotesTool::get_type_name, "None");
cls_XCAFDoc_NotesTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_NotesTool::get_type_descriptor, "None");
cls_XCAFDoc_NotesTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::DynamicType, "None");
cls_XCAFDoc_NotesTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_NotesTool::GetID, "Returns default attribute GUID");
cls_XCAFDoc_NotesTool.def_static("Set_", (opencascade::handle<XCAFDoc_NotesTool> (*)(const TDF_Label &)) &XCAFDoc_NotesTool::Set, "Create (if not exist) a notes tool from XCAFDoc on theLabel.", py::arg("theLabel"));
cls_XCAFDoc_NotesTool.def("GetNotesLabel", (TDF_Label (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::GetNotesLabel, "Returns the label of the notes hive.");
cls_XCAFDoc_NotesTool.def("GetAnnotatedItemsLabel", (TDF_Label (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::GetAnnotatedItemsLabel, "Returns the label of the annotated items hive.");
cls_XCAFDoc_NotesTool.def("NbNotes", (Standard_Integer (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::NbNotes, "Returns the number of labels in the notes hive.");
cls_XCAFDoc_NotesTool.def("NbAnnotatedItems", (Standard_Integer (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::NbAnnotatedItems, "Returns the number of labels in the annotated items hive.");
cls_XCAFDoc_NotesTool.def("GetNotes", (void (XCAFDoc_NotesTool::*)(TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetNotes, "Returns all labels from the notes hive. The label sequence isn't cleared beforehand.", py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetAnnotatedItems", (void (XCAFDoc_NotesTool::*)(TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetAnnotatedItems, "Returns all labels from the annotated items hive. The label sequence isn't cleared beforehand.", py::arg("theLabels"));
cls_XCAFDoc_NotesTool.def("IsAnnotatedItem", (Standard_Boolean (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_NotesTool::IsAnnotatedItem, "Checks if the given assembly item is annotated.", py::arg("theItemId"));
cls_XCAFDoc_NotesTool.def("IsAnnotatedItem", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &) const) &XCAFDoc_NotesTool::IsAnnotatedItem, "Checks if the given labeled item is annotated.", py::arg("theItemLabel"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItem", (TDF_Label (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_NotesTool::FindAnnotatedItem, "Finds a label of the given assembly item ID in the annotated items hive.", py::arg("theItemId"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItem", (TDF_Label (XCAFDoc_NotesTool::*)(const TDF_Label &) const) &XCAFDoc_NotesTool::FindAnnotatedItem, "Finds a label of the given labeled item in the annotated items hive.", py::arg("theItemLabel"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItemAttr", (TDF_Label (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, const Standard_GUID &) const) &XCAFDoc_NotesTool::FindAnnotatedItemAttr, "Finds a label of the given assembly item's attribute in the annotated items hive.", py::arg("theItemId"), py::arg("theGUID"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItemAttr", (TDF_Label (XCAFDoc_NotesTool::*)(const TDF_Label &, const Standard_GUID &) const) &XCAFDoc_NotesTool::FindAnnotatedItemAttr, "Finds a label of the given labeled item's attribute in the annotated items hive.", py::arg("theItemLabel"), py::arg("theGUID"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItemSubshape", (TDF_Label (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, Standard_Integer) const) &XCAFDoc_NotesTool::FindAnnotatedItemSubshape, "Finds a label of the given assembly item's subshape in the annotated items hive.", py::arg("theItemId"), py::arg("theSubshapeIndex"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItemSubshape", (TDF_Label (XCAFDoc_NotesTool::*)(const TDF_Label &, Standard_Integer) const) &XCAFDoc_NotesTool::FindAnnotatedItemSubshape, "Finds a label of the given labeled item's subshape in the annotated items hive.", py::arg("theItemLabel"), py::arg("theSubshapeIndex"));
cls_XCAFDoc_NotesTool.def("CreateComment", (opencascade::handle<XCAFDoc_Note> (XCAFDoc_NotesTool::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_NotesTool::CreateComment, "Create a new comment note. Creates a new label under the notes hive and attaches attribute (derived ftom", py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theComment"));
cls_XCAFDoc_NotesTool.def("CreateBalloon", (opencascade::handle<XCAFDoc_Note> (XCAFDoc_NotesTool::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_NotesTool::CreateBalloon, "Create a new 'balloon' note. Creates a new label under the notes hive and attaches attribute (derived ftom", py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theComment"));
cls_XCAFDoc_NotesTool.def("CreateBinData", (opencascade::handle<XCAFDoc_Note> (XCAFDoc_NotesTool::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, OSD_File &)) &XCAFDoc_NotesTool::CreateBinData, "Create a new note with data loaded from a binary file. Creates a new label under the notes hive and attaches attribute (derived ftom", py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theFile"));
cls_XCAFDoc_NotesTool.def("CreateBinData", (opencascade::handle<XCAFDoc_Note> (XCAFDoc_NotesTool::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const opencascade::handle<TColStd_HArray1OfByte> &)) &XCAFDoc_NotesTool::CreateBinData, "Create a new note with data loaded from a byte data array. Creates a new label under the notes hive and attaches attribute (derived ftom", py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theData"));
cls_XCAFDoc_NotesTool.def("GetNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetNotes, "Gets all note labels of the assembly item. Notes linked to item's subshapes or attributes aren't taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemId"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetNotes, "Gets all note labels of the labeled item. Notes linked to item's attributes aren't taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemLabel"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetAttrNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, const Standard_GUID &, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetAttrNotes, "Gets all note labels of the assembly item's attribute. Notes linked to the item itself or to item's subshapes aren't taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemId"), py::arg("theGUID"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetAttrNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const TDF_Label &, const Standard_GUID &, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetAttrNotes, "Gets all note labels of the labeled item's attribute. Notes linked to the item itself or to item's subshapes aren't taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemLabel"), py::arg("theGUID"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetSubshapeNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, Standard_Integer, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetSubshapeNotes, "Gets all note labels of the annotated item. Notes linked to the item itself or to item's attributes taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemId"), py::arg("theSubshapeIndex"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("AddNote", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &)) &XCAFDoc_NotesTool::AddNote, "Adds the given note to the assembly item.", py::arg("theNoteLabel"), py::arg("theItemId"));
cls_XCAFDoc_NotesTool.def("AddNote", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &)) &XCAFDoc_NotesTool::AddNote, "Adds the given note to the labeled item.", py::arg("theNoteLabel"), py::arg("theItemLabel"));
cls_XCAFDoc_NotesTool.def("AddNoteToAttr", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, const Standard_GUID &)) &XCAFDoc_NotesTool::AddNoteToAttr, "Adds the given note to the assembly item's attribute.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theGUID"));
cls_XCAFDoc_NotesTool.def("AddNoteToAttr", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, const Standard_GUID &)) &XCAFDoc_NotesTool::AddNoteToAttr, "Adds the given note to the labeled item's attribute.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theGUID"));
cls_XCAFDoc_NotesTool.def("AddNoteToSubshape", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, Standard_Integer)) &XCAFDoc_NotesTool::AddNoteToSubshape, "Adds the given note to the assembly item's subshape.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theSubshapeIndex"));
cls_XCAFDoc_NotesTool.def("AddNoteToSubshape", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, Standard_Integer)) &XCAFDoc_NotesTool::AddNoteToSubshape, "Adds the given note to the labeled item's subshape.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theSubshapeIndex"));
cls_XCAFDoc_NotesTool.def("RemoveNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const XCAFDoc_AssemblyItemId & a1) -> Standard_Boolean { return self.RemoveNote(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveNote, "Removes the given note from the assembly item.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const TDF_Label & a1) -> Standard_Boolean { return self.RemoveNote(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveNote, "Removes the given note from the labeled item.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveSubshapeNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const XCAFDoc_AssemblyItemId & a1, Standard_Integer a2) -> Standard_Boolean { return self.RemoveSubshapeNote(a0, a1, a2); });
cls_XCAFDoc_NotesTool.def("RemoveSubshapeNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, Standard_Integer, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveSubshapeNote, "Removes the given note from the assembly item's subshape.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theSubshapeIndex"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveSubshapeNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const TDF_Label & a1, Standard_Integer a2) -> Standard_Boolean { return self.RemoveSubshapeNote(a0, a1, a2); });
cls_XCAFDoc_NotesTool.def("RemoveSubshapeNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, Standard_Integer, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveSubshapeNote, "Removes the given note from the labeled item's subshape.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theSubshapeIndex"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAttrNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const XCAFDoc_AssemblyItemId & a1, const Standard_GUID & a2) -> Standard_Boolean { return self.RemoveAttrNote(a0, a1, a2); });
cls_XCAFDoc_NotesTool.def("RemoveAttrNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, const Standard_GUID &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAttrNote, "Removes a note from the assembly item's attribute.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theGUID"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAttrNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const TDF_Label & a1, const Standard_GUID & a2) -> Standard_Boolean { return self.RemoveAttrNote(a0, a1, a2); });
cls_XCAFDoc_NotesTool.def("RemoveAttrNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, const Standard_GUID &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAttrNote, "Removes a note from the labeled item's attribute.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theGUID"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllNotes", [](XCAFDoc_NotesTool &self, const XCAFDoc_AssemblyItemId & a0) -> Standard_Boolean { return self.RemoveAllNotes(a0); });
cls_XCAFDoc_NotesTool.def("RemoveAllNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllNotes, "Removes all notes from the assembly item.", py::arg("theItemId"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllNotes", [](XCAFDoc_NotesTool &self, const TDF_Label & a0) -> Standard_Boolean { return self.RemoveAllNotes(a0); });
cls_XCAFDoc_NotesTool.def("RemoveAllNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllNotes, "Removes all notes from the labeled item.", py::arg("theItemLabel"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllSubshapeNotes", [](XCAFDoc_NotesTool &self, const XCAFDoc_AssemblyItemId & a0, Standard_Integer a1) -> Standard_Boolean { return self.RemoveAllSubshapeNotes(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveAllSubshapeNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, Standard_Integer, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllSubshapeNotes, "Removes all notes from the assembly item's subshape.", py::arg("theItemId"), py::arg("theSubshapeIndex"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllAttrNotes", [](XCAFDoc_NotesTool &self, const XCAFDoc_AssemblyItemId & a0, const Standard_GUID & a1) -> Standard_Boolean { return self.RemoveAllAttrNotes(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveAllAttrNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, const Standard_GUID &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllAttrNotes, "Removes all notes from the assembly item's attribute.", py::arg("theItemId"), py::arg("theGUID"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllAttrNotes", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const Standard_GUID & a1) -> Standard_Boolean { return self.RemoveAllAttrNotes(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveAllAttrNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const Standard_GUID &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllAttrNotes, "Removes all notes from the labeled item's attribute.", py::arg("theItemLabel"), py::arg("theGUID"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("DeleteNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &)) &XCAFDoc_NotesTool::DeleteNote, "Deletes the given note. Removes all links with items annotated by the note.", py::arg("theNoteLabel"));
cls_XCAFDoc_NotesTool.def("DeleteNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(TDF_LabelSequence &)) &XCAFDoc_NotesTool::DeleteNotes, "Deletes the given notes. Removes all links with items annotated by the notes.", py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("DeleteAllNotes", (Standard_Integer (XCAFDoc_NotesTool::*)()) &XCAFDoc_NotesTool::DeleteAllNotes, "Deletes all notes. Clears all annotations.");
cls_XCAFDoc_NotesTool.def("NbOrphanNotes", (Standard_Integer (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::NbOrphanNotes, "Returns number of notes that aren't linked to annotated items.");
cls_XCAFDoc_NotesTool.def("GetOrphanNotes", (void (XCAFDoc_NotesTool::*)(TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetOrphanNotes, "Returns note labels that aren't linked to annotated items. The label sequence isn't cleared beforehand.", py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("DeleteOrphanNotes", (Standard_Integer (XCAFDoc_NotesTool::*)()) &XCAFDoc_NotesTool::DeleteOrphanNotes, "Deletes all notes that aren't linked to annotated items.");
cls_XCAFDoc_NotesTool.def("ID", (const Standard_GUID & (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::ID, "@}");
cls_XCAFDoc_NotesTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::NewEmpty, "None");
cls_XCAFDoc_NotesTool.def("Restore", (void (XCAFDoc_NotesTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_NotesTool::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_NotesTool.def("Paste", (void (XCAFDoc_NotesTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_NotesTool::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_NotesTool.def("Dump", (Standard_OStream & (XCAFDoc_NotesTool::*)(Standard_OStream &) const) &XCAFDoc_NotesTool::Dump, "None", py::arg("theOS"));

// TYPEDEF: XCAFDOC_PARTID
py::class_<TCollection_AsciiString> cls_XCAFDoc_PartId(mod, "XCAFDoc_PartId", "Class defines a variable-length sequence of 8-bit characters. Despite class name (kept for historical reasons), it is intended to store UTF-8 string, not just ASCII characters. However, multi-byte nature of UTF-8 is not considered by the following methods: - Method ::Length() return the number of bytes, not the number of Unicode symbols. - Methods taking/returning symbol index work with 8-bit code units, not true Unicode symbols, including ::Remove(), ::SetValue(), ::Value(), ::Search(), ::Trunc() and others. If application needs to process multi-byte Unicode symbols explicitly, NCollection_Utf8Iter class can be used for iterating through Unicode string (UTF-32 code unit will be returned for each position).", py::module_local());

// Constructors
cls_XCAFDoc_PartId.def(py::init<>());
cls_XCAFDoc_PartId.def(py::init<const Standard_CString>(), py::arg("message"));
cls_XCAFDoc_PartId.def(py::init<const Standard_CString, const Standard_Integer>(), py::arg("message"), py::arg("aLen"));
cls_XCAFDoc_PartId.def(py::init<const Standard_Character>(), py::arg("aChar"));
cls_XCAFDoc_PartId.def(py::init<const Standard_Integer, const Standard_Character>(), py::arg("length"), py::arg("filler"));
cls_XCAFDoc_PartId.def(py::init<const Standard_Integer>(), py::arg("value"));
cls_XCAFDoc_PartId.def(py::init<const Standard_Real>(), py::arg("value"));
cls_XCAFDoc_PartId.def(py::init<const TCollection_AsciiString &>(), py::arg("astring"));
// cls_XCAFDoc_PartId.def(py::init<TCollection_AsciiString &&>(), py::arg("theOther"));
cls_XCAFDoc_PartId.def(py::init<const TCollection_AsciiString &, const Standard_Character>(), py::arg("astring"), py::arg("message"));
cls_XCAFDoc_PartId.def(py::init<const TCollection_AsciiString &, const Standard_CString>(), py::arg("astring"), py::arg("message"));
cls_XCAFDoc_PartId.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("astring"), py::arg("message"));
cls_XCAFDoc_PartId.def(py::init<const TCollection_ExtendedString &>(), py::arg("astring"));
cls_XCAFDoc_PartId.def(py::init<const TCollection_ExtendedString &, const Standard_Character>(), py::arg("astring"), py::arg("replaceNonAscii"));
cls_XCAFDoc_PartId.def(py::init<const Standard_WideChar *>(), py::arg("theStringUtf"));

// Methods
// cls_XCAFDoc_PartId.def_static("operator new_", (void * (*)(size_t)) &TCollection_AsciiString::operator new, "None", py::arg("theSize"));
// cls_XCAFDoc_PartId.def_static("operator delete_", (void (*)(void *)) &TCollection_AsciiString::operator delete, "None", py::arg("theAddress"));
// cls_XCAFDoc_PartId.def_static("operator new[]_", (void * (*)(size_t)) &TCollection_AsciiString::operator new[], "None", py::arg("theSize"));
// cls_XCAFDoc_PartId.def_static("operator delete[]_", (void (*)(void *)) &TCollection_AsciiString::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFDoc_PartId.def_static("operator new_", (void * (*)(size_t, void *)) &TCollection_AsciiString::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFDoc_PartId.def_static("operator delete_", (void (*)(void *, void *)) &TCollection_AsciiString::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFDoc_PartId.def("AssignCat", (void (TCollection_AsciiString::*)(const Standard_Character)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator.", py::arg("other"));
cls_XCAFDoc_PartId.def("__iadd__", (void (TCollection_AsciiString::*)(const Standard_Character)) &TCollection_AsciiString::operator+=, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("AssignCat", (void (TCollection_AsciiString::*)(const Standard_Integer)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator.", py::arg("other"));
cls_XCAFDoc_PartId.def("__iadd__", (void (TCollection_AsciiString::*)(const Standard_Integer)) &TCollection_AsciiString::operator+=, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("AssignCat", (void (TCollection_AsciiString::*)(const Standard_Real)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator.", py::arg("other"));
cls_XCAFDoc_PartId.def("__iadd__", (void (TCollection_AsciiString::*)(const Standard_Real)) &TCollection_AsciiString::operator+=, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("AssignCat", (void (TCollection_AsciiString::*)(const Standard_CString)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator. ex: aString += 'Dummy' To catenate more than one CString, you must put a AsciiString before. Example: aString += 'Hello ' + 'Dolly' IS NOT VALID ! But astring += anotherString + 'Hello ' + 'Dolly' is valid.", py::arg("other"));
cls_XCAFDoc_PartId.def("__iadd__", (void (TCollection_AsciiString::*)(const Standard_CString)) &TCollection_AsciiString::operator+=, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("AssignCat", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator. Example: aString += anotherString", py::arg("other"));
cls_XCAFDoc_PartId.def("__iadd__", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::operator+=, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("Capitalize", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::Capitalize, "Converts the first character into its corresponding upper-case character and the other characters into lowercase Example: before me = 'hellO ' after me = 'Hello '");
cls_XCAFDoc_PartId.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Character) const) &TCollection_AsciiString::Cat, "Appends <other> to me. Syntax: aString = aString + 'Dummy' Example: aString contains 'I say ' aString = aString + 'Hello ' + 'Dolly' gives 'I say Hello Dolly' To catenate more than one CString, you must put a String before. So the following example is WRONG ! aString = 'Hello ' + 'Dolly' THIS IS NOT ALLOWED This rule is applicable to AssignCat (operator +=) too.", py::arg("other"));
cls_XCAFDoc_PartId.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Character) const) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Integer) const) &TCollection_AsciiString::Cat, "Appends <other> to me. Syntax: aString = aString + 15; Example: aString contains 'I say ' gives 'I say 15' To catenate more than one CString, you must put a String before. So the following example is WRONG ! aString = 'Hello ' + 'Dolly' THIS IS NOT ALLOWED This rule is applicable to AssignCat (operator +=) too.", py::arg("other"));
cls_XCAFDoc_PartId.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Integer) const) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Real) const) &TCollection_AsciiString::Cat, "Appends <other> to me. Syntax: aString = aString + 15.15; Example: aString contains 'I say ' gives 'I say 15.15' To catenate more than one CString, you must put a String before. So the following example is WRONG ! aString = 'Hello ' + 'Dolly' THIS IS NOT ALLOWED This rule is applicable to AssignCat (operator +=) too.", py::arg("other"));
cls_XCAFDoc_PartId.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Real) const) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::Cat, "Appends <other> to me. Syntax: aString = aString + 'Dummy' Example: aString contains 'I say ' aString = aString + 'Hello ' + 'Dolly' gives 'I say Hello Dolly' To catenate more than one CString, you must put a String before. So the following example is WRONG ! aString = 'Hello ' + 'Dolly' THIS IS NOT ALLOWED This rule is applicable to AssignCat (operator +=) too.", py::arg("other"));
cls_XCAFDoc_PartId.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::Cat, "Appends <other> to me. Example: aString = aString + anotherString", py::arg("other"));
cls_XCAFDoc_PartId.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("Center", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::Center, "Modifies this ASCII string so that its length becomes equal to Width and the new characters are equal to Filler. New characters are added both at the beginning and at the end of this string. If Width is less than the length of this ASCII string, nothing happens. Example TCollection_AsciiString myAlphabet('abcdef'); myAlphabet.Center(9,' '); assert ( myAlphabet == ' abcdef ' );", py::arg("Width"), py::arg("Filler"));
cls_XCAFDoc_PartId.def("ChangeAll", [](TCollection_AsciiString &self, const Standard_Character a0, const Standard_Character a1) -> void { return self.ChangeAll(a0, a1); });
cls_XCAFDoc_PartId.def("ChangeAll", (void (TCollection_AsciiString::*)(const Standard_Character, const Standard_Character, const Standard_Boolean)) &TCollection_AsciiString::ChangeAll, "Substitutes all the characters equal to aChar by NewChar in the AsciiString <me>. The substitution can be case sensitive. If you don't use default case sensitive, no matter wether aChar is uppercase or not. Example: me = 'Histake' -> ChangeAll('H','M',Standard_True) gives me = 'Mistake'", py::arg("aChar"), py::arg("NewChar"), py::arg("CaseSensitive"));
cls_XCAFDoc_PartId.def("Clear", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::Clear, "Removes all characters contained in <me>. This produces an empty AsciiString.");
cls_XCAFDoc_PartId.def("Copy", (void (TCollection_AsciiString::*)(const Standard_CString)) &TCollection_AsciiString::Copy, "Copy <fromwhere> to <me>. Used as operator = Example: aString = anotherCString;", py::arg("fromwhere"));
// cls_XCAFDoc_PartId.def("operator=", (void (TCollection_AsciiString::*)(const Standard_CString)) &TCollection_AsciiString::operator=, "None", py::arg("fromwhere"));
cls_XCAFDoc_PartId.def("Copy", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::Copy, "Copy <fromwhere> to <me>. Used as operator = Example: aString = anotherString;", py::arg("fromwhere"));
// cls_XCAFDoc_PartId.def("operator=", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::operator=, "None", py::arg("fromwhere"));
cls_XCAFDoc_PartId.def("Swap", (void (TCollection_AsciiString::*)(TCollection_AsciiString &)) &TCollection_AsciiString::Swap, "Exchange the data of two strings (without reallocating memory).", py::arg("theOther"));
// cls_XCAFDoc_PartId.def("operator=", (TCollection_AsciiString & (TCollection_AsciiString::*)(TCollection_AsciiString &&)) &TCollection_AsciiString::operator=, "Move assignment operator", py::arg("theOther"));
cls_XCAFDoc_PartId.def("FirstLocationInSet", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &, const Standard_Integer, const Standard_Integer) const) &TCollection_AsciiString::FirstLocationInSet, "Returns the index of the first character of <me> that is present in <Set>. The search begins to the index FromIndex and ends to the the index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAcAa', S = 'Aa', FromIndex = 1, Toindex = 7 after me = 'aabAcAa' returns 1", py::arg("Set"), py::arg("FromIndex"), py::arg("ToIndex"));
cls_XCAFDoc_PartId.def("FirstLocationNotInSet", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &, const Standard_Integer, const Standard_Integer) const) &TCollection_AsciiString::FirstLocationNotInSet, "Returns the index of the first character of <me> that is not present in the set <Set>. The search begins to the index FromIndex and ends to the the index ToIndex in <me>. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAcAa', S = 'Aa', FromIndex = 1, Toindex = 7 after me = 'aabAcAa' returns 3", py::arg("Set"), py::arg("FromIndex"), py::arg("ToIndex"));
cls_XCAFDoc_PartId.def("Insert", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::Insert, "Inserts a Character at position <where>. Example: aString contains 'hy not ?' aString.Insert(1,'W'); gives 'Why not ?' aString contains 'Wh' aString.Insert(3,'y'); gives 'Why' aString contains 'Way' aString.Insert(2,'h'); gives 'Why'", py::arg("where"), py::arg("what"));
cls_XCAFDoc_PartId.def("Insert", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_CString)) &TCollection_AsciiString::Insert, "Inserts a CString at position <where>. Example: aString contains 'O more' aString.Insert(2,'nce'); gives 'Once more'", py::arg("where"), py::arg("what"));
cls_XCAFDoc_PartId.def("Insert", (void (TCollection_AsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TCollection_AsciiString::Insert, "Inserts a AsciiString at position <where>.", py::arg("where"), py::arg("what"));
cls_XCAFDoc_PartId.def("InsertAfter", (void (TCollection_AsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TCollection_AsciiString::InsertAfter, "Pushing a string after a specific index in the string <me>. Raises an exception if Index is out of bounds. - less than 0 (InsertAfter), or less than 1 (InsertBefore), or - greater than the number of characters in this ASCII string. Example: before me = 'cde' , Index = 0 , other = 'ab' after me = 'abcde' , other = 'ab'", py::arg("Index"), py::arg("other"));
cls_XCAFDoc_PartId.def("InsertBefore", (void (TCollection_AsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TCollection_AsciiString::InsertBefore, "Pushing a string before a specific index in the string <me>. Raises an exception if Index is out of bounds. - less than 0 (InsertAfter), or less than 1 (InsertBefore), or - greater than the number of characters in this ASCII string. Example: before me = 'cde' , Index = 1 , other = 'ab' after me = 'abcde' , other = 'ab'", py::arg("Index"), py::arg("other"));
cls_XCAFDoc_PartId.def("IsEmpty", (Standard_Boolean (TCollection_AsciiString::*)() const) &TCollection_AsciiString::IsEmpty, "Returns True if the string <me> contains zero character.");
cls_XCAFDoc_PartId.def("IsEqual", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::IsEqual, "Returns true if the characters in this ASCII string are identical to the characters in ASCII string other. Note that this method is an alias of operator ==.", py::arg("other"));
cls_XCAFDoc_PartId.def("__eq__", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::operator==, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("IsEqual", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::IsEqual, "Returns true if the characters in this ASCII string are identical to the characters in ASCII string other. Note that this method is an alias of operator ==.", py::arg("other"));
cls_XCAFDoc_PartId.def("__eq__", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::operator==, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("IsDifferent", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::IsDifferent, "Returns true if there are differences between the characters in this ASCII string and ASCII string other. Note that this method is an alias of operator !=", py::arg("other"));
cls_XCAFDoc_PartId.def("__ne__", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::operator!=, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("IsDifferent", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::IsDifferent, "Returns true if there are differences between the characters in this ASCII string and ASCII string other. Note that this method is an alias of operator !=", py::arg("other"));
cls_XCAFDoc_PartId.def("__ne__", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::operator!=, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("IsLess", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::IsLess, "Returns TRUE if <me> is 'ASCII' less than <other>.", py::arg("other"));
cls_XCAFDoc_PartId.def("__lt__", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::operator<, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("IsLess", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::IsLess, "Returns TRUE if <me> is 'ASCII' less than <other>.", py::arg("other"));
cls_XCAFDoc_PartId.def("__lt__", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::operator<, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("IsGreater", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::IsGreater, "Returns TRUE if <me> is 'ASCII' greater than <other>.", py::arg("other"));
cls_XCAFDoc_PartId.def("__gt__", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::operator>, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("IsGreater", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::IsGreater, "Returns TRUE if <me> is 'ASCII' greater than <other>.", py::arg("other"));
cls_XCAFDoc_PartId.def("__gt__", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::operator>, py::is_operator(), "None", py::arg("other"));
cls_XCAFDoc_PartId.def("StartsWith", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::StartsWith, "Determines whether the beginning of this string instance matches the specified string.", py::arg("theStartString"));
cls_XCAFDoc_PartId.def("EndsWith", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::EndsWith, "Determines whether the end of this string instance matches the specified string.", py::arg("theEndString"));
cls_XCAFDoc_PartId.def("IntegerValue", (Standard_Integer (TCollection_AsciiString::*)() const) &TCollection_AsciiString::IntegerValue, "Converts a AsciiString containing a numeric expression to an Integer. Example: '215' returns 215.");
cls_XCAFDoc_PartId.def("IsIntegerValue", (Standard_Boolean (TCollection_AsciiString::*)() const) &TCollection_AsciiString::IsIntegerValue, "Returns True if the AsciiString contains an integer value. Note: an integer value is considered to be a real value as well.");
cls_XCAFDoc_PartId.def("IsRealValue", (Standard_Boolean (TCollection_AsciiString::*)() const) &TCollection_AsciiString::IsRealValue, "Returns True if the AsciiString contains a real value. Note: an integer value is considered to be a real value as well.");
cls_XCAFDoc_PartId.def("IsAscii", (Standard_Boolean (TCollection_AsciiString::*)() const) &TCollection_AsciiString::IsAscii, "Returns True if the AsciiString contains only ASCII characters between ' ' and '~'. This means no control character and no extended ASCII code.");
cls_XCAFDoc_PartId.def("LeftAdjust", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::LeftAdjust, "Removes all space characters in the begining of the string.");
cls_XCAFDoc_PartId.def("LeftJustify", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::LeftJustify, "left justify Length becomes equal to Width and the new characters are equal to Filler. If Width < Length nothing happens. Raises an exception if Width is less than zero. Example: before me = 'abcdef' , Width = 9 , Filler = ' ' after me = 'abcdef '", py::arg("Width"), py::arg("Filler"));
cls_XCAFDoc_PartId.def("Length", (Standard_Integer (TCollection_AsciiString::*)() const) &TCollection_AsciiString::Length, "Returns number of characters in <me>. This is the same functionality as 'strlen' in C. Example TCollection_AsciiString myAlphabet('abcdef'); assert ( myAlphabet.Length() == 6 ); - 1 is the position of the first character in this string. - The length of this string gives the position of its last character. - Positions less than or equal to zero, or greater than the length of this string are invalid in functions which identify a character of this string by its position.");
cls_XCAFDoc_PartId.def("Location", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &, const Standard_Integer, const Standard_Integer) const) &TCollection_AsciiString::Location, "Returns an index in the string <me> of the first occurence of the string S in the string <me> from the starting index FromIndex to the ending index ToIndex returns zero if failure Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAaAa', S = 'Aa', FromIndex = 1, ToIndex = 7 after me = 'aabAaAa' returns 4", py::arg("other"), py::arg("FromIndex"), py::arg("ToIndex"));
cls_XCAFDoc_PartId.def("Location", (Standard_Integer (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character, const Standard_Integer, const Standard_Integer) const) &TCollection_AsciiString::Location, "Returns the index of the nth occurence of the character C in the string <me> from the starting index FromIndex to the ending index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAa', N = 3, C = 'a', FromIndex = 1, ToIndex = 5 after me = 'aabAa' returns 5", py::arg("N"), py::arg("C"), py::arg("FromIndex"), py::arg("ToIndex"));
cls_XCAFDoc_PartId.def("LowerCase", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::LowerCase, "Converts <me> to its lower-case equivalent. Example TCollection_AsciiString myString('Hello Dolly'); myString.UpperCase(); assert ( myString == 'HELLO DOLLY' ); myString.LowerCase(); assert ( myString == 'hello dolly' );");
cls_XCAFDoc_PartId.def("Prepend", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::Prepend, "Inserts the string other at the beginning of this ASCII string. Example TCollection_AsciiString myAlphabet('cde'); TCollection_AsciiString myBegin('ab'); myAlphabet.Prepend(myBegin); assert ( myAlphabet == 'abcde' );", py::arg("other"));
cls_XCAFDoc_PartId.def("Print", (void (TCollection_AsciiString::*)(Standard_OStream &) const) &TCollection_AsciiString::Print, "Displays <me> on a stream.", py::arg("astream"));
cls_XCAFDoc_PartId.def("Read", (void (TCollection_AsciiString::*)(Standard_IStream &)) &TCollection_AsciiString::Read, "Read <me> from a stream.", py::arg("astream"));
cls_XCAFDoc_PartId.def("RealValue", (Standard_Real (TCollection_AsciiString::*)() const) &TCollection_AsciiString::RealValue, "Converts an AsciiString containing a numeric expression. to a Real. Example: ex: '215' returns 215.0. ex: '3.14159267' returns 3.14159267.");
cls_XCAFDoc_PartId.def("RemoveAll", (void (TCollection_AsciiString::*)(const Standard_Character, const Standard_Boolean)) &TCollection_AsciiString::RemoveAll, "Remove all the occurences of the character C in the string. Example: before me = 'HellLLo', C = 'L' , CaseSensitive = True after me = 'Hello'", py::arg("C"), py::arg("CaseSensitive"));
cls_XCAFDoc_PartId.def("RemoveAll", (void (TCollection_AsciiString::*)(const Standard_Character)) &TCollection_AsciiString::RemoveAll, "Removes every <what> characters from <me>.", py::arg("what"));
cls_XCAFDoc_PartId.def("Remove", [](TCollection_AsciiString &self, const Standard_Integer a0) -> void { return self.Remove(a0); });
cls_XCAFDoc_PartId.def("Remove", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Integer)) &TCollection_AsciiString::Remove, "Erases <ahowmany> characters from position <where>, <where> included. Example: aString contains 'Hello' aString.Remove(2,2) erases 2 characters from position 2 This gives 'Hlo'.", py::arg("where"), py::arg("ahowmany"));
cls_XCAFDoc_PartId.def("RightAdjust", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::RightAdjust, "Removes all space characters at the end of the string.");
cls_XCAFDoc_PartId.def("RightJustify", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::RightJustify, "Right justify. Length becomes equal to Width and the new characters are equal to Filler. if Width < Length nothing happens. Raises an exception if Width is less than zero. Example: before me = 'abcdef' , Width = 9 , Filler = ' ' after me = ' abcdef'", py::arg("Width"), py::arg("Filler"));
cls_XCAFDoc_PartId.def("Search", (Standard_Integer (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::Search, "Searches a CString in <me> from the beginning and returns position of first item <what> matching. it returns -1 if not found. Example: aString contains 'Sample single test' aString.Search('le') returns 5", py::arg("what"));
cls_XCAFDoc_PartId.def("Search", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::Search, "Searches an AsciiString in <me> from the beginning and returns position of first item <what> matching. It returns -1 if not found.", py::arg("what"));
cls_XCAFDoc_PartId.def("SearchFromEnd", (Standard_Integer (TCollection_AsciiString::*)(const Standard_CString) const) &TCollection_AsciiString::SearchFromEnd, "Searches a CString in a AsciiString from the end and returns position of first item <what> matching. It returns -1 if not found. Example: aString contains 'Sample single test' aString.SearchFromEnd('le') returns 12", py::arg("what"));
cls_XCAFDoc_PartId.def("SearchFromEnd", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &) const) &TCollection_AsciiString::SearchFromEnd, "Searches a AsciiString in another AsciiString from the end and returns position of first item <what> matching. It returns -1 if not found.", py::arg("what"));
cls_XCAFDoc_PartId.def("SetValue", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::SetValue, "Replaces one character in the AsciiString at position <where>. If <where> is less than zero or greater than the length of <me> an exception is raised. Example: aString contains 'Garbake' astring.Replace(6,'g') gives <me> = 'Garbage'", py::arg("where"), py::arg("what"));
cls_XCAFDoc_PartId.def("SetValue", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_CString)) &TCollection_AsciiString::SetValue, "Replaces a part of <me> by a CString. If <where> is less than zero or greater than the length of <me> an exception is raised. Example: aString contains 'abcde' aString.SetValue(4,'1234567') gives <me> = 'abc1234567'", py::arg("where"), py::arg("what"));
cls_XCAFDoc_PartId.def("SetValue", (void (TCollection_AsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TCollection_AsciiString::SetValue, "Replaces a part of <me> by another AsciiString.", py::arg("where"), py::arg("what"));
cls_XCAFDoc_PartId.def("Split", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Integer)) &TCollection_AsciiString::Split, "Splits a AsciiString into two sub-strings. Example: aString contains 'abcdefg' aString.Split(3) gives <me> = 'abc' and returns 'defg'", py::arg("where"));
cls_XCAFDoc_PartId.def("SubString", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Integer) const) &TCollection_AsciiString::SubString, "Creation of a sub-string of the string <me>. The sub-string starts to the index Fromindex and ends to the index ToIndex. Raises an exception if ToIndex or FromIndex is out of bounds Example: before me = 'abcdefg', ToIndex=3, FromIndex=6 after me = 'abcdefg' returns 'cdef'", py::arg("FromIndex"), py::arg("ToIndex"));
cls_XCAFDoc_PartId.def("ToCString", (Standard_CString (TCollection_AsciiString::*)() const) &TCollection_AsciiString::ToCString, "Returns pointer to AsciiString (char *). This is useful for some casual manipulations. Warning: Because this 'char *' is 'const', you can't modify its contents.");
cls_XCAFDoc_PartId.def("Token", [](TCollection_AsciiString &self) -> TCollection_AsciiString { return self.Token(); });
cls_XCAFDoc_PartId.def("Token", [](TCollection_AsciiString &self, const Standard_CString a0) -> TCollection_AsciiString { return self.Token(a0); });
cls_XCAFDoc_PartId.def("Token", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_CString, const Standard_Integer) const) &TCollection_AsciiString::Token, "Extracts <whichone> token from <me>. By default, the <separators> is set to space and tabulation. By default, the token extracted is the first one (whichone = 1). <separators> contains all separators you need. If no token indexed by <whichone> is found, it returns empty AsciiString. Example: aString contains 'This is a message' aString.Token() returns 'This' aString.Token(' ',4) returns 'message' aString.Token(' ',2) returns 'is' aString.Token(' ',9) returns '' Other separators than space character and tabulation are allowed : aString contains '1234; test:message , value' aString.Token('; :,',4) returns 'value' aString.Token('; :,',2) returns 'test'", py::arg("separators"), py::arg("whichone"));
cls_XCAFDoc_PartId.def("Trunc", (void (TCollection_AsciiString::*)(const Standard_Integer)) &TCollection_AsciiString::Trunc, "Truncates <me> to <ahowmany> characters. Example: me = 'Hello Dolly' -> Trunc(3) -> me = 'Hel'", py::arg("ahowmany"));
cls_XCAFDoc_PartId.def("UpperCase", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::UpperCase, "Converts <me> to its upper-case equivalent.");
cls_XCAFDoc_PartId.def("UsefullLength", (Standard_Integer (TCollection_AsciiString::*)() const) &TCollection_AsciiString::UsefullLength, "Length of the string ignoring all spaces (' ') and the control character at the end.");
cls_XCAFDoc_PartId.def("Value", (Standard_Character (TCollection_AsciiString::*)(const Standard_Integer) const) &TCollection_AsciiString::Value, "Returns character at position <where> in <me>. If <where> is less than zero or greater than the lenght of <me>, an exception is raised. Example: aString contains 'Hello' aString.Value(2) returns 'e'", py::arg("where"));
cls_XCAFDoc_PartId.def_static("HashCode_", (Standard_Integer (*)(const TCollection_AsciiString &, Standard_Integer)) &TCollection_AsciiString::HashCode, "Computes a hash code for the given ASCII string, in the range [1, theUpperBound]. Returns the same integer value as the hash function for TCollection_ExtendedString", py::arg("theAsciiString"), py::arg("theUpperBound"));
cls_XCAFDoc_PartId.def_static("IsEqual_", (Standard_Boolean (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &TCollection_AsciiString::IsEqual, "Returns True when the two strings are the same. (Just for HashCode for AsciiString)", py::arg("string1"), py::arg("string2"));
cls_XCAFDoc_PartId.def_static("IsEqual_", (Standard_Boolean (*)(const TCollection_AsciiString &, const Standard_CString)) &TCollection_AsciiString::IsEqual, "Returns True when the two strings are the same. (Just for HashCode for AsciiString)", py::arg("string1"), py::arg("string2"));
cls_XCAFDoc_PartId.def_static("IsSameString_", (Standard_Boolean (*)(const TCollection_AsciiString &, const TCollection_AsciiString &, const Standard_Boolean)) &TCollection_AsciiString::IsSameString, "Returns True if the strings contain same characters.", py::arg("theString1"), py::arg("theString2"), py::arg("theIsCaseSensitive"));

// CLASS: XCAFDOC_SHAPEMAPTOOL
py::class_<XCAFDoc_ShapeMapTool, opencascade::handle<XCAFDoc_ShapeMapTool>, TDF_Attribute> cls_XCAFDoc_ShapeMapTool(mod, "XCAFDoc_ShapeMapTool", "attribute containing map of sub shapes");

// Constructors
cls_XCAFDoc_ShapeMapTool.def(py::init<>());

// Methods
cls_XCAFDoc_ShapeMapTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_ShapeMapTool::GetID, "None");
cls_XCAFDoc_ShapeMapTool.def_static("Set_", (opencascade::handle<XCAFDoc_ShapeMapTool> (*)(const TDF_Label &)) &XCAFDoc_ShapeMapTool::Set, "Create (if not exist) ShapeTool from XCAFDoc on <L>.", py::arg("L"));
cls_XCAFDoc_ShapeMapTool.def("IsSubShape", (Standard_Boolean (XCAFDoc_ShapeMapTool::*)(const TopoDS_Shape &) const) &XCAFDoc_ShapeMapTool::IsSubShape, "Checks whether shape is subshape of shape stored on label shapeL", py::arg("sub"));
cls_XCAFDoc_ShapeMapTool.def("SetShape", (void (XCAFDoc_ShapeMapTool::*)(const TopoDS_Shape &)) &XCAFDoc_ShapeMapTool::SetShape, "Sets representation (TopoDS_Shape) for top-level shape", py::arg("S"));
cls_XCAFDoc_ShapeMapTool.def("ID", (const Standard_GUID & (XCAFDoc_ShapeMapTool::*)() const) &XCAFDoc_ShapeMapTool::ID, "None");
cls_XCAFDoc_ShapeMapTool.def("Restore", (void (XCAFDoc_ShapeMapTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_ShapeMapTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_ShapeMapTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_ShapeMapTool::*)() const) &XCAFDoc_ShapeMapTool::NewEmpty, "None");
cls_XCAFDoc_ShapeMapTool.def("Paste", (void (XCAFDoc_ShapeMapTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_ShapeMapTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_ShapeMapTool.def("GetMap", (const TopTools_IndexedMapOfShape & (XCAFDoc_ShapeMapTool::*)() const) &XCAFDoc_ShapeMapTool::GetMap, "None");
cls_XCAFDoc_ShapeMapTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ShapeMapTool::get_type_name, "None");
cls_XCAFDoc_ShapeMapTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ShapeMapTool::get_type_descriptor, "None");
cls_XCAFDoc_ShapeMapTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ShapeMapTool::*)() const) &XCAFDoc_ShapeMapTool::DynamicType, "None");

// CLASS: XCAFDOC_SHAPETOOL
py::class_<XCAFDoc_ShapeTool, opencascade::handle<XCAFDoc_ShapeTool>, TDF_Attribute> cls_XCAFDoc_ShapeTool(mod, "XCAFDoc_ShapeTool", "A tool to store shapes in an XDE document in the form of assembly structure, and to maintain this structure. Attribute containing Shapes section of DECAF document. Provide tools for management of Shapes section. The API provided by this class allows to work with this structure regardless of its low-level implementation. All the shapes are stored on child labels of a main label which is XCAFDoc_DocumentTool::LabelShapes(). The label for assembly also has sub-labels, each of which represents the instance of another shape in that assembly (component). Such sub-label stores reference to the label of the original shape in the form of TDataStd_TreeNode with GUID XCAFDoc::ShapeRefGUID(), and its location encapsulated into the NamedShape. For correct work with an XDE document, it is necessary to use methods for analysis and methods for working with shapes. For example: if ( STool->IsAssembly(aLabel) ) { Standard_Boolean subchilds = Standard_False; (default) Standard_Integer nbc = STool->NbComponents (aLabel[,subchilds]); } If subchilds is True, commands also consider sub-levels. By default, only level one is checked. In this example, number of children from the first level of assembly will be returned. Methods for creation and initialization: Constructor: XCAFDoc_ShapeTool::XCAFDoc_ShapeTool() Getting a guid: Standard_GUID GetID (); Creation (if does not exist) of ShapeTool on label L: Handle(XCAFDoc_ShapeTool) XCAFDoc_ShapeTool::Set(const TDF_Label& L) Analyze whether shape is a simple shape or an instance or a component of an assembly or it is an assembly ( methods of analysis). For example: STool->IsShape(aLabel) ; Analyze that the label represents a shape (simple shape, assembly or reference) or STool->IsTopLevel(aLabel); Analyze that the label is a label of a top-level shape. Work with simple shapes, assemblies and instances ( methods for work with shapes). For example: Add shape: Standard_Boolean makeAssembly; // True to interpret a Compound as an Assembly, False to take it as a whole aLabel = STool->AddShape(aShape, makeAssembly); Get shape: TDF_Label aLabel... // A label must be present if (aLabel.IsNull()) { ... no such label : abandon .. } TopoDS_Shape aShape; aShape = STool->GetShape(aLabel); if (aShape.IsNull()) { ... this label is not for a Shape ... } To get a label from shape. Standard_Boolean findInstance = Standard_False; (this is default value) aLabel = STool->FindShape(aShape [,findInstance]); if (aLabel.IsNull()) { ... no label found for this shape ... }");

// Constructors
cls_XCAFDoc_ShapeTool.def(py::init<>());

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
cls_XCAFDoc_ShapeTool.def("FindShape", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &, TDF_Label &, const Standard_Boolean) const) &XCAFDoc_ShapeTool::FindShape, "Returns the label corresponding to shape S (searches among top-level shapes, not including subcomponents of assemblies and subshapes) If findInstance is False (default), seach for the input shape without location If findInstance is True, searches for the input shape as is. Return True if <S> is found.", py::arg("S"), py::arg("L"), py::arg("findInstance"));
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
cls_XCAFDoc_ShapeTool.def("AddComponent", (TDF_Label (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TDF_Label &, const TopLoc_Location &)) &XCAFDoc_ShapeTool::AddComponent, "Adds a component given by its label and location to the assembly Note: assembly must be IsAssembly() or IsSimpleShape()", py::arg("assembly"), py::arg("comp"), py::arg("Loc"));
cls_XCAFDoc_ShapeTool.def("AddComponent", [](XCAFDoc_ShapeTool &self, const TDF_Label & a0, const TopoDS_Shape & a1) -> TDF_Label { return self.AddComponent(a0, a1); });
cls_XCAFDoc_ShapeTool.def("AddComponent", (TDF_Label (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &, const Standard_Boolean)) &XCAFDoc_ShapeTool::AddComponent, "Adds a shape (located) as a component to the assembly If necessary, creates an additional top-level shape for component and return the Label of component. If expand is True and component is Compound, it will be created as assembly also Note: assembly must be IsAssembly() or IsSimpleShape()", py::arg("assembly"), py::arg("comp"), py::arg("expand"));
cls_XCAFDoc_ShapeTool.def("RemoveComponent", (void (XCAFDoc_ShapeTool::*)(const TDF_Label &) const) &XCAFDoc_ShapeTool::RemoveComponent, "Removes a component from its assembly", py::arg("comp"));
cls_XCAFDoc_ShapeTool.def("UpdateAssemblies", (void (XCAFDoc_ShapeTool::*)()) &XCAFDoc_ShapeTool::UpdateAssemblies, "Top-down update for all assembly compounds stored in the document.");
cls_XCAFDoc_ShapeTool.def("FindSubShape", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &, TDF_Label &) const) &XCAFDoc_ShapeTool::FindSubShape, "Finds a label for subshape of shape stored on label shapeL Returns Null label if it is not found", py::arg("shapeL"), py::arg("sub"), py::arg("L"));
cls_XCAFDoc_ShapeTool.def("AddSubShape", (TDF_Label (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &) const) &XCAFDoc_ShapeTool::AddSubShape, "Adds a label for subshape of shape stored on label shapeL Returns Null label if it is not subshape", py::arg("shapeL"), py::arg("sub"));
cls_XCAFDoc_ShapeTool.def("AddSubShape", (Standard_Boolean (XCAFDoc_ShapeTool::*)(const TDF_Label &, const TopoDS_Shape &, TDF_Label &) const) &XCAFDoc_ShapeTool::AddSubShape, "Adds (of finds already existed) a label for subshape of shape stored on label shapeL. Label addedSubShapeL returns added (found) label or empty in case of wrong subshape. Returns True, if new shape was added, False in case of already existed subshape/wrong subshape", py::arg("shapeL"), py::arg("sub"), py::arg("addedSubShapeL"));
cls_XCAFDoc_ShapeTool.def("FindMainShapeUsingMap", (TDF_Label (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &) const) &XCAFDoc_ShapeTool::FindMainShapeUsingMap, "None", py::arg("sub"));
cls_XCAFDoc_ShapeTool.def("FindMainShape", (TDF_Label (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &) const) &XCAFDoc_ShapeTool::FindMainShape, "Performs a search among top-level shapes to find the shape containing as subshape Checks only simple shapes, and returns the first found label (which should be the only one for valid model)", py::arg("sub"));
cls_XCAFDoc_ShapeTool.def_static("GetSubShapes_", (Standard_Boolean (*)(const TDF_Label &, TDF_LabelSequence &)) &XCAFDoc_ShapeTool::GetSubShapes, "Returns list of labels identifying subshapes of the given shape Returns False if no subshapes are placed on that label", py::arg("L"), py::arg("Labels"));
cls_XCAFDoc_ShapeTool.def("BaseLabel", (TDF_Label (XCAFDoc_ShapeTool::*)() const) &XCAFDoc_ShapeTool::BaseLabel, "returns the label under which shapes are stored");
cls_XCAFDoc_ShapeTool.def("Dump", (Standard_OStream & (XCAFDoc_ShapeTool::*)(Standard_OStream &, const Standard_Boolean) const) &XCAFDoc_ShapeTool::Dump, "None", py::arg("theDumpLog"), py::arg("deep"));
cls_XCAFDoc_ShapeTool.def("Dump", (Standard_OStream & (XCAFDoc_ShapeTool::*)(Standard_OStream &) const) &XCAFDoc_ShapeTool::Dump, "None", py::arg("theDumpLog"));
cls_XCAFDoc_ShapeTool.def_static("DumpShape_", [](Standard_OStream & a0, const TDF_Label & a1) -> void { return XCAFDoc_ShapeTool::DumpShape(a0, a1); });
cls_XCAFDoc_ShapeTool.def_static("DumpShape_", [](Standard_OStream & a0, const TDF_Label & a1, const Standard_Integer a2) -> void { return XCAFDoc_ShapeTool::DumpShape(a0, a1, a2); });
cls_XCAFDoc_ShapeTool.def_static("DumpShape_", (void (*)(Standard_OStream &, const TDF_Label &, const Standard_Integer, const Standard_Boolean)) &XCAFDoc_ShapeTool::DumpShape, "Print to std::ostream <theDumpLog> type of shape found on <L> label and the entry of <L>, with <level> tabs before. If <deep>, print also TShape and Location addresses", py::arg("theDumpLog"), py::arg("L"), py::arg("level"), py::arg("deep"));
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
cls_XCAFDoc_ShapeTool.def("GetNamedProperties", [](XCAFDoc_ShapeTool &self, const TDF_Label & a0) -> opencascade::handle<TDataStd_NamedData> { return self.GetNamedProperties(a0); });
cls_XCAFDoc_ShapeTool.def("GetNamedProperties", (opencascade::handle<TDataStd_NamedData> (XCAFDoc_ShapeTool::*)(const TDF_Label &, const Standard_Boolean) const) &XCAFDoc_ShapeTool::GetNamedProperties, "Method to get NamedData attribute assigned to the given shape label.", py::arg("theLabel"), py::arg("theToCreate"));
cls_XCAFDoc_ShapeTool.def("GetNamedProperties", [](XCAFDoc_ShapeTool &self, const TopoDS_Shape & a0) -> opencascade::handle<TDataStd_NamedData> { return self.GetNamedProperties(a0); });
cls_XCAFDoc_ShapeTool.def("GetNamedProperties", (opencascade::handle<TDataStd_NamedData> (XCAFDoc_ShapeTool::*)(const TopoDS_Shape &, const Standard_Boolean) const) &XCAFDoc_ShapeTool::GetNamedProperties, "Method to get NamedData attribute assigned to a label of the given shape.", py::arg("theShape"), py::arg("theToCreate"));
cls_XCAFDoc_ShapeTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ShapeTool::get_type_name, "None");
cls_XCAFDoc_ShapeTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ShapeTool::get_type_descriptor, "None");
cls_XCAFDoc_ShapeTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ShapeTool::*)() const) &XCAFDoc_ShapeTool::DynamicType, "None");

// CLASS: XCAFDOC_VIEW
py::class_<XCAFDoc_View, opencascade::handle<XCAFDoc_View>, TDF_Attribute> cls_XCAFDoc_View(mod, "XCAFDoc_View", "Attribute to store view");

// Constructors
cls_XCAFDoc_View.def(py::init<>());

// Methods
cls_XCAFDoc_View.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_View::GetID, "None");
cls_XCAFDoc_View.def_static("Set_", (opencascade::handle<XCAFDoc_View> (*)(const TDF_Label &)) &XCAFDoc_View::Set, "None", py::arg("theLabel"));
cls_XCAFDoc_View.def("ID", (const Standard_GUID & (XCAFDoc_View::*)() const) &XCAFDoc_View::ID, "None");
cls_XCAFDoc_View.def("Restore", (void (XCAFDoc_View::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_View::Restore, "None", py::arg("With"));
cls_XCAFDoc_View.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_View::*)() const) &XCAFDoc_View::NewEmpty, "None");
cls_XCAFDoc_View.def("Paste", (void (XCAFDoc_View::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_View::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_View.def("SetObject", (void (XCAFDoc_View::*)(const opencascade::handle<XCAFView_Object> &)) &XCAFDoc_View::SetObject, "Updates parent's label and its sub-labels with data taken from theViewObject. Old data associated with the label will be lost.", py::arg("theViewObject"));
cls_XCAFDoc_View.def("GetObject", (opencascade::handle<XCAFView_Object> (XCAFDoc_View::*)() const) &XCAFDoc_View::GetObject, "Returns view object data taken from the paren's label and its sub-labels.");
cls_XCAFDoc_View.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_View::get_type_name, "None");
cls_XCAFDoc_View.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_View::get_type_descriptor, "None");
cls_XCAFDoc_View.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_View::*)() const) &XCAFDoc_View::DynamicType, "None");

// CLASS: XCAFDOC_VIEWTOOL
py::class_<XCAFDoc_ViewTool, opencascade::handle<XCAFDoc_ViewTool>, TDF_Attribute> cls_XCAFDoc_ViewTool(mod, "XCAFDoc_ViewTool", "Provides tools to store and retrieve Views in and from TDocStd_Document Each View contains parts XCAFDoc_View attribute with all information about camera and view window. Also each view contain information of displayed shapes and GDTs as sets of shape and GDT labels.");

// Constructors
cls_XCAFDoc_ViewTool.def(py::init<>());

// Methods
cls_XCAFDoc_ViewTool.def_static("Set_", (opencascade::handle<XCAFDoc_ViewTool> (*)(const TDF_Label &)) &XCAFDoc_ViewTool::Set, "Creates (if not exist) ViewTool.", py::arg("L"));
cls_XCAFDoc_ViewTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_ViewTool::GetID, "None");
cls_XCAFDoc_ViewTool.def("BaseLabel", (TDF_Label (XCAFDoc_ViewTool::*)() const) &XCAFDoc_ViewTool::BaseLabel, "Returns the label under which Views are stored");
cls_XCAFDoc_ViewTool.def("IsView", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &) const) &XCAFDoc_ViewTool::IsView, "Returns True if label belongs to a View table and is a View definition", py::arg("theLabel"));
cls_XCAFDoc_ViewTool.def("GetViewLabels", (void (XCAFDoc_ViewTool::*)(TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabels, "Returns a sequence of View labels currently stored in the View table", py::arg("theLabels"));
cls_XCAFDoc_ViewTool.def("SetView", (void (XCAFDoc_ViewTool::*)(const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_ViewTool::SetView, "Sets a link with GUID", py::arg("theShapes"), py::arg("theGDTs"), py::arg("theClippingPlanes"), py::arg("theNotes"), py::arg("theAnnotations"), py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("SetView", (void (XCAFDoc_ViewTool::*)(const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_ViewTool::SetView, "Sets a link with GUID", py::arg("theShapes"), py::arg("theGDTs"), py::arg("theClippingPlanes"), py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("SetView", (void (XCAFDoc_ViewTool::*)(const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_ViewTool::SetView, "Sets a link with GUID", py::arg("theShapes"), py::arg("theGDTs"), py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("SetClippingPlanes", (void (XCAFDoc_ViewTool::*)(const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_ViewTool::SetClippingPlanes, "Set Clipping planes to given View", py::arg("theClippingPlaneLabels"), py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("RemoveView", (void (XCAFDoc_ViewTool::*)(const TDF_Label &)) &XCAFDoc_ViewTool::RemoveView, "Remove View", py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForShape", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForShape, "Returns all View labels defined for label ShapeL", py::arg("theShapeL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForGDT", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForGDT, "Returns all View labels defined for label GDTL", py::arg("theGDTL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForClippingPlane", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForClippingPlane, "Returns all View labels defined for label ClippingPlaneL", py::arg("theClippingPlaneL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForNote", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForNote, "Returns all View labels defined for label NoteL", py::arg("theNoteL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForAnnotation", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForAnnotation, "Returns all View labels defined for label AnnotationL", py::arg("theAnnotationL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("AddView", (TDF_Label (XCAFDoc_ViewTool::*)()) &XCAFDoc_ViewTool::AddView, "Adds a view definition to a View table and returns its label");
cls_XCAFDoc_ViewTool.def("GetRefShapeLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefShapeLabel, "Returns shape labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theShapeLabels"));
cls_XCAFDoc_ViewTool.def("GetRefGDTLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefGDTLabel, "Returns GDT labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theGDTLabels"));
cls_XCAFDoc_ViewTool.def("GetRefClippingPlaneLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefClippingPlaneLabel, "Returns ClippingPlane labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theClippingPlaneLabels"));
cls_XCAFDoc_ViewTool.def("GetRefNoteLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefNoteLabel, "Returns Notes labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theNoteLabels"));
cls_XCAFDoc_ViewTool.def("GetRefAnnotationLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefAnnotationLabel, "Returns Annotation labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theAnnotationLabels"));
cls_XCAFDoc_ViewTool.def("IsLocked", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &) const) &XCAFDoc_ViewTool::IsLocked, "Returns true if the given View is marked as locked", py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("Lock", (void (XCAFDoc_ViewTool::*)(const TDF_Label &) const) &XCAFDoc_ViewTool::Lock, "Mark the given View as locked", py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("Unlock", (void (XCAFDoc_ViewTool::*)(const TDF_Label &) const) &XCAFDoc_ViewTool::Unlock, "Unlock the given View", py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("ID", (const Standard_GUID & (XCAFDoc_ViewTool::*)() const) &XCAFDoc_ViewTool::ID, "None");
cls_XCAFDoc_ViewTool.def("Restore", (void (XCAFDoc_ViewTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_ViewTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_ViewTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_ViewTool::*)() const) &XCAFDoc_ViewTool::NewEmpty, "None");
cls_XCAFDoc_ViewTool.def("Paste", (void (XCAFDoc_ViewTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_ViewTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_ViewTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ViewTool::get_type_name, "None");
cls_XCAFDoc_ViewTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ViewTool::get_type_descriptor, "None");
cls_XCAFDoc_ViewTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ViewTool::*)() const) &XCAFDoc_ViewTool::DynamicType, "None");

// CLASS: XCAFDOC_VOLUME
py::class_<XCAFDoc_Volume, opencascade::handle<XCAFDoc_Volume>, TDF_Attribute> cls_XCAFDoc_Volume(mod, "XCAFDoc_Volume", "attribute to store volume");

// Constructors
cls_XCAFDoc_Volume.def(py::init<>());

// Methods
cls_XCAFDoc_Volume.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Volume::GetID, "None");
cls_XCAFDoc_Volume.def("ID", (const Standard_GUID & (XCAFDoc_Volume::*)() const) &XCAFDoc_Volume::ID, "None");
cls_XCAFDoc_Volume.def("Set", (void (XCAFDoc_Volume::*)(const Standard_Real)) &XCAFDoc_Volume::Set, "Sets a value of volume", py::arg("vol"));
cls_XCAFDoc_Volume.def_static("Set_", (opencascade::handle<XCAFDoc_Volume> (*)(const TDF_Label &, const Standard_Real)) &XCAFDoc_Volume::Set, "Find, or create, an Volume attribute and set its value", py::arg("label"), py::arg("vol"));
cls_XCAFDoc_Volume.def("Get", (Standard_Real (XCAFDoc_Volume::*)() const) &XCAFDoc_Volume::Get, "None");
cls_XCAFDoc_Volume.def_static("Get_", [](const TDF_Label & label, Standard_Real & vol){ Standard_Boolean rv = XCAFDoc_Volume::Get(label, vol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, vol); }, "Returns volume as argument returns false if no such attribute at the <label>", py::arg("label"), py::arg("vol"));
cls_XCAFDoc_Volume.def("Restore", (void (XCAFDoc_Volume::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Volume::Restore, "None", py::arg("With"));
cls_XCAFDoc_Volume.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Volume::*)() const) &XCAFDoc_Volume::NewEmpty, "None");
cls_XCAFDoc_Volume.def("Paste", (void (XCAFDoc_Volume::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Volume::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Volume.def("Dump", (Standard_OStream & (XCAFDoc_Volume::*)(Standard_OStream &) const) &XCAFDoc_Volume::Dump, "None", py::arg("anOS"));
cls_XCAFDoc_Volume.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Volume::get_type_name, "None");
cls_XCAFDoc_Volume.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Volume::get_type_descriptor, "None");
cls_XCAFDoc_Volume.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Volume::*)() const) &XCAFDoc_Volume::DynamicType, "None");


}
