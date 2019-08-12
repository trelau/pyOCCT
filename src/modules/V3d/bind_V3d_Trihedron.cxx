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
#include <V3d_Trihedron.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_TypeOfTriedronPosition.hxx>
#include <Quantity_Color.hxx>
#include <V3d_View.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_TextAspect.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_TransformPers.hxx>

void bind_V3d_Trihedron(py::module &mod){

py::class_<V3d_Trihedron, opencascade::handle<V3d_Trihedron>, Standard_Transient> cls_V3d_Trihedron(mod, "V3d_Trihedron", "Class for presentation of zbuffer trihedron object.");

// Constructors
cls_V3d_Trihedron.def(py::init<>());

// Fields

// Methods
cls_V3d_Trihedron.def_static("get_type_name_", (const char * (*)()) &V3d_Trihedron::get_type_name, "None");
cls_V3d_Trihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_Trihedron::get_type_descriptor, "None");
cls_V3d_Trihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_Trihedron::*)() const) &V3d_Trihedron::DynamicType, "None");
cls_V3d_Trihedron.def("SetWireframe", (void (V3d_Trihedron::*)(const Standard_Boolean)) &V3d_Trihedron::SetWireframe, "Switch wireframe / shaded trihedron.", py::arg("theAsWireframe"));
cls_V3d_Trihedron.def("SetPosition", (void (V3d_Trihedron::*)(const Aspect_TypeOfTriedronPosition)) &V3d_Trihedron::SetPosition, "Setup the corner to draw the trihedron.", py::arg("thePosition"));
cls_V3d_Trihedron.def("SetScale", (void (V3d_Trihedron::*)(const Standard_Real)) &V3d_Trihedron::SetScale, "Setup the scale factor.", py::arg("theScale"));
cls_V3d_Trihedron.def("SetSizeRatio", (void (V3d_Trihedron::*)(const Standard_Real)) &V3d_Trihedron::SetSizeRatio, "Setup the size ratio factor.", py::arg("theRatio"));
cls_V3d_Trihedron.def("SetArrowDiameter", (void (V3d_Trihedron::*)(const Standard_Real)) &V3d_Trihedron::SetArrowDiameter, "Setup the arrow diameter.", py::arg("theDiam"));
cls_V3d_Trihedron.def("SetNbFacets", (void (V3d_Trihedron::*)(const Standard_Integer)) &V3d_Trihedron::SetNbFacets, "Setup the number of facets for tessellation.", py::arg("theNbFacets"));
cls_V3d_Trihedron.def("SetLabelsColor", (void (V3d_Trihedron::*)(const Quantity_Color &)) &V3d_Trihedron::SetLabelsColor, "Setup color of text labels.", py::arg("theColor"));
cls_V3d_Trihedron.def("SetArrowsColor", (void (V3d_Trihedron::*)(const Quantity_Color &, const Quantity_Color &, const Quantity_Color &)) &V3d_Trihedron::SetArrowsColor, "Setup colors of arrows.", py::arg("theXColor"), py::arg("theYColor"), py::arg("theZColor"));
cls_V3d_Trihedron.def("Display", (void (V3d_Trihedron::*)(const V3d_View &)) &V3d_Trihedron::Display, "Display trihedron.", py::arg("theView"));
cls_V3d_Trihedron.def("Erase", (void (V3d_Trihedron::*)()) &V3d_Trihedron::Erase, "Erase trihedron.");

// Enums

}