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
#include <gp_Ax2.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Pnt2d.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepPrim_Builder.hxx>
#include <BRepPrim_OneAxis.hxx>

void bind_BRepPrim_OneAxis(py::module &mod){

py::class_<BRepPrim_OneAxis, std::unique_ptr<BRepPrim_OneAxis>> cls_BRepPrim_OneAxis(mod, "BRepPrim_OneAxis", "Algorithm to build primitives with one axis of revolution.");

// Fields

// Methods
// cls_BRepPrim_OneAxis.def_static("operator new_", (void * (*)(size_t)) &BRepPrim_OneAxis::operator new, "None", py::arg("theSize"));
// cls_BRepPrim_OneAxis.def_static("operator delete_", (void (*)(void *)) &BRepPrim_OneAxis::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrim_OneAxis.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrim_OneAxis::operator new[], "None", py::arg("theSize"));
// cls_BRepPrim_OneAxis.def_static("operator delete[]_", (void (*)(void *)) &BRepPrim_OneAxis::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrim_OneAxis.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrim_OneAxis::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrim_OneAxis.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrim_OneAxis::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrim_OneAxis.def("SetMeridianOffset", [](BRepPrim_OneAxis &self) -> void { return self.SetMeridianOffset(); });
cls_BRepPrim_OneAxis.def("SetMeridianOffset", (void (BRepPrim_OneAxis::*)(const Standard_Real)) &BRepPrim_OneAxis::SetMeridianOffset, "The MeridianOffset is added to the parameters on the meridian curve and to the V values of the pcurves. This is used for the sphere for example, to give a range on the meridian edge which is not VMin, VMax.", py::arg("MeridianOffset"));
cls_BRepPrim_OneAxis.def("Axes", (const gp_Ax2 & (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::Axes, "Returns the Ax2 from <me>.");
cls_BRepPrim_OneAxis.def("Axes", (void (BRepPrim_OneAxis::*)(const gp_Ax2 &)) &BRepPrim_OneAxis::Axes, "None", py::arg("A"));
cls_BRepPrim_OneAxis.def("Angle", (Standard_Real (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::Angle, "None");
cls_BRepPrim_OneAxis.def("Angle", (void (BRepPrim_OneAxis::*)(const Standard_Real)) &BRepPrim_OneAxis::Angle, "None", py::arg("A"));
cls_BRepPrim_OneAxis.def("VMin", (Standard_Real (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::VMin, "None");
cls_BRepPrim_OneAxis.def("VMin", (void (BRepPrim_OneAxis::*)(const Standard_Real)) &BRepPrim_OneAxis::VMin, "None", py::arg("V"));
cls_BRepPrim_OneAxis.def("VMax", (Standard_Real (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::VMax, "None");
cls_BRepPrim_OneAxis.def("VMax", (void (BRepPrim_OneAxis::*)(const Standard_Real)) &BRepPrim_OneAxis::VMax, "None", py::arg("V"));
cls_BRepPrim_OneAxis.def("MakeEmptyLateralFace", (TopoDS_Face (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::MakeEmptyLateralFace, "Returns a face with no edges. The surface is the lateral surface with normals pointing outward. The U parameter is the angle with the origin on the X axis. The V parameter is the parameter of the meridian.");
cls_BRepPrim_OneAxis.def("MakeEmptyMeridianEdge", (TopoDS_Edge (BRepPrim_OneAxis::*)(const Standard_Real) const) &BRepPrim_OneAxis::MakeEmptyMeridianEdge, "Returns an edge with a 3D curve made from the meridian in the XZ plane rotated by <Ang> around the Z-axis. Ang may be 0 or myAngle.", py::arg("Ang"));
cls_BRepPrim_OneAxis.def("SetMeridianPCurve", (void (BRepPrim_OneAxis::*)(TopoDS_Edge &, const TopoDS_Face &) const) &BRepPrim_OneAxis::SetMeridianPCurve, "Sets the parametric curve of the edge <E> in the face <F> to be the 2d representation of the meridian.", py::arg("E"), py::arg("F"));
cls_BRepPrim_OneAxis.def("MeridianValue", (gp_Pnt2d (BRepPrim_OneAxis::*)(const Standard_Real) const) &BRepPrim_OneAxis::MeridianValue, "Returns the meridian point at parameter <V> in the plane XZ.", py::arg("V"));
cls_BRepPrim_OneAxis.def("MeridianOnAxis", (Standard_Boolean (BRepPrim_OneAxis::*)(const Standard_Real) const) &BRepPrim_OneAxis::MeridianOnAxis, "Returns True if the point of parameter <V> on the meridian is on the Axis. Default implementation is Abs(MeridianValue(V).X()) < Precision::Confusion()", py::arg("V"));
cls_BRepPrim_OneAxis.def("MeridianClosed", (Standard_Boolean (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::MeridianClosed, "Returns True if the meridian is closed. Default implementation is MeridianValue(VMin).IsEqual(MeridianValue(VMax), Precision::Confusion())");
cls_BRepPrim_OneAxis.def("VMaxInfinite", (Standard_Boolean (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::VMaxInfinite, "Returns True if VMax is infinite. Default Precision::IsPositiveInfinite(VMax);");
cls_BRepPrim_OneAxis.def("VMinInfinite", (Standard_Boolean (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::VMinInfinite, "Returns True if VMin is infinite. Default Precision::IsNegativeInfinite(VMax);");
cls_BRepPrim_OneAxis.def("HasTop", (Standard_Boolean (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::HasTop, "Returns True if there is a top face.");
cls_BRepPrim_OneAxis.def("HasBottom", (Standard_Boolean (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::HasBottom, "Returns True if there is a bottom face.");
cls_BRepPrim_OneAxis.def("HasSides", (Standard_Boolean (BRepPrim_OneAxis::*)() const) &BRepPrim_OneAxis::HasSides, "Returns True if there are Start and End faces.");
cls_BRepPrim_OneAxis.def("Shell", (const TopoDS_Shell & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::Shell, "Returns the Shell containing all the Faces of the primitive.");
cls_BRepPrim_OneAxis.def("LateralFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::LateralFace, "Returns the lateral Face. It is oriented toward the outside of the primitive.");
cls_BRepPrim_OneAxis.def("TopFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopFace, "Returns the top planar Face. It is Oriented toward the +Z axis (outside).");
cls_BRepPrim_OneAxis.def("BottomFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomFace, "Returns the Bottom planar Face. It is Oriented toward the -Z axis (outside).");
cls_BRepPrim_OneAxis.def("StartFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartFace, "Returns the Face starting the slice, it is oriented toward the exterior of the primitive.");
cls_BRepPrim_OneAxis.def("EndFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndFace, "Returns the Face ending the slice, it is oriented toward the exterior of the primitive.");
cls_BRepPrim_OneAxis.def("LateralWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::LateralWire, "Returns the wire in the lateral face.");
cls_BRepPrim_OneAxis.def("LateralStartWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::LateralStartWire, "Returns the wire in the lateral face with the start edge.");
cls_BRepPrim_OneAxis.def("LateralEndWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::LateralEndWire, "Returns the wire with in lateral face with the end edge.");
cls_BRepPrim_OneAxis.def("TopWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopWire, "Returns the wire in the top face.");
cls_BRepPrim_OneAxis.def("BottomWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomWire, "Returns the wire in the bottom face.");
cls_BRepPrim_OneAxis.def("StartWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartWire, "Returns the wire in the start face.");
cls_BRepPrim_OneAxis.def("AxisStartWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisStartWire, "Returns the wire in the start face with the AxisEdge.");
cls_BRepPrim_OneAxis.def("EndWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndWire, "Returns the Wire in the end face.");
cls_BRepPrim_OneAxis.def("AxisEndWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisEndWire, "Returns the Wire in the end face with the AxisEdge.");
cls_BRepPrim_OneAxis.def("AxisEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisEdge, "Returns the Edge built along the Axis and oriented on +Z of the Axis.");
cls_BRepPrim_OneAxis.def("StartEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartEdge, "Returns the Edge at angle 0.");
cls_BRepPrim_OneAxis.def("EndEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndEdge, "Returns the Edge at angle Angle. If !HasSides() the StartEdge and the EndEdge are the same edge.");
cls_BRepPrim_OneAxis.def("StartTopEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartTopEdge, "Returns the linear Edge between start Face and top Face.");
cls_BRepPrim_OneAxis.def("StartBottomEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartBottomEdge, "Returns the linear Edge between start Face and bottom Face.");
cls_BRepPrim_OneAxis.def("EndTopEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndTopEdge, "Returns the linear Edge between end Face and top Face.");
cls_BRepPrim_OneAxis.def("EndBottomEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndBottomEdge, "Returns the linear Edge between end Face and bottom Face.");
cls_BRepPrim_OneAxis.def("TopEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopEdge, "Returns the edge at VMax. If MeridianClosed() the TopEdge and the BottomEdge are the same edge.");
cls_BRepPrim_OneAxis.def("BottomEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomEdge, "Returns the edge at VMin. If MeridianClosed() the TopEdge and the BottomEdge are the same edge.");
cls_BRepPrim_OneAxis.def("AxisTopVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisTopVertex, "Returns the Vertex at the Top altitude on the axis.");
cls_BRepPrim_OneAxis.def("AxisBottomVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisBottomVertex, "Returns the Vertex at the Bottom altitude on the axis.");
cls_BRepPrim_OneAxis.def("TopStartVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopStartVertex, "Returns the vertex (0,VMax)");
cls_BRepPrim_OneAxis.def("TopEndVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopEndVertex, "Returns the vertex (angle,VMax)");
cls_BRepPrim_OneAxis.def("BottomStartVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomStartVertex, "Returns the vertex (0,VMin)");
cls_BRepPrim_OneAxis.def("BottomEndVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomEndVertex, "Returns the vertex (angle,VMax)");

// Enums

}