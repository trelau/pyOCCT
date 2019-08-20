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
#include <Bnd_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_ExtFlag.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <Precision.hxx>
#include <BRepExtrema_SeqOfSolution.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <BRepExtrema_DistanceSS.hxx>

void bind_BRepExtrema_DistanceSS(py::module &mod){

py::class_<BRepExtrema_DistanceSS, std::unique_ptr<BRepExtrema_DistanceSS>> cls_BRepExtrema_DistanceSS(mod, "BRepExtrema_DistanceSS", "This class allows to compute minimum distance between two shapes (face edge vertex) and is used in DistShapeShape class.");

// Constructors
cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"));
cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Extrema_ExtFlag>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("F"));
cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("F"), py::arg("A"));
cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("aDeflection"));
cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("aDeflection"), py::arg("F"));
cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("aDeflection"), py::arg("F"), py::arg("A"));

// Fields

// Methods
// cls_BRepExtrema_DistanceSS.def_static("operator new_", (void * (*)(size_t)) &BRepExtrema_DistanceSS::operator new, "None", py::arg("theSize"));
// cls_BRepExtrema_DistanceSS.def_static("operator delete_", (void (*)(void *)) &BRepExtrema_DistanceSS::operator delete, "None", py::arg("theAddress"));
// cls_BRepExtrema_DistanceSS.def_static("operator new[]_", (void * (*)(size_t)) &BRepExtrema_DistanceSS::operator new[], "None", py::arg("theSize"));
// cls_BRepExtrema_DistanceSS.def_static("operator delete[]_", (void (*)(void *)) &BRepExtrema_DistanceSS::operator delete[], "None", py::arg("theAddress"));
// cls_BRepExtrema_DistanceSS.def_static("operator new_", (void * (*)(size_t, void *)) &BRepExtrema_DistanceSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepExtrema_DistanceSS.def_static("operator delete_", (void (*)(void *, void *)) &BRepExtrema_DistanceSS::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepExtrema_DistanceSS.def("IsDone", (Standard_Boolean (BRepExtrema_DistanceSS::*)() const) &BRepExtrema_DistanceSS::IsDone, "True if the distance has been computed");
cls_BRepExtrema_DistanceSS.def("DistValue", (Standard_Real (BRepExtrema_DistanceSS::*)() const) &BRepExtrema_DistanceSS::DistValue, "returns the distance value");
cls_BRepExtrema_DistanceSS.def("Seq1Value", (const BRepExtrema_SeqOfSolution & (BRepExtrema_DistanceSS::*)() const) &BRepExtrema_DistanceSS::Seq1Value, "returns the list of solutions on the first shape");
cls_BRepExtrema_DistanceSS.def("Seq2Value", (const BRepExtrema_SeqOfSolution & (BRepExtrema_DistanceSS::*)() const) &BRepExtrema_DistanceSS::Seq2Value, "returns the list of solutions on the second shape");
cls_BRepExtrema_DistanceSS.def("SetFlag", (void (BRepExtrema_DistanceSS::*)(const Extrema_ExtFlag)) &BRepExtrema_DistanceSS::SetFlag, "sets the flag controlling minimum and maximum search", py::arg("F"));
cls_BRepExtrema_DistanceSS.def("SetAlgo", (void (BRepExtrema_DistanceSS::*)(const Extrema_ExtAlgo)) &BRepExtrema_DistanceSS::SetAlgo, "sets the flag controlling ...", py::arg("A"));

// Enums

}