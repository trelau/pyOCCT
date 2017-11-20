#include <pyOCCT_Common.hpp>

#include <Hatch_LineForm.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Hatch_Line.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Pnt2d.hxx>
#include <Hatch_Hatcher.hxx>
#include <Hatch_Parameter.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Hatch_SequenceOfParameter.hxx>
#include <Hatch_SequenceOfLine.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(Hatch, mod) {

	// IMPORT
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_LineForm.hxx
	py::enum_<Hatch_LineForm>(mod, "Hatch_LineForm", "Form of a trimmed line")
		.value("Hatch_XLINE", Hatch_LineForm::Hatch_XLINE)
		.value("Hatch_YLINE", Hatch_LineForm::Hatch_YLINE)
		.value("Hatch_ANYLINE", Hatch_LineForm::Hatch_ANYLINE)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_Line.hxx
	py::class_<Hatch_Line, std::unique_ptr<Hatch_Line, Deleter<Hatch_Line>>> cls_Hatch_Line(mod, "Hatch_Line", "Stores a Line in the Hatcher. Represented by :");
	cls_Hatch_Line.def(py::init<>());
	cls_Hatch_Line.def(py::init<const gp_Lin2d &, const Hatch_LineForm>(), py::arg("L"), py::arg("T"));
	cls_Hatch_Line.def("AddIntersection", (void (Hatch_Line::*)(const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Real, const Standard_Real)) &Hatch_Line::AddIntersection, "Insert a new intersection in the sorted list.", py::arg("Par1"), py::arg("Start"), py::arg("Index"), py::arg("Par2"), py::arg("theToler"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_Hatcher.hxx
	py::class_<Hatch_Hatcher, std::unique_ptr<Hatch_Hatcher, Deleter<Hatch_Hatcher>>> cls_Hatch_Hatcher(mod, "Hatch_Hatcher", "The Hatcher is an algorithm to compute cross hatchings in a 2d plane. It is mainly dedicated to display purpose.");
	cls_Hatch_Hatcher.def(py::init<const Standard_Real>(), py::arg("Tol"));
	cls_Hatch_Hatcher.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("Tol"), py::arg("Oriented"));
	cls_Hatch_Hatcher.def("Tolerance", (void (Hatch_Hatcher::*)(const Standard_Real)) &Hatch_Hatcher::Tolerance, "None", py::arg("Tol"));
	cls_Hatch_Hatcher.def("Tolerance", (Standard_Real (Hatch_Hatcher::*)() const ) &Hatch_Hatcher::Tolerance, "None");
	cls_Hatch_Hatcher.def("AddLine", [](Hatch_Hatcher &self, const gp_Lin2d & a0) -> void { return self.AddLine(a0); }, py::arg("L"));
	cls_Hatch_Hatcher.def("AddLine", (void (Hatch_Hatcher::*)(const gp_Lin2d &, const Hatch_LineForm)) &Hatch_Hatcher::AddLine, "Add a line <L> to be trimmed. <T> the type is only kept from information. It is not used in the computation.", py::arg("L"), py::arg("T"));
	cls_Hatch_Hatcher.def("AddLine", (void (Hatch_Hatcher::*)(const gp_Dir2d &, const Standard_Real)) &Hatch_Hatcher::AddLine, "Add an infinite line on direction <D> at distance <Dist> from the origin to be trimmed. <Dist> may be negative.", py::arg("D"), py::arg("Dist"));
	cls_Hatch_Hatcher.def("AddXLine", (void (Hatch_Hatcher::*)(const Standard_Real)) &Hatch_Hatcher::AddXLine, "Add an infinite line parallel to the Y-axis at abciss <X>.", py::arg("X"));
	cls_Hatch_Hatcher.def("AddYLine", (void (Hatch_Hatcher::*)(const Standard_Real)) &Hatch_Hatcher::AddYLine, "Add an infinite line parallel to the X-axis at ordinate <Y>.", py::arg("Y"));
	cls_Hatch_Hatcher.def("Trim", [](Hatch_Hatcher &self, const gp_Lin2d & a0) -> void { return self.Trim(a0); }, py::arg("L"));
	cls_Hatch_Hatcher.def("Trim", (void (Hatch_Hatcher::*)(const gp_Lin2d &, const Standard_Integer)) &Hatch_Hatcher::Trim, "Trims the lines at intersections with <L>.", py::arg("L"), py::arg("Index"));
	cls_Hatch_Hatcher.def("Trim", [](Hatch_Hatcher &self, const gp_Lin2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Trim(a0, a1, a2); }, py::arg("L"), py::arg("Start"), py::arg("End"));
	cls_Hatch_Hatcher.def("Trim", (void (Hatch_Hatcher::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Integer)) &Hatch_Hatcher::Trim, "Trims the lines at intersections with <L> in the parameter range <Start>, <End>", py::arg("L"), py::arg("Start"), py::arg("End"), py::arg("Index"));
	cls_Hatch_Hatcher.def("Trim", [](Hatch_Hatcher &self, const gp_Pnt2d & a0, const gp_Pnt2d & a1) -> void { return self.Trim(a0, a1); }, py::arg("P1"), py::arg("P2"));
	cls_Hatch_Hatcher.def("Trim", (void (Hatch_Hatcher::*)(const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Integer)) &Hatch_Hatcher::Trim, "Trims the line at intersection with the oriented segment P1,P2.", py::arg("P1"), py::arg("P2"), py::arg("Index"));
	cls_Hatch_Hatcher.def("NbIntervals", (Standard_Integer (Hatch_Hatcher::*)() const ) &Hatch_Hatcher::NbIntervals, "Returns the total number of intervals on all the lines.");
	cls_Hatch_Hatcher.def("NbLines", (Standard_Integer (Hatch_Hatcher::*)() const ) &Hatch_Hatcher::NbLines, "Returns the number of lines.");
	cls_Hatch_Hatcher.def("Line", (const gp_Lin2d & (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::Line, "Returns the line of index <I>.", py::arg("I"));
	cls_Hatch_Hatcher.def("LineForm", (Hatch_LineForm (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::LineForm, "Returns the type of the line of index <I>.", py::arg("I"));
	cls_Hatch_Hatcher.def("IsXLine", (Standard_Boolean (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::IsXLine, "Returns True if the line of index <I> has a constant X value.", py::arg("I"));
	cls_Hatch_Hatcher.def("IsYLine", (Standard_Boolean (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::IsYLine, "Returns True if the line of index <I> has a constant Y value.", py::arg("I"));
	cls_Hatch_Hatcher.def("Coordinate", (Standard_Real (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::Coordinate, "Returns the X or Y coordinate of the line of index <I> if it is a X or a Y line.", py::arg("I"));
	cls_Hatch_Hatcher.def("NbIntervals", (Standard_Integer (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::NbIntervals, "Returns the number of intervals on line of index <I>.", py::arg("I"));
	cls_Hatch_Hatcher.def("Start", (Standard_Real (Hatch_Hatcher::*)(const Standard_Integer, const Standard_Integer) const ) &Hatch_Hatcher::Start, "Returns the first parameter of interval <J> on line <I>.", py::arg("I"), py::arg("J"));
	cls_Hatch_Hatcher.def("StartIndex", [](Hatch_Hatcher &self, const Standard_Integer I, const Standard_Integer J, Standard_Integer & Index, Standard_Real & Par2){ self.StartIndex(I, J, Index, Par2); return std::tuple<Standard_Integer &, Standard_Real &>(Index, Par2); }, "Returns the first Index and Par2 of interval <J> on line <I>.", py::arg("I"), py::arg("J"), py::arg("Index"), py::arg("Par2"));
	cls_Hatch_Hatcher.def("End", (Standard_Real (Hatch_Hatcher::*)(const Standard_Integer, const Standard_Integer) const ) &Hatch_Hatcher::End, "Returns the last parameter of interval <J> on line <I>.", py::arg("I"), py::arg("J"));
	cls_Hatch_Hatcher.def("EndIndex", [](Hatch_Hatcher &self, const Standard_Integer I, const Standard_Integer J, Standard_Integer & Index, Standard_Real & Par2){ self.EndIndex(I, J, Index, Par2); return std::tuple<Standard_Integer &, Standard_Real &>(Index, Par2); }, "Returns the last Index and Par2 of interval <J> on line <I>.", py::arg("I"), py::arg("J"), py::arg("Index"), py::arg("Par2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_Parameter.hxx
	py::class_<Hatch_Parameter, std::unique_ptr<Hatch_Parameter, Deleter<Hatch_Parameter>>> cls_Hatch_Parameter(mod, "Hatch_Parameter", "Stores an intersection on a line represented by :");
	cls_Hatch_Parameter.def(py::init<>());
	cls_Hatch_Parameter.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("Par1"), py::arg("Start"));
	cls_Hatch_Parameter.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Integer>(), py::arg("Par1"), py::arg("Start"), py::arg("Index"));
	cls_Hatch_Parameter.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Real>(), py::arg("Par1"), py::arg("Start"), py::arg("Index"), py::arg("Par2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_SequenceOfParameter.hxx
	bind_NCollection_Sequence<Hatch_Parameter>(mod, "Hatch_SequenceOfParameter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_SequenceOfLine.hxx
	bind_NCollection_Sequence<Hatch_Line>(mod, "Hatch_SequenceOfLine");


}
