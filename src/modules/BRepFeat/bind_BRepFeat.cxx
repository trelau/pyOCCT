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
#include <TColgp_SequenceOfPnt.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Face.hxx>
#include <BRepTopAdaptor_FClass2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <TopoDS_Solid.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_OStream.hxx>
#include <BRepFeat_StatusError.hxx>
#include <BRepFeat_Builder.hxx>
#include <BRepFeat_MakeCylindricalHole.hxx>
#include <BRepFeat_SplitShape.hxx>
#include <BRepFeat_Form.hxx>
#include <BRepFeat_RibSlot.hxx>
#include <BRepFeat_MakePrism.hxx>
#include <BRepFeat_MakeRevol.hxx>
#include <BRepFeat_MakePipe.hxx>
#include <BRepFeat_Gluer.hxx>
#include <BRepFeat_MakeDPrism.hxx>
#include <BRepFeat_MakeLinearForm.hxx>
#include <BRepFeat_MakeRevolutionForm.hxx>
#include <BRepFeat.hxx>

void bind_BRepFeat(py::module &mod){

py::class_<BRepFeat> cls_BRepFeat(mod, "BRepFeat", "BRepFeat is necessary for the creation and manipulation of both form and mechanical features in a Boundary Representation framework. Form features can be depressions or protrusions and include the following types: - Cylinder - Draft Prism - Prism - Revolved feature - Pipe Depending on whether you wish to make a depression or a protrusion, you can choose your operation type between the following: - removing matter (a Boolean cut: Fuse setting 0) - adding matter (Boolean fusion: Fuse setting 1) The semantics of form feature creation is based on the construction of shapes: - for a certain length in a certain direction - up to a limiting face - from a limiting face at a height - above and/or below a plane The shape defining the construction of a feature can be either a supporting edge or a concerned area of a face. In case of supporting edge, this contour can be attached to a face of the basis shape by binding. When the contour is bound to this face, the information that the contour will slide on the face becomes available to the relevant class methods. In case of the concerned area of a face, you could, for example, cut it out and move it at a different height, which will define the limiting face of a protrusion or depression. Topological definition with local operations of this sort makes calculations simpler and faster than a global operation. The latter would entail a second phase of removing unwanted matter to get the same result. Mechanical features include ribs - protrusions - and grooves (or slots) - depressions along planar (linear) surfaces or revolution surfaces. The semantics of mechanical features is based on giving thickness to a contour. This thickness can either be unilateral - on one side of the contour - or bilateral - on both sides. As in the semantics of form features, the thickness is defined by construction of shapes in specific contexts. However, in case of mechanical features, development contexts differ. Here they include extrusion: - to a limiting face of the basis shape - to or from a limiting plane - to a height.");

// Constructors

// Fields

// Methods
// cls_BRepFeat.def_static("operator new_", (void * (*)(size_t)) &BRepFeat::operator new, "None", py::arg("theSize"));
// cls_BRepFeat.def_static("operator delete_", (void (*)(void *)) &BRepFeat::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat.def_static("SampleEdges_", (void (*)(const TopoDS_Shape &, TColgp_SequenceOfPnt &)) &BRepFeat::SampleEdges, "None", py::arg("S"), py::arg("Pt"));
cls_BRepFeat.def_static("Barycenter_", (void (*)(const TopoDS_Shape &, gp_Pnt &)) &BRepFeat::Barycenter, "None", py::arg("S"), py::arg("Pt"));
cls_BRepFeat.def_static("ParametricBarycenter_", (Standard_Real (*)(const TopoDS_Shape &, const opencascade::handle<Geom_Curve> &)) &BRepFeat::ParametricBarycenter, "None", py::arg("S"), py::arg("C"));
cls_BRepFeat.def_static("ParametricMinMax_", [](const TopoDS_Shape & S, const opencascade::handle<Geom_Curve> & C, Standard_Real & prmin, Standard_Real & prmax, Standard_Real & prbmin, Standard_Real & prbmax, Standard_Boolean & flag, const Standard_Boolean Ori){ BRepFeat::ParametricMinMax(S, C, prmin, prmax, prbmin, prbmax, flag, Ori); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Boolean &>(prmin, prmax, prbmin, prbmax, flag); }, "Ori = True taking account the orientation", py::arg("S"), py::arg("C"), py::arg("prmin"), py::arg("prmax"), py::arg("prbmin"), py::arg("prbmax"), py::arg("flag"), py::arg("Ori"));
cls_BRepFeat.def_static("IsInside_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &)) &BRepFeat::IsInside, "None", py::arg("F1"), py::arg("F2"));
// cls_BRepFeat.def_static("IsInOut_", (Standard_Boolean (*)(const BRepTopAdaptor_FClass2d &, const Geom2dAdaptor_Curve &)) &BRepFeat::IsInOut, "None", py::arg("FC"), py::arg("AC"));
cls_BRepFeat.def_static("FaceUntil_", (void (*)(const TopoDS_Shape &, TopoDS_Face &)) &BRepFeat::FaceUntil, "None", py::arg("S"), py::arg("F"));
cls_BRepFeat.def_static("Tool_", (TopoDS_Solid (*)(const TopoDS_Shape &, const TopoDS_Face &, const TopAbs_Orientation)) &BRepFeat::Tool, "None", py::arg("SRef"), py::arg("Fac"), py::arg("Orf"));
cls_BRepFeat.def_static("Print_", (Standard_OStream & (*)(const BRepFeat_StatusError, Standard_OStream &)) &BRepFeat::Print, "Prints the Error description of the State <St> as a String on the Stream <S> and returns <S>.", py::arg("SE"), py::arg("S"));

// Enums

}