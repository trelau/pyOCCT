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
#include <BRepPrimAPI_MakeSweep.hxx>
#include <Standard.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2.hxx>
#include <gp_Dir.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepFill_TypeOfContact.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <Law_Function.hxx>
#include <BRepBuilderAPI_PipeError.hxx>
#include <BRepBuilderAPI_TransitionMode.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepFill_PipeShell.hxx>
#include <BRepOffsetAPI_MakePipeShell.hxx>

void bind_BRepOffsetAPI_MakePipeShell(py::module &mod){

py::class_<BRepOffsetAPI_MakePipeShell, std::unique_ptr<BRepOffsetAPI_MakePipeShell>, BRepPrimAPI_MakeSweep> cls_BRepOffsetAPI_MakePipeShell(mod, "BRepOffsetAPI_MakePipeShell", "This class provides for a framework to construct a shell or a solid along a spine consisting in a wire. To produce a solid, the initial wire must be closed. Two approaches are used: - definition by section - by a section and a scaling law - by addition of successive intermediary sections - definition by sweep mode. - pseudo-Frenet - constant - binormal constant - normal defined by a surface support - normal defined by a guiding contour. The two global approaches can also be combined. You can also close the surface later in order to form a solid. Warning: some limitations exist -- Mode with auxilary spine is incompatible with hometetic laws -- Mode with auxilary spine and keep contact produce only CO surface.");

// Constructors
cls_BRepOffsetAPI_MakePipeShell.def(py::init<const TopoDS_Wire &>(), py::arg("Spine"));

// Fields

// Methods
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakePipeShell::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakePipeShell::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakePipeShell::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakePipeShell::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakePipeShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakePipeShell::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", [](BRepOffsetAPI_MakePipeShell &self) -> void { return self.SetMode(); });
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets a Frenet or a CorrectedFrenet trihedron to perform the sweeping If IsFrenet is false, a corrected Frenet trihedron is used.", py::arg("IsFrenet"));
cls_BRepOffsetAPI_MakePipeShell.def("SetDiscreteMode", (void (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::SetDiscreteMode, "Sets a Discrete trihedron to perform the sweeping");
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (void (BRepOffsetAPI_MakePipeShell::*)(const gp_Ax2 &)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets a fixed trihedron to perform the sweeping all sections will be parallel.", py::arg("Axe"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (void (BRepOffsetAPI_MakePipeShell::*)(const gp_Dir &)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets a fixed BiNormal direction to perform the -- sweeping. Angular relations beetween the section(s) and <BiNormal> will be constant", py::arg("BiNormal"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (Standard_Boolean (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets support to the spine to define the BiNormal of the trihedron, like the normal to the surfaces. Warning: To be effective, Each edge of the <spine> must have an representaion on one face of<SpineSupport>", py::arg("SpineSupport"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Wire & a0, const Standard_Boolean a1) -> void { return self.SetMode(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Wire &, const Standard_Boolean, const BRepFill_TypeOfContact)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets an auxiliary spine to define the Normal For each Point of the Spine P, an Point Q is evalued on <AuxiliarySpine> If <CurvilinearEquivalence> Q split <AuxiliarySpine> with the same length ratio than P split <Spline>. Else the plan define by P and the tangent to the <Spine> intersect <AuxiliarySpine> in Q. If <KeepContact> equals BRepFill_NoContact: The Normal is defined by the vector PQ. If <KeepContact> equals BRepFill_Contact: The Normal is defined to achieve that the sweeped section is in contact to the auxiliarySpine. The width of section is constant all along the path. In other words, the auxiliary spine lies on the swept surface, but not necessarily is a boundary of this surface. However, the auxiliary spine has to be close enough to the main spine to provide intersection with any section all along the path. If <KeepContact> equals BRepFill_ContactOnBorder: The auxiliary spine becomes a boundary of the swept surface and the width of section varies along the path. Give section to sweep. Possibilities are : - Give one or sevral section - Give one profile and an homotetic law. - Automatic compute of correspondance beetween spine, and section on the sweeped shape - correspondance beetween spine, and section on the sweeped shape defined by a vertex of the spine", py::arg("AuxiliarySpine"), py::arg("CurvilinearEquivalence"), py::arg("KeepContact"));
cls_BRepOffsetAPI_MakePipeShell.def("Add", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0) -> void { return self.Add(a0); });
cls_BRepOffsetAPI_MakePipeShell.def("Add", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Add(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("Add", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::Add, "Adds the section Profile to this framework. First and last sections may be punctual, so the shape Profile may be both wire and vertex. Correspondent point on spine is computed automatically. If WithContact is true, the section is translated to be in contact with the spine. If WithCorrection is true, the section is rotated to be orthogonal to the spine?s tangent in the correspondent point. This option has no sense if the section is punctual (Profile is of type TopoDS_Vertex).", py::arg("Profile"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepOffsetAPI_MakePipeShell.def("Add", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const TopoDS_Vertex & a1) -> void { return self.Add(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("Add", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const TopoDS_Vertex & a1, const Standard_Boolean a2) -> void { return self.Add(a0, a1, a2); });
cls_BRepOffsetAPI_MakePipeShell.def("Add", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::Add, "Adds the section Profile to this framework. Correspondent point on the spine is given by Location. Warning: To be effective, it is not recommended to combine methods Add and SetLaw.", py::arg("Profile"), py::arg("Location"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1) -> void { return self.SetLaw(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const Standard_Boolean a2) -> void { return self.SetLaw(a0, a1, a2); });
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &, const opencascade::handle<Law_Function> &, const Standard_Boolean, const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::SetLaw, "Sets the evolution law defined by the wire Profile with its position (Location, WithContact, WithCorrection are the same options as in methods Add) and a homotetic law defined by the function L. Warning: To be effective, it is not recommended to combine methods Add and SetLaw.", py::arg("Profile"), py::arg("L"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const TopoDS_Vertex & a2) -> void { return self.SetLaw(a0, a1, a2); });
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const TopoDS_Vertex & a2, const Standard_Boolean a3) -> void { return self.SetLaw(a0, a1, a2, a3); });
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &, const opencascade::handle<Law_Function> &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::SetLaw, "Sets the evolution law defined by the wire Profile with its position (Location, WithContact, WithCorrection are the same options as in methods Add) and a homotetic law defined by the function L. Warning: To be effective, it is not recommended to combine methods Add and SetLaw.", py::arg("Profile"), py::arg("L"), py::arg("Location"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepOffsetAPI_MakePipeShell.def("Delete", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakePipeShell::Delete, "Removes the section Profile from this framework.", py::arg("Profile"));
cls_BRepOffsetAPI_MakePipeShell.def("IsReady", (Standard_Boolean (BRepOffsetAPI_MakePipeShell::*)() const) &BRepOffsetAPI_MakePipeShell::IsReady, "Returns true if this tool object is ready to build the shape, i.e. has a definition for the wire section Profile.");
cls_BRepOffsetAPI_MakePipeShell.def("GetStatus", (BRepBuilderAPI_PipeError (BRepOffsetAPI_MakePipeShell::*)() const) &BRepOffsetAPI_MakePipeShell::GetStatus, "Get a status, when Simulate or Build failed. It can be BRepBuilderAPI_PipeDone, BRepBuilderAPI_PipeNotDone, BRepBuilderAPI_PlaneNotIntersectGuide, BRepBuilderAPI_ImpossibleContact.");
cls_BRepOffsetAPI_MakePipeShell.def("SetTolerance", [](BRepOffsetAPI_MakePipeShell &self) -> void { return self.SetTolerance(); });
cls_BRepOffsetAPI_MakePipeShell.def("SetTolerance", [](BRepOffsetAPI_MakePipeShell &self, const Standard_Real a0) -> void { return self.SetTolerance(a0); });
cls_BRepOffsetAPI_MakePipeShell.def("SetTolerance", [](BRepOffsetAPI_MakePipeShell &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("SetTolerance", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &BRepOffsetAPI_MakePipeShell::SetTolerance, "Sets the following tolerance values - 3D tolerance Tol3d - boundary tolerance BoundTol - angular tolerance TolAngular.", py::arg("Tol3d"), py::arg("BoundTol"), py::arg("TolAngular"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMaxDegree", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Integer)) &BRepOffsetAPI_MakePipeShell::SetMaxDegree, "Define the maximum V degree of resulting surface", py::arg("NewMaxDegree"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMaxSegments", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Integer)) &BRepOffsetAPI_MakePipeShell::SetMaxSegments, "Define the maximum number of spans in V-direction on resulting surface", py::arg("NewMaxSegments"));
cls_BRepOffsetAPI_MakePipeShell.def("SetForceApproxC1", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::SetForceApproxC1, "Set the flag that indicates attempt to approximate a C1-continuous surface if a swept surface proved to be C0.", py::arg("ForceApproxC1"));
cls_BRepOffsetAPI_MakePipeShell.def("SetTransitionMode", [](BRepOffsetAPI_MakePipeShell &self) -> void { return self.SetTransitionMode(); });
cls_BRepOffsetAPI_MakePipeShell.def("SetTransitionMode", (void (BRepOffsetAPI_MakePipeShell::*)(const BRepBuilderAPI_TransitionMode)) &BRepOffsetAPI_MakePipeShell::SetTransitionMode, "Sets the transition mode to manage discontinuities on the swept shape caused by fractures on the spine. The transition mode can be BRepBuilderAPI_Transformed (default value), BRepBuilderAPI_RightCorner, BRepBuilderAPI_RoundCorner: - RepBuilderAPI_Transformed: discontinuities are treated by modification of the sweeping mode. The pipe is 'transformed' at the fractures of the spine. This mode assumes building a self-intersected shell. - BRepBuilderAPI_RightCorner: discontinuities are treated like right corner. Two pieces of the pipe corresponding to two adjacent segments of the spine are extended and intersected at a fracture of the spine. - BRepBuilderAPI_RoundCorner: discontinuities are treated like round corner. The corner is treated as rotation of the profile around an axis which passes through the point of the spine?s fracture. This axis is based on cross product of directions tangent to the adjacent segments of the spine at their common point. Warnings The mode BRepBuilderAPI_RightCorner provides a valid result if intersection of two pieces of the pipe (corresponding to two adjacent segments of the spine) in the neighborhood of the spine?s fracture is connected and planar. This condition can be violated if the spine is non-linear in some neighborhood of the fracture or if the profile was set with a scaling law. The last mode, BRepBuilderAPI_RoundCorner, will assuredly provide a good result only if a profile was set with option WithCorrection = True, i.e. it is strictly orthogonal to the spine.", py::arg("Mode"));
cls_BRepOffsetAPI_MakePipeShell.def("Simulate", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Integer, TopTools_ListOfShape &)) &BRepOffsetAPI_MakePipeShell::Simulate, "Simulates the resulting shape by calculating its cross-sections. The spine is devided by this cross-sections into (NumberOfSection - 1) equal parts, the number of cross-sections is NumberOfSection. The cross-sections are wires and they are returned in the list Result. This gives a rapid preview of the resulting shape, which will be obtained using the settings you have provided. Raises NotDone if <me> it is not Ready", py::arg("NumberOfSection"), py::arg("Result"));
cls_BRepOffsetAPI_MakePipeShell.def("Build", (void (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepOffsetAPI_MakePipeShell.def("MakeSolid", (Standard_Boolean (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::MakeSolid, "Transforms the sweeping Shell in Solid. If a propfile is not closed returns False");
cls_BRepOffsetAPI_MakePipeShell.def("FirstShape", (TopoDS_Shape (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::FirstShape, "Returns the TopoDS Shape of the bottom of the sweep.");
cls_BRepOffsetAPI_MakePipeShell.def("LastShape", (TopoDS_Shape (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::LastShape, "Returns the TopoDS Shape of the top of the sweep.");
cls_BRepOffsetAPI_MakePipeShell.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakePipeShell::Generated, "Returns a list of new shapes generated from the shape S by the shell-generating algorithm. This function is redefined from BRepOffsetAPI_MakeShape::Generated. S can be an edge or a vertex of a given Profile (see methods Add).", py::arg("S"));
cls_BRepOffsetAPI_MakePipeShell.def("ErrorOnSurface", (Standard_Real (BRepOffsetAPI_MakePipeShell::*)() const) &BRepOffsetAPI_MakePipeShell::ErrorOnSurface, "None");
cls_BRepOffsetAPI_MakePipeShell.def("Profiles", (void (BRepOffsetAPI_MakePipeShell::*)(TopTools_ListOfShape &)) &BRepOffsetAPI_MakePipeShell::Profiles, "Returns the list of original profiles", py::arg("theProfiles"));

// Enums

}