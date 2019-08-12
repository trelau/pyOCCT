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
#include <Standard_Handle.hxx>
#include <XCAFDimTolObjects_DimensionObject.hxx>
#include <TCollection_HAsciiString.hxx>
#include <XCAFDimTolObjects_DimensionQualifier.hxx>
#include <Standard_TypeDef.hxx>
#include <XCAFDimTolObjects_DimensionType.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <XCAFDimTolObjects_DimensionFormVariance.hxx>
#include <XCAFDimTolObjects_DimensionGrade.hxx>
#include <XCAFDimTolObjects_DimensionModifiersSequence.hxx>
#include <XCAFDimTolObjects_DimensionModif.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Vector.hxx>

void bind_XCAFDimTolObjects_DimensionObject(py::module &mod){

py::class_<XCAFDimTolObjects_DimensionObject, opencascade::handle<XCAFDimTolObjects_DimensionObject>, Standard_Transient> cls_XCAFDimTolObjects_DimensionObject(mod, "XCAFDimTolObjects_DimensionObject", "Access object to store dimension data");

// Constructors
cls_XCAFDimTolObjects_DimensionObject.def(py::init<>());
cls_XCAFDimTolObjects_DimensionObject.def(py::init<const opencascade::handle<XCAFDimTolObjects_DimensionObject> &>(), py::arg("theObj"));

// Fields

// Methods
cls_XCAFDimTolObjects_DimensionObject.def("GetSemanticName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetSemanticName, "Returns semantic name");
cls_XCAFDimTolObjects_DimensionObject.def("SetSemanticName", (void (XCAFDimTolObjects_DimensionObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DimensionObject::SetSemanticName, "Sets semantic name", py::arg("theName"));
cls_XCAFDimTolObjects_DimensionObject.def("SetQualifier", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionQualifier)) &XCAFDimTolObjects_DimensionObject::SetQualifier, "Sets dimension qualifier as min., max. or average.", py::arg("theQualifier"));
cls_XCAFDimTolObjects_DimensionObject.def("GetQualifier", (XCAFDimTolObjects_DimensionQualifier (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetQualifier, "Returns dimension qualifier.");
cls_XCAFDimTolObjects_DimensionObject.def("HasQualifier", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasQualifier, "Returns True if the object has dimension qualifier.");
cls_XCAFDimTolObjects_DimensionObject.def("SetType", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionType)) &XCAFDimTolObjects_DimensionObject::SetType, "Sets a specific type of dimension.", py::arg("theTyupe"));
cls_XCAFDimTolObjects_DimensionObject.def("GetType", (XCAFDimTolObjects_DimensionType (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetType, "Returns dimension type.");
cls_XCAFDimTolObjects_DimensionObject.def("GetValue", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetValue, "Returns the main dimension value. It will be the middle value in case of range dimension.");
cls_XCAFDimTolObjects_DimensionObject.def("GetValues", (opencascade::handle<TColStd_HArray1OfReal> (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetValues, "Returns raw array of dimension values");
cls_XCAFDimTolObjects_DimensionObject.def("SetValue", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetValue, "Sets the main dimension value. Overwrites previous values.", py::arg("theValue"));
cls_XCAFDimTolObjects_DimensionObject.def("SetValues", (void (XCAFDimTolObjects_DimensionObject::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &XCAFDimTolObjects_DimensionObject::SetValues, "Replaces current raw array of dimension values with theValues array.", py::arg("theValue"));
cls_XCAFDimTolObjects_DimensionObject.def("IsDimWithRange", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::IsDimWithRange, "Returns True if the dimension is of range kind. Dimension is of range kind if its values array contains two elements defining lower and upper bounds.");
cls_XCAFDimTolObjects_DimensionObject.def("SetUpperBound", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetUpperBound, "Sets the upper bound of the range dimension, otherwise resets it to an empty range with the specified upper bound.", py::arg("theUpperBound"));
cls_XCAFDimTolObjects_DimensionObject.def("SetLowerBound", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetLowerBound, "Sets the lower bound of the range dimension, otherwise resets it to an empty range with the specified lower bound.", py::arg("theLowerBound"));
cls_XCAFDimTolObjects_DimensionObject.def("GetUpperBound", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetUpperBound, "Returns the upper bound of the range dimension, otherwise - zero.");
cls_XCAFDimTolObjects_DimensionObject.def("GetLowerBound", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetLowerBound, "Returns the lower bound of the range dimension, otherwise - zero.");
cls_XCAFDimTolObjects_DimensionObject.def("IsDimWithPlusMinusTolerance", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::IsDimWithPlusMinusTolerance, "Returns True if the dimension is of +/- tolerance kind. Dimension is of +/- tolerance kind if its values array contains three elements defining the main value and the lower/upper tolerances.");
cls_XCAFDimTolObjects_DimensionObject.def("SetUpperTolValue", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetUpperTolValue, "Sets the upper value of the toleranced dimension, otherwise resets a simple dimension to toleranced one with the specified lower/upper tolerances. Returns False in case of range dimension.", py::arg("theUperTolValue"));
cls_XCAFDimTolObjects_DimensionObject.def("SetLowerTolValue", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetLowerTolValue, "Sets the lower value of the toleranced dimension, otherwise resets a simple dimension to toleranced one with the specified lower/upper tolerances. Returns False in case of range dimension.", py::arg("theLowerTolValue"));
cls_XCAFDimTolObjects_DimensionObject.def("GetUpperTolValue", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetUpperTolValue, "Returns the lower value of the toleranced dimension, otherwise - zero.");
cls_XCAFDimTolObjects_DimensionObject.def("GetLowerTolValue", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetLowerTolValue, "Returns the upper value of the toleranced dimension, otherwise - zero.");
cls_XCAFDimTolObjects_DimensionObject.def("IsDimWithClassOfTolerance", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::IsDimWithClassOfTolerance, "Returns True if the form variance was set to not XCAFDimTolObjects_DimensionFormVariance_None value.");
cls_XCAFDimTolObjects_DimensionObject.def("SetClassOfTolerance", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Boolean, const XCAFDimTolObjects_DimensionFormVariance, const XCAFDimTolObjects_DimensionGrade)) &XCAFDimTolObjects_DimensionObject::SetClassOfTolerance, "Sets tolerance class of the dimension.", py::arg("theHole"), py::arg("theFormVariance"), py::arg("theGrade"));
cls_XCAFDimTolObjects_DimensionObject.def("GetClassOfTolerance", [](XCAFDimTolObjects_DimensionObject &self, Standard_Boolean & theHole, XCAFDimTolObjects_DimensionFormVariance & theFormVariance, XCAFDimTolObjects_DimensionGrade & theGrade){ Standard_Boolean rv = self.GetClassOfTolerance(theHole, theFormVariance, theGrade); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theHole); }, "Retrieves tolerance class parameters of the dimension. Returns True if the dimension is toleranced.", py::arg("theHole"), py::arg("theFormVariance"), py::arg("theGrade"));
cls_XCAFDimTolObjects_DimensionObject.def("SetNbOfDecimalPlaces", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DimensionObject::SetNbOfDecimalPlaces, "Sets the number of places to the left and right of the decimal point respectively.", py::arg("theL"), py::arg("theR"));
cls_XCAFDimTolObjects_DimensionObject.def("GetNbOfDecimalPlaces", [](XCAFDimTolObjects_DimensionObject &self, Standard_Integer & theL, Standard_Integer & theR){ self.GetNbOfDecimalPlaces(theL, theR); return std::tuple<Standard_Integer &, Standard_Integer &>(theL, theR); }, "Returns the number of places to the left and right of the decimal point respectively.", py::arg("theL"), py::arg("theR"));
cls_XCAFDimTolObjects_DimensionObject.def("GetModifiers", (XCAFDimTolObjects_DimensionModifiersSequence (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetModifiers, "Returns a sequence of modifiers of the dimension.");
cls_XCAFDimTolObjects_DimensionObject.def("SetModifiers", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionObject::SetModifiers, "Sets new sequence of dimension modifiers.", py::arg("theModifiers"));
cls_XCAFDimTolObjects_DimensionObject.def("AddModifier", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionModif)) &XCAFDimTolObjects_DimensionObject::AddModifier, "Adds a modifier to the dimension sequence of modifiers.", py::arg("theModifier"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPath", (TopoDS_Edge (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPath, "Returns a 'curve' along which the dimension is measured.");
cls_XCAFDimTolObjects_DimensionObject.def("SetPath", (void (XCAFDimTolObjects_DimensionObject::*)(const TopoDS_Edge &)) &XCAFDimTolObjects_DimensionObject::SetPath, "Sets a 'curve' along which the dimension is measured.", py::arg("thePath"));
cls_XCAFDimTolObjects_DimensionObject.def("GetDirection", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(gp_Dir &) const) &XCAFDimTolObjects_DimensionObject::GetDirection, "Returns the orientation of the dimension in annotation plane.", py::arg("theDir"));
cls_XCAFDimTolObjects_DimensionObject.def("SetDirection", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(const gp_Dir &)) &XCAFDimTolObjects_DimensionObject::SetDirection, "Sets an orientation of the dimension in annotation plane.", py::arg("theDir"));
cls_XCAFDimTolObjects_DimensionObject.def("SetPointTextAttach", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_DimensionObject::SetPointTextAttach, "Sets position of the dimension text.", py::arg("thePntText"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPointTextAttach", (const gp_Pnt & (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPointTextAttach, "Returns position of the dimension text.");
cls_XCAFDimTolObjects_DimensionObject.def("HasTextPoint", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasTextPoint, "Returns True if the position of dimension text is specified.");
cls_XCAFDimTolObjects_DimensionObject.def("SetPlane", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_DimensionObject::SetPlane, "Sets annotation plane.", py::arg("thePlane"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPlane", (const gp_Ax2 & (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPlane, "Returns annotation plane.");
cls_XCAFDimTolObjects_DimensionObject.def("HasPlane", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasPlane, "Returns True if the object has annotation plane.");
cls_XCAFDimTolObjects_DimensionObject.def("HasPoint", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasPoint, "Returns true, if connection point exists (for dimesional_size), if connection point for the first shape exists (for dimensional_location).");
cls_XCAFDimTolObjects_DimensionObject.def("HasPoint2", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasPoint2, "None");
cls_XCAFDimTolObjects_DimensionObject.def("SetPoint", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Pnt)) &XCAFDimTolObjects_DimensionObject::SetPoint, "Set connection point (for dimesional_size), Set connection point for the first shape (for dimensional_location).", py::arg("thePnt"));
cls_XCAFDimTolObjects_DimensionObject.def("SetPoint2", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Pnt)) &XCAFDimTolObjects_DimensionObject::SetPoint2, "None", py::arg("thePnt"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPoint", (gp_Pnt (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPoint, "Get connection point (for dimesional_size), Get connection point for the first shape (for dimensional_location).");
cls_XCAFDimTolObjects_DimensionObject.def("GetPoint2", (gp_Pnt (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPoint2, "None");
cls_XCAFDimTolObjects_DimensionObject.def("SetPresentation", (void (XCAFDimTolObjects_DimensionObject::*)(const TopoDS_Shape &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DimensionObject::SetPresentation, "Set graphical presentation for the object.", py::arg("thePresentation"), py::arg("thePresentationName"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPresentation", (TopoDS_Shape (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPresentation, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_DimensionObject.def("GetPresentationName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPresentationName, "Returns graphical presentation of the object");
cls_XCAFDimTolObjects_DimensionObject.def("HasDescriptions", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasDescriptions, "Returns true, if the object has descriptions.");
cls_XCAFDimTolObjects_DimensionObject.def("NbDescriptions", (Standard_Integer (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::NbDescriptions, "Returns number of descriptions.");
cls_XCAFDimTolObjects_DimensionObject.def("GetDescription", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer) const) &XCAFDimTolObjects_DimensionObject::GetDescription, "Returns description with the given number.", py::arg("theNumber"));
cls_XCAFDimTolObjects_DimensionObject.def("GetDescriptionName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer) const) &XCAFDimTolObjects_DimensionObject::GetDescriptionName, "Returns name of description with the given number.", py::arg("theNumber"));
cls_XCAFDimTolObjects_DimensionObject.def("RemoveDescription", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer)) &XCAFDimTolObjects_DimensionObject::RemoveDescription, "Remove description with the given number.", py::arg("theNumber"));
cls_XCAFDimTolObjects_DimensionObject.def("AddDescription", (void (XCAFDimTolObjects_DimensionObject::*)(const opencascade::handle<TCollection_HAsciiString>, const opencascade::handle<TCollection_HAsciiString>)) &XCAFDimTolObjects_DimensionObject::AddDescription, "Add new description.", py::arg("theDescription"), py::arg("theName"));
cls_XCAFDimTolObjects_DimensionObject.def_static("get_type_name_", (const char * (*)()) &XCAFDimTolObjects_DimensionObject::get_type_name, "None");
cls_XCAFDimTolObjects_DimensionObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDimTolObjects_DimensionObject::get_type_descriptor, "None");
cls_XCAFDimTolObjects_DimensionObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::DynamicType, "None");

// Enums

}