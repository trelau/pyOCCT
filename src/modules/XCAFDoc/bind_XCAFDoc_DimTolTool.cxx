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
#include <Standard_Handle.hxx>
#include <XCAFDoc_DimTolTool.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelSequence.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TCollection_HAsciiString.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopoDS_Shape.hxx>
#include <TDF_LabelMapHasher.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_DimTolTool(py::module &mod){

py::class_<XCAFDoc_DimTolTool, opencascade::handle<XCAFDoc_DimTolTool>, TDF_Attribute> cls_XCAFDoc_DimTolTool(mod, "XCAFDoc_DimTolTool", "Attribute containing GD&T section of XCAF document. Provide tools for GD&T section management.");

// Constructors
cls_XCAFDoc_DimTolTool.def(py::init<>());

// Fields

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

// Enums

}