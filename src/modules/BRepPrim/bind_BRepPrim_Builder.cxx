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
#include <BRep_Builder.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pln.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepPrim_Builder.hxx>

void bind_BRepPrim_Builder(py::module &mod){

py::class_<BRepPrim_Builder, std::unique_ptr<BRepPrim_Builder>> cls_BRepPrim_Builder(mod, "BRepPrim_Builder", "implements the abstract Builder with the BRep Builder");

// Constructors
cls_BRepPrim_Builder.def(py::init<>());
cls_BRepPrim_Builder.def(py::init<const BRep_Builder &>(), py::arg("B"));

// Fields

// Methods
// cls_BRepPrim_Builder.def_static("operator new_", (void * (*)(size_t)) &BRepPrim_Builder::operator new, "None", py::arg("theSize"));
// cls_BRepPrim_Builder.def_static("operator delete_", (void (*)(void *)) &BRepPrim_Builder::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrim_Builder.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrim_Builder::operator new[], "None", py::arg("theSize"));
// cls_BRepPrim_Builder.def_static("operator delete[]_", (void (*)(void *)) &BRepPrim_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrim_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrim_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrim_Builder.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrim_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrim_Builder.def("Builder", (const BRep_Builder & (BRepPrim_Builder::*)() const) &BRepPrim_Builder::Builder, "None");
cls_BRepPrim_Builder.def("MakeShell", (void (BRepPrim_Builder::*)(TopoDS_Shell &) const) &BRepPrim_Builder::MakeShell, "Make a empty Shell.", py::arg("S"));
cls_BRepPrim_Builder.def("MakeFace", (void (BRepPrim_Builder::*)(TopoDS_Face &, const gp_Pln &) const) &BRepPrim_Builder::MakeFace, "Returns in <F> a Face built with the plane equation <P>. Used by all primitives.", py::arg("F"), py::arg("P"));
cls_BRepPrim_Builder.def("MakeWire", (void (BRepPrim_Builder::*)(TopoDS_Wire &) const) &BRepPrim_Builder::MakeWire, "Returns in <W> an empty Wire.", py::arg("W"));
cls_BRepPrim_Builder.def("MakeDegeneratedEdge", (void (BRepPrim_Builder::*)(TopoDS_Edge &) const) &BRepPrim_Builder::MakeDegeneratedEdge, "Returns in <E> a degenerated edge.", py::arg("E"));
cls_BRepPrim_Builder.def("MakeEdge", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const gp_Lin &) const) &BRepPrim_Builder::MakeEdge, "Returns in <E> an Edge built with the line equation <L>.", py::arg("E"), py::arg("L"));
cls_BRepPrim_Builder.def("MakeEdge", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const gp_Circ &) const) &BRepPrim_Builder::MakeEdge, "Returns in <E> an Edge built with the circle equation <C>.", py::arg("E"), py::arg("C"));
cls_BRepPrim_Builder.def("SetPCurve", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Face &, const gp_Lin2d &) const) &BRepPrim_Builder::SetPCurve, "Sets the line <L> to be the curve representing the edge <E> in the parametric space of the surface of <F>.", py::arg("E"), py::arg("F"), py::arg("L"));
cls_BRepPrim_Builder.def("SetPCurve", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Face &, const gp_Lin2d &, const gp_Lin2d &) const) &BRepPrim_Builder::SetPCurve, "Sets the lines <L1,L2> to be the curves representing the edge <E> in the parametric space of the closed surface of <F>.", py::arg("E"), py::arg("F"), py::arg("L1"), py::arg("L2"));
cls_BRepPrim_Builder.def("SetPCurve", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Face &, const gp_Circ2d &) const) &BRepPrim_Builder::SetPCurve, "Sets the circle <C> to be the curve representing the edge <E> in the parametric space of the surface of <F>.", py::arg("E"), py::arg("F"), py::arg("C"));
cls_BRepPrim_Builder.def("MakeVertex", (void (BRepPrim_Builder::*)(TopoDS_Vertex &, const gp_Pnt &) const) &BRepPrim_Builder::MakeVertex, "Returns in <V> a Vertex built with the point <P>.", py::arg("V"), py::arg("P"));
cls_BRepPrim_Builder.def("ReverseFace", (void (BRepPrim_Builder::*)(TopoDS_Face &) const) &BRepPrim_Builder::ReverseFace, "Reverses the Face <F>.", py::arg("F"));
cls_BRepPrim_Builder.def("AddEdgeVertex", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const Standard_Boolean) const) &BRepPrim_Builder::AddEdgeVertex, "Adds the Vertex <V> in the Edge <E>. <P> is the parameter of the vertex on the edge. If direct is False the Vertex is reversed.", py::arg("E"), py::arg("V"), py::arg("P"), py::arg("direct"));
cls_BRepPrim_Builder.def("AddEdgeVertex", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real) const) &BRepPrim_Builder::AddEdgeVertex, "Adds the Vertex <V> in the Edge <E>. <P1,P2> are the parameters of the vertex on the closed edge.", py::arg("E"), py::arg("V"), py::arg("P1"), py::arg("P2"));
cls_BRepPrim_Builder.def("SetParameters", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real) const) &BRepPrim_Builder::SetParameters, "<P1,P2> are the parameters of the vertex on the edge. The edge is a closed curve.", py::arg("E"), py::arg("V"), py::arg("P1"), py::arg("P2"));
cls_BRepPrim_Builder.def("AddWireEdge", (void (BRepPrim_Builder::*)(TopoDS_Wire &, const TopoDS_Edge &, const Standard_Boolean) const) &BRepPrim_Builder::AddWireEdge, "Adds the Edge <E> in the Wire <W>, if direct is False the Edge is reversed.", py::arg("W"), py::arg("E"), py::arg("direct"));
cls_BRepPrim_Builder.def("AddFaceWire", (void (BRepPrim_Builder::*)(TopoDS_Face &, const TopoDS_Wire &) const) &BRepPrim_Builder::AddFaceWire, "Adds the Wire <W> in the Face <F>.", py::arg("F"), py::arg("W"));
cls_BRepPrim_Builder.def("AddShellFace", (void (BRepPrim_Builder::*)(TopoDS_Shell &, const TopoDS_Face &) const) &BRepPrim_Builder::AddShellFace, "Adds the Face <F> in the Shell <Sh>.", py::arg("Sh"), py::arg("F"));
cls_BRepPrim_Builder.def("CompleteEdge", (void (BRepPrim_Builder::*)(TopoDS_Edge &) const) &BRepPrim_Builder::CompleteEdge, "This is called once an edge is completed. It gives the opportunity to perform any post treatment.", py::arg("E"));
cls_BRepPrim_Builder.def("CompleteWire", (void (BRepPrim_Builder::*)(TopoDS_Wire &) const) &BRepPrim_Builder::CompleteWire, "This is called once a wire is completed. It gives the opportunity to perform any post treatment.", py::arg("W"));
cls_BRepPrim_Builder.def("CompleteFace", (void (BRepPrim_Builder::*)(TopoDS_Face &) const) &BRepPrim_Builder::CompleteFace, "This is called once a face is completed. It gives the opportunity to perform any post treatment.", py::arg("F"));
cls_BRepPrim_Builder.def("CompleteShell", (void (BRepPrim_Builder::*)(TopoDS_Shell &) const) &BRepPrim_Builder::CompleteShell, "This is called once a shell is completed. It gives the opportunity to perform any post treatment.", py::arg("S"));

// Enums

}