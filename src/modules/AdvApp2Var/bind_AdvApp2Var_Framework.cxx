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
#include <AdvApp2Var_SequenceOfNode.hxx>
#include <AdvApp2Var_SequenceOfStrip.hxx>
#include <Standard_TypeDef.hxx>
#include <AdvApp2Var_Iso.hxx>
#include <GeomAbs_IsoType.hxx>
#include <AdvApp2Var_Node.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <AdvApp2Var_Framework.hxx>

void bind_AdvApp2Var_Framework(py::module &mod){

py::class_<AdvApp2Var_Framework, std::unique_ptr<AdvApp2Var_Framework, Deleter<AdvApp2Var_Framework>>> cls_AdvApp2Var_Framework(mod, "AdvApp2Var_Framework", "None");

// Constructors
cls_AdvApp2Var_Framework.def(py::init<>());
cls_AdvApp2Var_Framework.def(py::init<const AdvApp2Var_SequenceOfNode &, const AdvApp2Var_SequenceOfStrip &, const AdvApp2Var_SequenceOfStrip &>(), py::arg("Frame"), py::arg("UFrontier"), py::arg("VFrontier"));

// Fields

// Methods
// cls_AdvApp2Var_Framework.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Framework::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Framework.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Framework::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Framework.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Framework::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Framework.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Framework::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Framework.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Framework::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Framework.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Framework::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Framework.def("FirstNotApprox", [](AdvApp2Var_Framework &self, Standard_Integer & IndexIso, Standard_Integer & IndexStrip, AdvApp2Var_Iso & anIso){ Standard_Boolean rv = self.FirstNotApprox(IndexIso, IndexStrip, anIso); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndexIso, IndexStrip); }, "search the Index of the first Iso not approximated, if all Isos are approximated Standard_False is returned.", py::arg("IndexIso"), py::arg("IndexStrip"), py::arg("anIso"));
cls_AdvApp2Var_Framework.def("FirstNode", (Standard_Integer (AdvApp2Var_Framework::*)(const GeomAbs_IsoType, const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Framework::FirstNode, "None", py::arg("Type"), py::arg("IndexIso"), py::arg("IndexStrip"));
cls_AdvApp2Var_Framework.def("LastNode", (Standard_Integer (AdvApp2Var_Framework::*)(const GeomAbs_IsoType, const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Framework::LastNode, "None", py::arg("Type"), py::arg("IndexIso"), py::arg("IndexStrip"));
cls_AdvApp2Var_Framework.def("ChangeIso", (void (AdvApp2Var_Framework::*)(const Standard_Integer, const Standard_Integer, const AdvApp2Var_Iso &)) &AdvApp2Var_Framework::ChangeIso, "None", py::arg("IndexIso"), py::arg("IndexStrip"), py::arg("anIso"));
cls_AdvApp2Var_Framework.def("Node", (const AdvApp2Var_Node & (AdvApp2Var_Framework::*)(const Standard_Integer) const) &AdvApp2Var_Framework::Node, "None", py::arg("IndexNode"));
cls_AdvApp2Var_Framework.def("Node", (const AdvApp2Var_Node & (AdvApp2Var_Framework::*)(const Standard_Real, const Standard_Real) const) &AdvApp2Var_Framework::Node, "None", py::arg("U"), py::arg("V"));
cls_AdvApp2Var_Framework.def("IsoU", (const AdvApp2Var_Iso & (AdvApp2Var_Framework::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &AdvApp2Var_Framework::IsoU, "None", py::arg("U"), py::arg("V0"), py::arg("V1"));
cls_AdvApp2Var_Framework.def("IsoV", (const AdvApp2Var_Iso & (AdvApp2Var_Framework::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &AdvApp2Var_Framework::IsoV, "None", py::arg("U0"), py::arg("U1"), py::arg("V"));
cls_AdvApp2Var_Framework.def("ChangeNode", (AdvApp2Var_Node & (AdvApp2Var_Framework::*)(const Standard_Integer)) &AdvApp2Var_Framework::ChangeNode, "None", py::arg("IndexNode"));
cls_AdvApp2Var_Framework.def("UpdateInU", (void (AdvApp2Var_Framework::*)(const Standard_Real)) &AdvApp2Var_Framework::UpdateInU, "None", py::arg("CuttingValue"));
cls_AdvApp2Var_Framework.def("UpdateInV", (void (AdvApp2Var_Framework::*)(const Standard_Real)) &AdvApp2Var_Framework::UpdateInV, "None", py::arg("CuttingValue"));
cls_AdvApp2Var_Framework.def("UEquation", (const opencascade::handle<TColStd_HArray1OfReal> & (AdvApp2Var_Framework::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Framework::UEquation, "None", py::arg("IndexIso"), py::arg("IndexStrip"));
cls_AdvApp2Var_Framework.def("VEquation", (const opencascade::handle<TColStd_HArray1OfReal> & (AdvApp2Var_Framework::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Framework::VEquation, "None", py::arg("IndexIso"), py::arg("IndexStrip"));

// Enums

}