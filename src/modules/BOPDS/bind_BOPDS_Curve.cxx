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
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IntTools_Curve.hxx>
#include <Bnd_Box.hxx>
#include <BOPDS_ListOfPaveBlock.hxx>
#include <BOPDS_PaveBlock.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPDS_Curve.hxx>

void bind_BOPDS_Curve(py::module &mod){

py::class_<BOPDS_Curve, std::unique_ptr<BOPDS_Curve, Deleter<BOPDS_Curve>>> cls_BOPDS_Curve(mod, "BOPDS_Curve", "The class BOPDS_Curve is to store the information about intersection curve");

// Constructors
cls_BOPDS_Curve.def(py::init<>());
cls_BOPDS_Curve.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPDS_Curve.def_static("operator new_", (void * (*)(size_t)) &BOPDS_Curve::operator new, "None", py::arg("theSize"));
// cls_BOPDS_Curve.def_static("operator delete_", (void (*)(void *)) &BOPDS_Curve::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_Curve.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_Curve::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_Curve.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_Curve.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_Curve.def("SetCurve", (void (BOPDS_Curve::*)(const IntTools_Curve &)) &BOPDS_Curve::SetCurve, "Modifier Sets the curve <theC>", py::arg("theC"));
cls_BOPDS_Curve.def("Curve", (const IntTools_Curve & (BOPDS_Curve::*)() const) &BOPDS_Curve::Curve, "Selector Returns the curve");
cls_BOPDS_Curve.def("SetBox", (void (BOPDS_Curve::*)(const Bnd_Box &)) &BOPDS_Curve::SetBox, "Modifier Sets the bounding box <theBox> of the curve", py::arg("theBox"));
cls_BOPDS_Curve.def("Box", (const Bnd_Box & (BOPDS_Curve::*)() const) &BOPDS_Curve::Box, "Selector Returns the bounding box of the curve");
cls_BOPDS_Curve.def("ChangeBox", (Bnd_Box & (BOPDS_Curve::*)()) &BOPDS_Curve::ChangeBox, "Selector/Modifier Returns the bounding box of the curve");
cls_BOPDS_Curve.def("SetPaveBlocks", (void (BOPDS_Curve::*)(const BOPDS_ListOfPaveBlock &)) &BOPDS_Curve::SetPaveBlocks, "None", py::arg("theLPB"));
cls_BOPDS_Curve.def("PaveBlocks", (const BOPDS_ListOfPaveBlock & (BOPDS_Curve::*)() const) &BOPDS_Curve::PaveBlocks, "Selector Returns the list of pave blocks of the curve");
cls_BOPDS_Curve.def("ChangePaveBlocks", (BOPDS_ListOfPaveBlock & (BOPDS_Curve::*)()) &BOPDS_Curve::ChangePaveBlocks, "Selector/Modifier Returns the list of pave blocks of the curve");
cls_BOPDS_Curve.def("InitPaveBlock1", (void (BOPDS_Curve::*)()) &BOPDS_Curve::InitPaveBlock1, "Creates initial pave block of the curve");
cls_BOPDS_Curve.def("ChangePaveBlock1", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_Curve::*)()) &BOPDS_Curve::ChangePaveBlock1, "Selector/Modifier Returns initial pave block of the curve");
cls_BOPDS_Curve.def("TechnoVertices", (const TColStd_ListOfInteger & (BOPDS_Curve::*)() const) &BOPDS_Curve::TechnoVertices, "Selector Returns list of indices of technologic vertices of the curve");
cls_BOPDS_Curve.def("ChangeTechnoVertices", (TColStd_ListOfInteger & (BOPDS_Curve::*)()) &BOPDS_Curve::ChangeTechnoVertices, "Selector/Modifier Returns list of indices of technologic vertices of the curve");
cls_BOPDS_Curve.def("HasEdge", (Standard_Boolean (BOPDS_Curve::*)() const) &BOPDS_Curve::HasEdge, "Query Returns true if at least one pave block of the curve has edge");
cls_BOPDS_Curve.def("SetTolerance", (void (BOPDS_Curve::*)(const Standard_Real)) &BOPDS_Curve::SetTolerance, "Sets the tolerance for the curve.", py::arg("theTol"));
cls_BOPDS_Curve.def("Tolerance", (Standard_Real (BOPDS_Curve::*)() const) &BOPDS_Curve::Tolerance, "Returns the tolerance of the curve");
cls_BOPDS_Curve.def("TangentialTolerance", (Standard_Real (BOPDS_Curve::*)() const) &BOPDS_Curve::TangentialTolerance, "Returns the tangential tolerance of the curve");

// Enums

}