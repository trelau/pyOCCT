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
#include <AdvApp2Var_SequenceOfPatch.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <AdvApp2Var_Patch.hxx>
#include <AdvApp2Var_Network.hxx>

void bind_AdvApp2Var_Network(py::module &mod){

py::class_<AdvApp2Var_Network, std::unique_ptr<AdvApp2Var_Network, Deleter<AdvApp2Var_Network>>> cls_AdvApp2Var_Network(mod, "AdvApp2Var_Network", "None");

// Constructors
cls_AdvApp2Var_Network.def(py::init<>());
cls_AdvApp2Var_Network.def(py::init<const AdvApp2Var_SequenceOfPatch &, const TColStd_SequenceOfReal &, const TColStd_SequenceOfReal &>(), py::arg("Net"), py::arg("TheU"), py::arg("TheV"));

// Fields

// Methods
// cls_AdvApp2Var_Network.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Network::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Network.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Network::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Network.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Network::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Network.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Network::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Network.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Network::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Network.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Network::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Network.def("FirstNotApprox", [](AdvApp2Var_Network &self, Standard_Integer & Index){ Standard_Boolean rv = self.FirstNotApprox(Index); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, Index); }, "search the Index of the first Patch not approximated, if all Patches are approximated Standard_False is returned", py::arg("Index"));
cls_AdvApp2Var_Network.def("ChangePatch", (AdvApp2Var_Patch & (AdvApp2Var_Network::*)(const Standard_Integer)) &AdvApp2Var_Network::ChangePatch, "None", py::arg("Index"));
cls_AdvApp2Var_Network.def("__call__", (AdvApp2Var_Patch & (AdvApp2Var_Network::*)(const Standard_Integer)) &AdvApp2Var_Network::operator(), py::is_operator(), "None", py::arg("Index"));
cls_AdvApp2Var_Network.def("UpdateInU", (void (AdvApp2Var_Network::*)(const Standard_Real)) &AdvApp2Var_Network::UpdateInU, "None", py::arg("CuttingValue"));
cls_AdvApp2Var_Network.def("UpdateInV", (void (AdvApp2Var_Network::*)(const Standard_Real)) &AdvApp2Var_Network::UpdateInV, "None", py::arg("CuttingValue"));
cls_AdvApp2Var_Network.def("SameDegree", [](AdvApp2Var_Network &self, const Standard_Integer iu, const Standard_Integer iv, Standard_Integer & ncfu, Standard_Integer & ncfv){ self.SameDegree(iu, iv, ncfu, ncfv); return std::tuple<Standard_Integer &, Standard_Integer &>(ncfu, ncfv); }, "None", py::arg("iu"), py::arg("iv"), py::arg("ncfu"), py::arg("ncfv"));
cls_AdvApp2Var_Network.def("NbPatch", (Standard_Integer (AdvApp2Var_Network::*)() const) &AdvApp2Var_Network::NbPatch, "None");
cls_AdvApp2Var_Network.def("NbPatchInU", (Standard_Integer (AdvApp2Var_Network::*)() const) &AdvApp2Var_Network::NbPatchInU, "None");
cls_AdvApp2Var_Network.def("NbPatchInV", (Standard_Integer (AdvApp2Var_Network::*)() const) &AdvApp2Var_Network::NbPatchInV, "None");
cls_AdvApp2Var_Network.def("UParameter", (Standard_Real (AdvApp2Var_Network::*)(const Standard_Integer) const) &AdvApp2Var_Network::UParameter, "None", py::arg("Index"));
cls_AdvApp2Var_Network.def("VParameter", (Standard_Real (AdvApp2Var_Network::*)(const Standard_Integer) const) &AdvApp2Var_Network::VParameter, "None", py::arg("Index"));
cls_AdvApp2Var_Network.def("Patch", (const AdvApp2Var_Patch & (AdvApp2Var_Network::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Network::Patch, "None", py::arg("UIndex"), py::arg("VIndex"));
cls_AdvApp2Var_Network.def("__call__", (const AdvApp2Var_Patch & (AdvApp2Var_Network::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Network::operator(), py::is_operator(), "None", py::arg("UIndex"), py::arg("VIndex"));

// Enums

}