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
#include <Standard_Handle.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <ShapeExtend_Explorer.hxx>

void bind_ShapeExtend_Explorer(py::module &mod){

py::class_<ShapeExtend_Explorer> cls_ShapeExtend_Explorer(mod, "ShapeExtend_Explorer", "This class is intended to explore shapes and convert different representations (list, sequence, compound) of complex shapes. It provides tools for: - obtaining type of the shapes in context of TopoDS_Compound, - exploring shapes in context of TopoDS_Compound, - converting different representations of shapes (list, sequence, compound).");

// Constructors
cls_ShapeExtend_Explorer.def(py::init<>());

// Fields

// Methods
// cls_ShapeExtend_Explorer.def_static("operator new_", (void * (*)(size_t)) &ShapeExtend_Explorer::operator new, "None", py::arg("theSize"));
// cls_ShapeExtend_Explorer.def_static("operator delete_", (void (*)(void *)) &ShapeExtend_Explorer::operator delete, "None", py::arg("theAddress"));
// cls_ShapeExtend_Explorer.def_static("operator new[]_", (void * (*)(size_t)) &ShapeExtend_Explorer::operator new[], "None", py::arg("theSize"));
// cls_ShapeExtend_Explorer.def_static("operator delete[]_", (void (*)(void *)) &ShapeExtend_Explorer::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeExtend_Explorer.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeExtend_Explorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeExtend_Explorer.def_static("operator delete_", (void (*)(void *, void *)) &ShapeExtend_Explorer::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeExtend_Explorer.def("CompoundFromSeq", (TopoDS_Shape (ShapeExtend_Explorer::*)(const opencascade::handle<TopTools_HSequenceOfShape> &) const) &ShapeExtend_Explorer::CompoundFromSeq, "Converts a sequence of Shapes to a Compound", py::arg("seqval"));
cls_ShapeExtend_Explorer.def("SeqFromCompound", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeExtend_Explorer::*)(const TopoDS_Shape &, const Standard_Boolean) const) &ShapeExtend_Explorer::SeqFromCompound, "Converts a Compound to a list of Shapes if <comp> is not a compound, the list contains only <comp> if <comp> is Null, the list is empty if <comp> is a Compound, its sub-shapes are put into the list then if <expcomp> is True, if a sub-shape is a Compound, it is not put to the list but its sub-shapes are (recursive)", py::arg("comp"), py::arg("expcomp"));
cls_ShapeExtend_Explorer.def("ListFromSeq", [](ShapeExtend_Explorer &self, const opencascade::handle<TopTools_HSequenceOfShape> & a0, TopTools_ListOfShape & a1) -> void { return self.ListFromSeq(a0, a1); });
cls_ShapeExtend_Explorer.def("ListFromSeq", (void (ShapeExtend_Explorer::*)(const opencascade::handle<TopTools_HSequenceOfShape> &, TopTools_ListOfShape &, const Standard_Boolean) const) &ShapeExtend_Explorer::ListFromSeq, "Converts a Sequence of Shapes to a List of Shapes <clear> if True (D), commands the list to start from scratch else, the list is cumulated", py::arg("seqval"), py::arg("lisval"), py::arg("clear"));
cls_ShapeExtend_Explorer.def("SeqFromList", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeExtend_Explorer::*)(const TopTools_ListOfShape &) const) &ShapeExtend_Explorer::SeqFromList, "Converts a List of Shapes to a Sequence of Shapes", py::arg("lisval"));
cls_ShapeExtend_Explorer.def("ShapeType", (TopAbs_ShapeEnum (ShapeExtend_Explorer::*)(const TopoDS_Shape &, const Standard_Boolean) const) &ShapeExtend_Explorer::ShapeType, "Returns the type of a Shape: true type if <compound> is False If <compound> is True and <shape> is a Compound, iterates on its items. If all are of the same type, returns this type. Else, returns COMPOUND. If it is empty, returns SHAPE For a Null Shape, returns SHAPE", py::arg("shape"), py::arg("compound"));
cls_ShapeExtend_Explorer.def("SortedCompound", (TopoDS_Shape (ShapeExtend_Explorer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const Standard_Boolean, const Standard_Boolean) const) &ShapeExtend_Explorer::SortedCompound, "Builds a COMPOUND from the given shape. It explores the shape level by level, according to the <explore> argument. If <explore> is False, only COMPOUND items are explored, else all items are. The following shapes are added to resulting compound: - shapes which comply to <type> - if <type> is WIRE, considers also free edges (and makes wires) - if <type> is SHELL, considers also free faces (and makes shells) If <compound> is True, gathers items in compounds which correspond to starting COMPOUND,SOLID or SHELL containers, or items directly contained in a Compound", py::arg("shape"), py::arg("type"), py::arg("explore"), py::arg("compound"));
cls_ShapeExtend_Explorer.def("DispatchList", (void (ShapeExtend_Explorer::*)(const opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &) const) &ShapeExtend_Explorer::DispatchList, "Dispatches starting list of shapes according to their type, to the appropriate resulting lists For each of these lists, if it is null, it is firstly created else, new items are appended to the already existing ones", py::arg("list"), py::arg("vertices"), py::arg("edges"), py::arg("wires"), py::arg("faces"), py::arg("shells"), py::arg("solids"), py::arg("compsols"), py::arg("compounds"));

// Enums

}