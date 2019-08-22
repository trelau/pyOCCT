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
#include <TopoDS_Face.hxx>
#include <HLRTopoBRep_Data.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Line.hxx>
#include <HLRTopoBRep_FaceIsoLiner.hxx>

void bind_HLRTopoBRep_FaceIsoLiner(py::module &mod){

py::class_<HLRTopoBRep_FaceIsoLiner> cls_HLRTopoBRep_FaceIsoLiner(mod, "HLRTopoBRep_FaceIsoLiner", "None");

// Constructors

// Fields

// Methods
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator new_", (void * (*)(size_t)) &HLRTopoBRep_FaceIsoLiner::operator new, "None", py::arg("theSize"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator delete_", (void (*)(void *)) &HLRTopoBRep_FaceIsoLiner::operator delete, "None", py::arg("theAddress"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator new[]_", (void * (*)(size_t)) &HLRTopoBRep_FaceIsoLiner::operator new[], "None", py::arg("theSize"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator delete[]_", (void (*)(void *)) &HLRTopoBRep_FaceIsoLiner::operator delete[], "None", py::arg("theAddress"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator new_", (void * (*)(size_t, void *)) &HLRTopoBRep_FaceIsoLiner::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator delete_", (void (*)(void *, void *)) &HLRTopoBRep_FaceIsoLiner::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRTopoBRep_FaceIsoLiner.def_static("Perform_", (void (*)(const Standard_Integer, const TopoDS_Face &, HLRTopoBRep_Data &, const Standard_Integer)) &HLRTopoBRep_FaceIsoLiner::Perform, "None", py::arg("FI"), py::arg("F"), py::arg("DS"), py::arg("nbIsos"));
cls_HLRTopoBRep_FaceIsoLiner.def_static("MakeVertex_", (TopoDS_Vertex (*)(const TopoDS_Edge &, const gp_Pnt &, const Standard_Real, const Standard_Real, HLRTopoBRep_Data &)) &HLRTopoBRep_FaceIsoLiner::MakeVertex, "None", py::arg("E"), py::arg("P"), py::arg("Par"), py::arg("Tol"), py::arg("DS"));
cls_HLRTopoBRep_FaceIsoLiner.def_static("MakeIsoLine_", (void (*)(const TopoDS_Face &, const opencascade::handle<Geom2d_Line> &, TopoDS_Vertex &, TopoDS_Vertex &, const Standard_Real, const Standard_Real, const Standard_Real, HLRTopoBRep_Data &)) &HLRTopoBRep_FaceIsoLiner::MakeIsoLine, "None", py::arg("F"), py::arg("Iso"), py::arg("V1"), py::arg("V2"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("DS"));

// Enums

}