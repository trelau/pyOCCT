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
#include <Contap_SurfFunction.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_InteriorPoint.hxx>
#include <IntSurf_SequenceOfInteriorPoint.hxx>
#include <Contap_TheSearchInside.hxx>

void bind_Contap_TheSearchInside(py::module &mod){

py::class_<Contap_TheSearchInside, std::unique_ptr<Contap_TheSearchInside, Deleter<Contap_TheSearchInside>>> cls_Contap_TheSearchInside(mod, "Contap_TheSearchInside", "None");

// Constructors
cls_Contap_TheSearchInside.def(py::init<>());
cls_Contap_TheSearchInside.def(py::init<Contap_SurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real>(), py::arg("F"), py::arg("Surf"), py::arg("T"), py::arg("Epsilon"));

// Fields

// Methods
// cls_Contap_TheSearchInside.def_static("operator new_", (void * (*)(size_t)) &Contap_TheSearchInside::operator new, "None", py::arg("theSize"));
// cls_Contap_TheSearchInside.def_static("operator delete_", (void (*)(void *)) &Contap_TheSearchInside::operator delete, "None", py::arg("theAddress"));
// cls_Contap_TheSearchInside.def_static("operator new[]_", (void * (*)(size_t)) &Contap_TheSearchInside::operator new[], "None", py::arg("theSize"));
// cls_Contap_TheSearchInside.def_static("operator delete[]_", (void (*)(void *)) &Contap_TheSearchInside::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_TheSearchInside.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_TheSearchInside::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_TheSearchInside.def_static("operator delete_", (void (*)(void *, void *)) &Contap_TheSearchInside::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_TheSearchInside.def("Perform", (void (Contap_TheSearchInside::*)(Contap_SurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real)) &Contap_TheSearchInside::Perform, "None", py::arg("F"), py::arg("Surf"), py::arg("T"), py::arg("Epsilon"));
cls_Contap_TheSearchInside.def("Perform", (void (Contap_TheSearchInside::*)(Contap_SurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Contap_TheSearchInside::Perform, "None", py::arg("F"), py::arg("Surf"), py::arg("UStart"), py::arg("VStart"));
cls_Contap_TheSearchInside.def("IsDone", (Standard_Boolean (Contap_TheSearchInside::*)() const) &Contap_TheSearchInside::IsDone, "None");
cls_Contap_TheSearchInside.def("NbPoints", (Standard_Integer (Contap_TheSearchInside::*)() const) &Contap_TheSearchInside::NbPoints, "Returns the number of points. The exception NotDone if raised if IsDone returns False.");
cls_Contap_TheSearchInside.def("Value", (const IntSurf_InteriorPoint & (Contap_TheSearchInside::*)(const Standard_Integer) const) &Contap_TheSearchInside::Value, "Returns the point of range Index. The exception NotDone if raised if IsDone returns False. The exception OutOfRange if raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));

// Enums

}