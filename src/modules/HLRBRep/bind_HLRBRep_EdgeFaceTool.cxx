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
#include <gp_Dir.hxx>
#include <HLRBRep_EdgeFaceTool.hxx>

void bind_HLRBRep_EdgeFaceTool(py::module &mod){

py::class_<HLRBRep_EdgeFaceTool> cls_HLRBRep_EdgeFaceTool(mod, "HLRBRep_EdgeFaceTool", "The EdgeFaceTool computes the UV coordinates at a given parameter on a Curve and a Surface. It also compute the signed curvature value in a direction at a given u,v point on a surface.");

// Constructors

// Fields

// Methods
// cls_HLRBRep_EdgeFaceTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeFaceTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeFaceTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeFaceTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeFaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeFaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeFaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeFaceTool.def_static("CurvatureValue_", (Standard_Real (*)(const Standard_Address, const Standard_Real, const Standard_Real, const gp_Dir &)) &HLRBRep_EdgeFaceTool::CurvatureValue, "None", py::arg("F"), py::arg("U"), py::arg("V"), py::arg("Tg"));
cls_HLRBRep_EdgeFaceTool.def_static("UVPoint_", [](const Standard_Real Par, const Standard_Address E, const Standard_Address F, Standard_Real & U, Standard_Real & V){ Standard_Boolean rv = HLRBRep_EdgeFaceTool::UVPoint(Par, E, F, U, V); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, U, V); }, "return True if U and V are found.", py::arg("Par"), py::arg("E"), py::arg("F"), py::arg("U"), py::arg("V"));

// Enums

}