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
#include <IntSurf_LineOn2S.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Contap_Point.hxx>
#include <Standard_TypeDef.hxx>
#include <Contap_IType.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <Contap_TheHSequenceOfPoint.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Contap_Line.hxx>

void bind_Contap_Line(py::module &mod){

py::class_<Contap_Line, std::unique_ptr<Contap_Line>> cls_Contap_Line(mod, "Contap_Line", "None");

// Constructors
cls_Contap_Line.def(py::init<>());

// Fields

// Methods
// cls_Contap_Line.def_static("operator new_", (void * (*)(size_t)) &Contap_Line::operator new, "None", py::arg("theSize"));
// cls_Contap_Line.def_static("operator delete_", (void (*)(void *)) &Contap_Line::operator delete, "None", py::arg("theAddress"));
// cls_Contap_Line.def_static("operator new[]_", (void * (*)(size_t)) &Contap_Line::operator new[], "None", py::arg("theSize"));
// cls_Contap_Line.def_static("operator delete[]_", (void (*)(void *)) &Contap_Line::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_Line.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_Line::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_Line.def_static("operator delete_", (void (*)(void *, void *)) &Contap_Line::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_Line.def("SetLineOn2S", (void (Contap_Line::*)(const opencascade::handle<IntSurf_LineOn2S> &)) &Contap_Line::SetLineOn2S, "None", py::arg("L"));
cls_Contap_Line.def("Clear", (void (Contap_Line::*)()) &Contap_Line::Clear, "None");
cls_Contap_Line.def("LineOn2S", (const opencascade::handle<IntSurf_LineOn2S> & (Contap_Line::*)() const) &Contap_Line::LineOn2S, "None");
cls_Contap_Line.def("ResetSeqOfVertex", (void (Contap_Line::*)()) &Contap_Line::ResetSeqOfVertex, "None");
cls_Contap_Line.def("Add", (void (Contap_Line::*)(const IntSurf_PntOn2S &)) &Contap_Line::Add, "None", py::arg("P"));
cls_Contap_Line.def("SetValue", (void (Contap_Line::*)(const gp_Lin &)) &Contap_Line::SetValue, "None", py::arg("L"));
cls_Contap_Line.def("SetValue", (void (Contap_Line::*)(const gp_Circ &)) &Contap_Line::SetValue, "None", py::arg("C"));
cls_Contap_Line.def("SetValue", (void (Contap_Line::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_Line::SetValue, "None", py::arg("A"));
cls_Contap_Line.def("Add", (void (Contap_Line::*)(const Contap_Point &)) &Contap_Line::Add, "None", py::arg("P"));
cls_Contap_Line.def("NbVertex", (Standard_Integer (Contap_Line::*)() const) &Contap_Line::NbVertex, "None");
cls_Contap_Line.def("Vertex", (Contap_Point & (Contap_Line::*)(const Standard_Integer) const) &Contap_Line::Vertex, "None", py::arg("Index"));
cls_Contap_Line.def("TypeContour", (Contap_IType (Contap_Line::*)() const) &Contap_Line::TypeContour, "Returns Contap_Lin for a line, Contap_Circle for a circle, and Contap_Walking for a Walking line, Contap_Restriction for a part of boundarie.");
cls_Contap_Line.def("NbPnts", (Standard_Integer (Contap_Line::*)() const) &Contap_Line::NbPnts, "None");
cls_Contap_Line.def("Point", (const IntSurf_PntOn2S & (Contap_Line::*)(const Standard_Integer) const) &Contap_Line::Point, "None", py::arg("Index"));
cls_Contap_Line.def("Line", (gp_Lin (Contap_Line::*)() const) &Contap_Line::Line, "None");
cls_Contap_Line.def("Circle", (gp_Circ (Contap_Line::*)() const) &Contap_Line::Circle, "None");
cls_Contap_Line.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (Contap_Line::*)() const) &Contap_Line::Arc, "None");
cls_Contap_Line.def("SetTransitionOnS", (void (Contap_Line::*)(const IntSurf_TypeTrans)) &Contap_Line::SetTransitionOnS, "Set The Tansition of the line.", py::arg("T"));
cls_Contap_Line.def("TransitionOnS", (IntSurf_TypeTrans (Contap_Line::*)() const) &Contap_Line::TransitionOnS, "returns IN if at the 'left' of the line, the normale of the surface is oriented to the observator.");

// Enums

}