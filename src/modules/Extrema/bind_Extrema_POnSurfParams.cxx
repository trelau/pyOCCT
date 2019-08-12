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
#include <Extrema_POnSurf.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ElementType.hxx>
#include <Extrema_POnSurfParams.hxx>

void bind_Extrema_POnSurfParams(py::module &mod){

py::class_<Extrema_POnSurfParams, std::unique_ptr<Extrema_POnSurfParams, Deleter<Extrema_POnSurfParams>>, Extrema_POnSurf> cls_Extrema_POnSurfParams(mod, "Extrema_POnSurfParams", "Data container for point on surface parameters. These parameters are required to compute an initial approximation for extrema computation.");

// Constructors
cls_Extrema_POnSurfParams.def(py::init<>());
cls_Extrema_POnSurfParams.def(py::init<const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("theU"), py::arg("theV"), py::arg("thePnt"));

// Fields

// Methods
// cls_Extrema_POnSurfParams.def_static("operator new_", (void * (*)(size_t)) &Extrema_POnSurfParams::operator new, "None", py::arg("theSize"));
// cls_Extrema_POnSurfParams.def_static("operator delete_", (void (*)(void *)) &Extrema_POnSurfParams::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_POnSurfParams.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_POnSurfParams::operator new[], "None", py::arg("theSize"));
// cls_Extrema_POnSurfParams.def_static("operator delete[]_", (void (*)(void *)) &Extrema_POnSurfParams::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_POnSurfParams.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_POnSurfParams::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_POnSurfParams.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_POnSurfParams::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_POnSurfParams.def("SetSqrDistance", (void (Extrema_POnSurfParams::*)(const Standard_Real)) &Extrema_POnSurfParams::SetSqrDistance, "Sets the square distance from this point to another one (e.g. to the point to be projected).", py::arg("theSqrDistance"));
cls_Extrema_POnSurfParams.def("GetSqrDistance", (Standard_Real (Extrema_POnSurfParams::*)() const) &Extrema_POnSurfParams::GetSqrDistance, "Query the square distance from this point to another one.");
cls_Extrema_POnSurfParams.def("SetElementType", (void (Extrema_POnSurfParams::*)(const Extrema_ElementType)) &Extrema_POnSurfParams::SetElementType, "Sets the element type on which this point is situated.", py::arg("theElementType"));
cls_Extrema_POnSurfParams.def("GetElementType", (Extrema_ElementType (Extrema_POnSurfParams::*)() const) &Extrema_POnSurfParams::GetElementType, "Query the element type on which this point is situated.");
cls_Extrema_POnSurfParams.def("SetIndices", (void (Extrema_POnSurfParams::*)(const Standard_Integer, const Standard_Integer)) &Extrema_POnSurfParams::SetIndices, "Sets the U and V indices of an element that contains this point.", py::arg("theIndexU"), py::arg("theIndexV"));
cls_Extrema_POnSurfParams.def("GetIndices", [](Extrema_POnSurfParams &self, Standard_Integer & theIndexU, Standard_Integer & theIndexV){ self.GetIndices(theIndexU, theIndexV); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndexU, theIndexV); }, "Query the U and V indices of an element that contains this point.", py::arg("theIndexU"), py::arg("theIndexV"));

// Enums

}