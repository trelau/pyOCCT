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
#include <TopAbs_State.hxx>
#include <HLRAlgo_Coincidence.hxx>

void bind_HLRAlgo_Coincidence(py::module &mod){

py::class_<HLRAlgo_Coincidence> cls_HLRAlgo_Coincidence(mod, "HLRAlgo_Coincidence", "The Coincidence class is used in an Inteference to store informations on the 'hiding' edge.");

// Constructors
cls_HLRAlgo_Coincidence.def(py::init<>());

// Fields

// Methods
// cls_HLRAlgo_Coincidence.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_Coincidence::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_Coincidence.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_Coincidence::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_Coincidence.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_Coincidence::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_Coincidence.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_Coincidence::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_Coincidence.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_Coincidence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_Coincidence.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_Coincidence::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_Coincidence.def("Set2D", (void (HLRAlgo_Coincidence::*)(const Standard_Integer, const Standard_Real)) &HLRAlgo_Coincidence::Set2D, "None", py::arg("FE"), py::arg("Param"));
cls_HLRAlgo_Coincidence.def("SetState3D", (void (HLRAlgo_Coincidence::*)(const TopAbs_State, const TopAbs_State)) &HLRAlgo_Coincidence::SetState3D, "None", py::arg("stbef"), py::arg("staft"));
cls_HLRAlgo_Coincidence.def("Value2D", [](HLRAlgo_Coincidence &self, Standard_Integer & FE, Standard_Real & Param){ self.Value2D(FE, Param); return std::tuple<Standard_Integer &, Standard_Real &>(FE, Param); }, "None", py::arg("FE"), py::arg("Param"));
cls_HLRAlgo_Coincidence.def("State3D", (void (HLRAlgo_Coincidence::*)(TopAbs_State &, TopAbs_State &) const) &HLRAlgo_Coincidence::State3D, "None", py::arg("stbef"), py::arg("staft"));

// Enums

}