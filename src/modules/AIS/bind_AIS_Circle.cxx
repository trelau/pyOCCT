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
#include <AIS_InteractiveObject.hxx>
#include <Standard_Handle.hxx>
#include <AIS_Circle.hxx>
#include <Standard_Type.hxx>
#include <Geom_Circle.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Quantity_Color.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>

void bind_AIS_Circle(py::module &mod){

py::class_<AIS_Circle, opencascade::handle<AIS_Circle>, AIS_InteractiveObject> cls_AIS_Circle(mod, "AIS_Circle", "Constructs circle datums to be used in construction of composite shapes.");

// Constructors
cls_AIS_Circle.def(py::init<const opencascade::handle<Geom_Circle> &>(), py::arg("aCircle"));
cls_AIS_Circle.def(py::init<const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real>(), py::arg("theCircle"), py::arg("theUStart"), py::arg("theUEnd"));
cls_AIS_Circle.def(py::init<const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("theCircle"), py::arg("theUStart"), py::arg("theUEnd"), py::arg("theIsFilledCircleSens"));

// Fields

// Methods
cls_AIS_Circle.def_static("get_type_name_", (const char * (*)()) &AIS_Circle::get_type_name, "None");
cls_AIS_Circle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Circle::get_type_descriptor, "None");
cls_AIS_Circle.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Circle::*)() const) &AIS_Circle::DynamicType, "None");
cls_AIS_Circle.def("Compute", (void (AIS_Circle::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Circle::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Circle.def("Signature", (Standard_Integer (AIS_Circle::*)() const) &AIS_Circle::Signature, "Returns index 6 by default.");
cls_AIS_Circle.def("Type", (AIS_KindOfInteractive (AIS_Circle::*)() const) &AIS_Circle::Type, "Indicates that the type of Interactive Object is a datum.");
cls_AIS_Circle.def("Circle", (const opencascade::handle<Geom_Circle> & (AIS_Circle::*)() const) &AIS_Circle::Circle, "Returns the circle component defined in SetCircle.");
cls_AIS_Circle.def("Parameters", [](AIS_Circle &self, Standard_Real & theU1, Standard_Real & theU2){ self.Parameters(theU1, theU2); return std::tuple<Standard_Real &, Standard_Real &>(theU1, theU2); }, "Constructs instances of the starting point and the end point parameters, theU1 and theU2.", py::arg("theU1"), py::arg("theU2"));
cls_AIS_Circle.def("SetCircle", (void (AIS_Circle::*)(const opencascade::handle<Geom_Circle> &)) &AIS_Circle::SetCircle, "Allows you to provide settings for the circle datum aCircle.", py::arg("theCircle"));
cls_AIS_Circle.def("SetFirstParam", (void (AIS_Circle::*)(const Standard_Real)) &AIS_Circle::SetFirstParam, "Allows you to set the parameter theU for the starting point of an arc.", py::arg("theU"));
cls_AIS_Circle.def("SetLastParam", (void (AIS_Circle::*)(const Standard_Real)) &AIS_Circle::SetLastParam, "Allows you to provide the parameter theU for the end point of an arc.", py::arg("theU"));
cls_AIS_Circle.def("SetColor", (void (AIS_Circle::*)(const Quantity_Color &)) &AIS_Circle::SetColor, "None", py::arg("aColor"));
cls_AIS_Circle.def("SetWidth", (void (AIS_Circle::*)(const Standard_Real)) &AIS_Circle::SetWidth, "Assigns the width aValue to the solid line boundary of the circle datum.", py::arg("aValue"));
cls_AIS_Circle.def("UnsetColor", (void (AIS_Circle::*)()) &AIS_Circle::UnsetColor, "Removes color from the solid line boundary of the circle datum.");
cls_AIS_Circle.def("UnsetWidth", (void (AIS_Circle::*)()) &AIS_Circle::UnsetWidth, "Removes width settings from the solid line boundary of the circle datum.");
cls_AIS_Circle.def("IsFilledCircleSens", (Standard_Boolean (AIS_Circle::*)() const) &AIS_Circle::IsFilledCircleSens, "Returns the type of sensitivity for the circle;");
cls_AIS_Circle.def("SetFilledCircleSens", (void (AIS_Circle::*)(const Standard_Boolean)) &AIS_Circle::SetFilledCircleSens, "Sets the type of sensitivity for the circle. If theIsFilledCircleSens set to Standard_True then the whole circle will be detectable, otherwise only the boundary of the circle.", py::arg("theIsFilledCircleSens"));

// Enums

}