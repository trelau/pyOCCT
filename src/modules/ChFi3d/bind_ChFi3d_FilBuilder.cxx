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
#include <ChFi3d_Builder.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <ChFi3d_FilletShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <Law_Function.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_XY.hxx>
#include <ChFiDS_SecHArray1.hxx>
#include <ChFiDS_SurfData.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <ChFiDS_Spine.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <math_Vector.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <ChFiDS_SequenceOfSurfData.hxx>
#include <BRepBlend_Line.hxx>
#include <ChFiDS_Stripe.hxx>
#include <ChFiDS_ListOfStripe.hxx>
#include <BlendFunc_SectionShape.hxx>
#include <ChFi3d_FilBuilder.hxx>

void bind_ChFi3d_FilBuilder(py::module &mod){

py::class_<ChFi3d_FilBuilder, std::unique_ptr<ChFi3d_FilBuilder>, ChFi3d_Builder> cls_ChFi3d_FilBuilder(mod, "ChFi3d_FilBuilder", "Tool of construction of fillets 3d on edges (on a solid).");

// Constructors
cls_ChFi3d_FilBuilder.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_ChFi3d_FilBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape>(), py::arg("S"), py::arg("FShape"));
cls_ChFi3d_FilBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape, const Standard_Real>(), py::arg("S"), py::arg("FShape"), py::arg("Ta"));

// Fields

// Methods
// cls_ChFi3d_FilBuilder.def_static("operator new_", (void * (*)(size_t)) &ChFi3d_FilBuilder::operator new, "None", py::arg("theSize"));
// cls_ChFi3d_FilBuilder.def_static("operator delete_", (void (*)(void *)) &ChFi3d_FilBuilder::operator delete, "None", py::arg("theAddress"));
// cls_ChFi3d_FilBuilder.def_static("operator new[]_", (void * (*)(size_t)) &ChFi3d_FilBuilder::operator new[], "None", py::arg("theSize"));
// cls_ChFi3d_FilBuilder.def_static("operator delete[]_", (void (*)(void *)) &ChFi3d_FilBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_ChFi3d_FilBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &ChFi3d_FilBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFi3d_FilBuilder.def_static("operator delete_", (void (*)(void *, void *)) &ChFi3d_FilBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFi3d_FilBuilder.def("SetFilletShape", (void (ChFi3d_FilBuilder::*)(const ChFi3d_FilletShape)) &ChFi3d_FilBuilder::SetFilletShape, "Sets the type of fillet surface.", py::arg("FShape"));
cls_ChFi3d_FilBuilder.def("GetFilletShape", (ChFi3d_FilletShape (ChFi3d_FilBuilder::*)() const) &ChFi3d_FilBuilder::GetFilletShape, "Returns the type of fillet surface.");
cls_ChFi3d_FilBuilder.def("Add", (void (ChFi3d_FilBuilder::*)(const TopoDS_Edge &)) &ChFi3d_FilBuilder::Add, "initialisation of a contour with the first edge (the following are found by propagation). Attention, you need to start with SetRadius.", py::arg("E"));
cls_ChFi3d_FilBuilder.def("Add", (void (ChFi3d_FilBuilder::*)(const Standard_Real, const TopoDS_Edge &)) &ChFi3d_FilBuilder::Add, "initialisation of the constant vector the corresponding 1st edge.", py::arg("Radius"), py::arg("E"));
cls_ChFi3d_FilBuilder.def("SetRadius", (void (ChFi3d_FilBuilder::*)(const opencascade::handle<Law_Function> &, const Standard_Integer, const Standard_Integer)) &ChFi3d_FilBuilder::SetRadius, "Set the radius of the contour of index IC.", py::arg("C"), py::arg("IC"), py::arg("IinC"));
cls_ChFi3d_FilBuilder.def("IsConstant", (Standard_Boolean (ChFi3d_FilBuilder::*)(const Standard_Integer)) &ChFi3d_FilBuilder::IsConstant, "Returns true the contour is flaged as edge constant.", py::arg("IC"));
cls_ChFi3d_FilBuilder.def("Radius", (Standard_Real (ChFi3d_FilBuilder::*)(const Standard_Integer)) &ChFi3d_FilBuilder::Radius, "Returns the vector if the contour is flagged as edge constant.", py::arg("IC"));
cls_ChFi3d_FilBuilder.def("ResetContour", (void (ChFi3d_FilBuilder::*)(const Standard_Integer)) &ChFi3d_FilBuilder::ResetContour, "Reset all vectors of contour IC.", py::arg("IC"));
cls_ChFi3d_FilBuilder.def("SetRadius", (void (ChFi3d_FilBuilder::*)(const Standard_Real, const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::SetRadius, "Set a constant on edge E of the contour of index IC. Since then E is flagged as constant.", py::arg("Radius"), py::arg("IC"), py::arg("E"));
cls_ChFi3d_FilBuilder.def("UnSet", (void (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::UnSet, "Extracts the flag constant and the vector of edge E.", py::arg("IC"), py::arg("E"));
cls_ChFi3d_FilBuilder.def("SetRadius", (void (ChFi3d_FilBuilder::*)(const Standard_Real, const Standard_Integer, const TopoDS_Vertex &)) &ChFi3d_FilBuilder::SetRadius, "Set a vector on vertex V of the contour of index IC.", py::arg("Radius"), py::arg("IC"), py::arg("V"));
cls_ChFi3d_FilBuilder.def("UnSet", (void (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Vertex &)) &ChFi3d_FilBuilder::UnSet, "Extracts the vector of the vertex V.", py::arg("IC"), py::arg("V"));
cls_ChFi3d_FilBuilder.def("SetRadius", (void (ChFi3d_FilBuilder::*)(const gp_XY &, const Standard_Integer, const Standard_Integer)) &ChFi3d_FilBuilder::SetRadius, "Set a vertex on the point of parametre U in the edge IinC of the contour of index IC", py::arg("UandR"), py::arg("IC"), py::arg("IinC"));
cls_ChFi3d_FilBuilder.def("IsConstant", (Standard_Boolean (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::IsConstant, "Returns true E is flagged as edge constant.", py::arg("IC"), py::arg("E"));
cls_ChFi3d_FilBuilder.def("Radius", (Standard_Real (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::Radius, "Returns the vector if E is flagged as edge constant.", py::arg("IC"), py::arg("E"));
cls_ChFi3d_FilBuilder.def("GetBounds", [](ChFi3d_FilBuilder &self, const Standard_Integer IC, const TopoDS_Edge & E, Standard_Real & First, Standard_Real & Last){ Standard_Boolean rv = self.GetBounds(IC, E, First, Last); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, First, Last); }, "Returns in First and Last les extremities of the part of variable vector framing E, returns False if E is flagged as edge constant.", py::arg("IC"), py::arg("E"), py::arg("First"), py::arg("Last"));
cls_ChFi3d_FilBuilder.def("GetLaw", (opencascade::handle<Law_Function> (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::GetLaw, "Returns the rule of elementary evolution of the part to variable vector framing E, returns a rule zero if E is flagged as edge constant.", py::arg("IC"), py::arg("E"));
cls_ChFi3d_FilBuilder.def("SetLaw", (void (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &, const opencascade::handle<Law_Function> &)) &ChFi3d_FilBuilder::SetLaw, "Sets the rule of elementary evolution of the part to variable vector framing E.", py::arg("IC"), py::arg("E"), py::arg("L"));
cls_ChFi3d_FilBuilder.def("Simulate", (void (ChFi3d_FilBuilder::*)(const Standard_Integer)) &ChFi3d_FilBuilder::Simulate, "None", py::arg("IC"));
cls_ChFi3d_FilBuilder.def("NbSurf", (Standard_Integer (ChFi3d_FilBuilder::*)(const Standard_Integer) const) &ChFi3d_FilBuilder::NbSurf, "None", py::arg("IC"));
cls_ChFi3d_FilBuilder.def("Sect", (opencascade::handle<ChFiDS_SecHArray1> (ChFi3d_FilBuilder::*)(const Standard_Integer, const Standard_Integer) const) &ChFi3d_FilBuilder::Sect, "None", py::arg("IC"), py::arg("IS"));

// Enums

}