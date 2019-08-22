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
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Ax3.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <BRepFill_Generator.hxx>
#include <BRepFill_SectionLaw.hxx>
#include <BRepFill_ShapeLaw.hxx>
#include <BRepFill_NSections.hxx>
#include <BRepFill_Draft.hxx>
#include <BRepFill_LocationLaw.hxx>
#include <BRepFill_DraftLaw.hxx>
#include <BRepFill_Edge3DLaw.hxx>
#include <BRepFill_EdgeOnSurfLaw.hxx>
#include <BRepFill_ACRLaw.hxx>
#include <BRepFill_Pipe.hxx>
#include <BRepFill_PipeShell.hxx>
#include <BRepFill_Evolved.hxx>
#include <BRepFill_Sweep.hxx>
#include <BRepFill_CompatibleWires.hxx>
#include <BRepFill_OffsetWire.hxx>
#include <BRepFill_OffsetAncestors.hxx>
#include <BRepFill_ApproxSeewing.hxx>
#include <BRepFill_ComputeCLine.hxx>
#include <BRepFill_TrimSurfaceTool.hxx>
#include <BRepFill_TrimEdgeTool.hxx>
#include <BRepFill_SectionPlacement.hxx>
#include <BRepFill_Section.hxx>
#include <BRepFill_TrimShellCorner.hxx>
#include <BRepFill_CurveConstraint.hxx>
#include <BRepFill_Filling.hxx>
#include <BRepFill_FaceAndOrder.hxx>
#include <BRepFill_EdgeFaceAndOrder.hxx>
#include <BRepFill.hxx>

void bind_BRepFill(py::module &mod){

py::class_<BRepFill> cls_BRepFill(mod, "BRepFill", "None");

// Constructors

// Fields

// Methods
// cls_BRepFill.def_static("operator new_", (void * (*)(size_t)) &BRepFill::operator new, "None", py::arg("theSize"));
// cls_BRepFill.def_static("operator delete_", (void (*)(void *)) &BRepFill::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill::operator new[], "None", py::arg("theSize"));
// cls_BRepFill.def_static("operator delete[]_", (void (*)(void *)) &BRepFill::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill.def_static("Face_", (TopoDS_Face (*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepFill::Face, "Computes a ruled surface between two edges.", py::arg("Edge1"), py::arg("Edge2"));
cls_BRepFill.def_static("Shell_", (TopoDS_Shell (*)(const TopoDS_Wire &, const TopoDS_Wire &)) &BRepFill::Shell, "Computes a ruled surface between two wires. The wires must have the same number of edges.", py::arg("Wire1"), py::arg("Wire2"));
cls_BRepFill.def_static("Axe_", [](const TopoDS_Shape & Spine, const TopoDS_Wire & Profile, gp_Ax3 & AxeProf, Standard_Boolean & ProfOnSpine, const Standard_Real Tol){ BRepFill::Axe(Spine, Profile, AxeProf, ProfOnSpine, Tol); return ProfOnSpine; }, "Computes <AxeProf> as Follow. <Location> is the Position of the nearest vertex V of <Profile> to <Spine>.<XDirection> is confused with the tangent to <Spine> at the projected point of V on the Spine. <Direction> is normal to <Spine>. <Spine> is a plane wire or a plane face.", py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("ProfOnSpine"), py::arg("Tol"));
cls_BRepFill.def_static("ComputeACR_", (void (*)(const TopoDS_Wire &, TColStd_Array1OfReal &)) &BRepFill::ComputeACR, "Compute ACR on a wire", py::arg("wire"), py::arg("ACR"));
cls_BRepFill.def_static("InsertACR_", (TopoDS_Wire (*)(const TopoDS_Wire &, const TColStd_Array1OfReal &, const Standard_Real)) &BRepFill::InsertACR, "Insert ACR on a wire", py::arg("wire"), py::arg("ACRcuts"), py::arg("prec"));

// Enums

}