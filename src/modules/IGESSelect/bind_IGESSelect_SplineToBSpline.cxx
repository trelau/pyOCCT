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
#include <IFSelect_Transformer.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Graph.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_SplineToBSpline.hxx>
#include <Standard_Type.hxx>
#include <Interface_CopyControl.hxx>

void bind_IGESSelect_SplineToBSpline(py::module &mod){

py::class_<IGESSelect_SplineToBSpline, opencascade::handle<IGESSelect_SplineToBSpline>, IFSelect_Transformer> cls_IGESSelect_SplineToBSpline(mod, "IGESSelect_SplineToBSpline", "This type of Transformer allows to convert Spline Curves (IGES type 112) and Surfaces (IGES Type 126) to BSpline Curves (IGES type 114) and Surfac (IGES Type 128). All other entities are rebuilt as identical but on the basis of this conversion.");

// Constructors
cls_IGESSelect_SplineToBSpline.def(py::init<const Standard_Boolean>(), py::arg("tryC2"));

// Fields

// Methods
cls_IGESSelect_SplineToBSpline.def("OptionTryC2", (Standard_Boolean (IGESSelect_SplineToBSpline::*)() const) &IGESSelect_SplineToBSpline::OptionTryC2, "Returns the option TryC2 given at creation time");
cls_IGESSelect_SplineToBSpline.def("Perform", (Standard_Boolean (IGESSelect_SplineToBSpline::*)(const Interface_Graph &, const opencascade::handle<Interface_Protocol> &, Interface_CheckIterator &, opencascade::handle<Interface_InterfaceModel> &)) &IGESSelect_SplineToBSpline::Perform, "Performs the transformation, if there is at least one Spline Curve (112) or Surface (126). Does nothing if there is none.", py::arg("G"), py::arg("protocol"), py::arg("checks"), py::arg("newmod"));
cls_IGESSelect_SplineToBSpline.def("Updated", (Standard_Boolean (IGESSelect_SplineToBSpline::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &IGESSelect_SplineToBSpline::Updated, "Returns the transformed entities. If original data contained no Spline Curve or Surface, the result is identity : <entto> = <entfrom> Else, the copied counterpart is returned : for a Spline Curve or Surface, it is a converted BSpline Curve or Surface. Else, it is the result of general service Copy (rebuilt as necessary by BSPlines replacing Splines).", py::arg("entfrom"), py::arg("entto"));
cls_IGESSelect_SplineToBSpline.def("Label", (TCollection_AsciiString (IGESSelect_SplineToBSpline::*)() const) &IGESSelect_SplineToBSpline::Label, "Returns a text which defines the way a Transformer works : 'Conversion Spline to BSpline' and as opted, ' trying to upgrade continuity'");
cls_IGESSelect_SplineToBSpline.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SplineToBSpline::get_type_name, "None");
cls_IGESSelect_SplineToBSpline.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SplineToBSpline::get_type_descriptor, "None");
cls_IGESSelect_SplineToBSpline.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SplineToBSpline::*)() const) &IGESSelect_SplineToBSpline::DynamicType, "None");

// Enums

}