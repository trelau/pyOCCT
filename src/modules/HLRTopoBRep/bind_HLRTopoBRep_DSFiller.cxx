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
#include <TopoDS_Shape.hxx>
#include <Contap_Contour.hxx>
#include <HLRTopoBRep_Data.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Vertex.hxx>
#include <Contap_Point.hxx>
#include <TopoDS_Edge.hxx>
#include <HLRTopoBRep_DSFiller.hxx>

void bind_HLRTopoBRep_DSFiller(py::module &mod){

py::class_<HLRTopoBRep_DSFiller> cls_HLRTopoBRep_DSFiller(mod, "HLRTopoBRep_DSFiller", "Provides methods to fill a HLRTopoBRep_Data.");

// Constructors

// Fields

// Methods
// cls_HLRTopoBRep_DSFiller.def_static("operator new_", (void * (*)(size_t)) &HLRTopoBRep_DSFiller::operator new, "None", py::arg("theSize"));
// cls_HLRTopoBRep_DSFiller.def_static("operator delete_", (void (*)(void *)) &HLRTopoBRep_DSFiller::operator delete, "None", py::arg("theAddress"));
// cls_HLRTopoBRep_DSFiller.def_static("operator new[]_", (void * (*)(size_t)) &HLRTopoBRep_DSFiller::operator new[], "None", py::arg("theSize"));
// cls_HLRTopoBRep_DSFiller.def_static("operator delete[]_", (void (*)(void *)) &HLRTopoBRep_DSFiller::operator delete[], "None", py::arg("theAddress"));
// cls_HLRTopoBRep_DSFiller.def_static("operator new_", (void * (*)(size_t, void *)) &HLRTopoBRep_DSFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRTopoBRep_DSFiller.def_static("operator delete_", (void (*)(void *, void *)) &HLRTopoBRep_DSFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRTopoBRep_DSFiller.def_static("Insert_", (void (*)(const TopoDS_Shape &, Contap_Contour &, HLRTopoBRep_Data &, BRepTopAdaptor_MapOfShapeTool &, const Standard_Integer)) &HLRTopoBRep_DSFiller::Insert, "Stores in <DS> the outlines of <S> using the current outliner and stores the isolines in <DS> using a Hatcher.", py::arg("S"), py::arg("FO"), py::arg("DS"), py::arg("MST"), py::arg("nbIso"));

// Enums

}