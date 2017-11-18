#include <pyOCCT_Common.hpp>

#include <BOPAlgo_Builder.hxx>
#include <Message_ProgressIndicator.hxx>

#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepAlgoAPI_Algo.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_GlueEnum.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BOPAlgo_PPaveFiller.hxx>
#include <BOPAlgo_PBuilder.hxx>
#include <BRepAlgoAPI_BuilderAlgo.hxx>
#include <BOPAlgo_Operation.hxx>
#include <BRepAlgoAPI_BooleanOperation.hxx>
#include <BOPAlgo_ListOfCheckResult.hxx>
#include <BRepAlgoAPI_Check.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <gp_Pln.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <BRepAlgoAPI_Section.hxx>
#include <BRepAlgoAPI_Splitter.hxx>

PYBIND11_MODULE(BRepAlgoAPI, mod) {

	// IMPORT
	py::module::import("OCCT.BRepBuilderAPI");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.BOPAlgo");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgoAPI_Algo.hxx
	py::class_<BRepAlgoAPI_Algo, std::unique_ptr<BRepAlgoAPI_Algo, py::nodelete>, BRepBuilderAPI_MakeShape> cls_BRepAlgoAPI_Algo(mod, "BRepAlgoAPI_Algo", "Provides the root interface for the API algorithms");
	cls_BRepAlgoAPI_Algo.def("Shape", (const TopoDS_Shape & (BRepAlgoAPI_Algo::*)()) &BRepAlgoAPI_Algo::Shape, "None");
	cls_BRepAlgoAPI_Algo.def("Clear", (void (BRepAlgoAPI_Algo::*)()) &BRepAlgoAPI_Algo::Clear, "Clears all warnings and errors, and any data cached by the algorithm. User defined options are not cleared.");
	cls_BRepAlgoAPI_Algo.def("SetRunParallel", (void (BRepAlgoAPI_Algo::*)(const Standard_Boolean)) &BRepAlgoAPI_Algo::SetRunParallel, "Set the flag of parallel processing if <theFlag> is true the parallel processing is switched on if <theFlag> is false the parallel processing is switched off", py::arg("theFlag"));
	cls_BRepAlgoAPI_Algo.def("RunParallel", (Standard_Boolean (BRepAlgoAPI_Algo::*)() const ) &BRepAlgoAPI_Algo::RunParallel, "Returns the flag of parallel processing");
	cls_BRepAlgoAPI_Algo.def("SetFuzzyValue", (void (BRepAlgoAPI_Algo::*)(const Standard_Real)) &BRepAlgoAPI_Algo::SetFuzzyValue, "Sets the additional tolerance", py::arg("theFuzz"));
	cls_BRepAlgoAPI_Algo.def("FuzzyValue", (Standard_Real (BRepAlgoAPI_Algo::*)() const ) &BRepAlgoAPI_Algo::FuzzyValue, "Returns the additional tolerance");
	cls_BRepAlgoAPI_Algo.def("HasErrors", (Standard_Boolean (BRepAlgoAPI_Algo::*)() const ) &BRepAlgoAPI_Algo::HasErrors, "Returns true if algorithm has failed");
	cls_BRepAlgoAPI_Algo.def("HasWarnings", (Standard_Boolean (BRepAlgoAPI_Algo::*)() const ) &BRepAlgoAPI_Algo::HasWarnings, "Returns true if algorithm has generated some warning alerts");
	cls_BRepAlgoAPI_Algo.def("HasError", (Standard_Boolean (BRepAlgoAPI_Algo::*)(const opencascade::handle<Standard_Type> &) const ) &BRepAlgoAPI_Algo::HasError, "Returns true if algorithm has generated error of specified type", py::arg("theType"));
	cls_BRepAlgoAPI_Algo.def("HasWarning", (Standard_Boolean (BRepAlgoAPI_Algo::*)(const opencascade::handle<Standard_Type> &) const ) &BRepAlgoAPI_Algo::HasWarning, "Returns true if algorithm has generated warning of specified type", py::arg("theType"));
	cls_BRepAlgoAPI_Algo.def("DumpErrors", (void (BRepAlgoAPI_Algo::*)(Standard_OStream &) const ) &BRepAlgoAPI_Algo::DumpErrors, "Dumps the error status into the given stream", py::arg("theOS"));
	cls_BRepAlgoAPI_Algo.def("DumpWarnings", (void (BRepAlgoAPI_Algo::*)(Standard_OStream &) const ) &BRepAlgoAPI_Algo::DumpWarnings, "Dumps the warning statuses into the given stream", py::arg("theOS"));
	cls_BRepAlgoAPI_Algo.def("ClearWarnings", (void (BRepAlgoAPI_Algo::*)()) &BRepAlgoAPI_Algo::ClearWarnings, "Clears the warnings of the algorithm");
	cls_BRepAlgoAPI_Algo.def("GetReport", (const opencascade::handle<Message_Report> & (BRepAlgoAPI_Algo::*)() const ) &BRepAlgoAPI_Algo::GetReport, "Returns report collecting all errors and warnings");
	cls_BRepAlgoAPI_Algo.def("SetProgressIndicator", (void (BRepAlgoAPI_Algo::*)(const opencascade::handle<Message_ProgressIndicator> &)) &BRepAlgoAPI_Algo::SetProgressIndicator, "Set the Progress Indicator object.", py::arg("theObj"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgoAPI_BuilderAlgo.hxx
	py::class_<BRepAlgoAPI_BuilderAlgo, std::unique_ptr<BRepAlgoAPI_BuilderAlgo, Deleter<BRepAlgoAPI_BuilderAlgo>>, BRepAlgoAPI_Algo> cls_BRepAlgoAPI_BuilderAlgo(mod, "BRepAlgoAPI_BuilderAlgo", "The class contains API level of the General Fuse algorithm.");
	cls_BRepAlgoAPI_BuilderAlgo.def(py::init<>());
	cls_BRepAlgoAPI_BuilderAlgo.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("thePF"));
	cls_BRepAlgoAPI_BuilderAlgo.def("SetNonDestructive", (void (BRepAlgoAPI_BuilderAlgo::*)(const Standard_Boolean)) &BRepAlgoAPI_BuilderAlgo::SetNonDestructive, "Sets the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.", py::arg("theFlag"));
	cls_BRepAlgoAPI_BuilderAlgo.def("NonDestructive", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const ) &BRepAlgoAPI_BuilderAlgo::NonDestructive, "Returns the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.");
	cls_BRepAlgoAPI_BuilderAlgo.def("SetGlue", (void (BRepAlgoAPI_BuilderAlgo::*)(const BOPAlgo_GlueEnum)) &BRepAlgoAPI_BuilderAlgo::SetGlue, "Sets the glue option for the algorithm", py::arg("theGlue"));
	cls_BRepAlgoAPI_BuilderAlgo.def("Glue", (BOPAlgo_GlueEnum (BRepAlgoAPI_BuilderAlgo::*)() const ) &BRepAlgoAPI_BuilderAlgo::Glue, "Returns the glue option of the algorithm");
	cls_BRepAlgoAPI_BuilderAlgo.def("SetArguments", (void (BRepAlgoAPI_BuilderAlgo::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_BuilderAlgo::SetArguments, "Sets the arguments", py::arg("theLS"));
	cls_BRepAlgoAPI_BuilderAlgo.def("Arguments", (const TopTools_ListOfShape & (BRepAlgoAPI_BuilderAlgo::*)() const ) &BRepAlgoAPI_BuilderAlgo::Arguments, "Gets the arguments");
	cls_BRepAlgoAPI_BuilderAlgo.def("Build", (void (BRepAlgoAPI_BuilderAlgo::*)()) &BRepAlgoAPI_BuilderAlgo::Build, "Performs the algorithm");
	cls_BRepAlgoAPI_BuilderAlgo.def("Modified", (const TopTools_ListOfShape & (BRepAlgoAPI_BuilderAlgo::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BuilderAlgo::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("aS"));
	cls_BRepAlgoAPI_BuilderAlgo.def("IsDeleted", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BuilderAlgo::IsDeleted, "Returns true if the shape S has been deleted. The result shape of the operation does not contain the shape S.", py::arg("aS"));
	cls_BRepAlgoAPI_BuilderAlgo.def("Generated", (const TopTools_ListOfShape & (BRepAlgoAPI_BuilderAlgo::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BuilderAlgo::Generated, "Returns the list of shapes generated from the shape <S>. For use in BRepNaming.", py::arg("S"));
	cls_BRepAlgoAPI_BuilderAlgo.def("HasModified", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const ) &BRepAlgoAPI_BuilderAlgo::HasModified, "Returns true if there is at least one modified shape. For use in BRepNaming.");
	cls_BRepAlgoAPI_BuilderAlgo.def("HasGenerated", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const ) &BRepAlgoAPI_BuilderAlgo::HasGenerated, "Returns true if there is at least one generated shape. For use in BRepNaming.");
	cls_BRepAlgoAPI_BuilderAlgo.def("HasDeleted", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const ) &BRepAlgoAPI_BuilderAlgo::HasDeleted, "Returns true if there is at least one deleted shape. For use in BRepNaming.");
	cls_BRepAlgoAPI_BuilderAlgo.def("DSFiller", (const BOPAlgo_PPaveFiller & (BRepAlgoAPI_BuilderAlgo::*)() const ) &BRepAlgoAPI_BuilderAlgo::DSFiller, "Returns the Intersection tool");
	cls_BRepAlgoAPI_BuilderAlgo.def("Builder", (const BOPAlgo_PBuilder & (BRepAlgoAPI_BuilderAlgo::*)() const ) &BRepAlgoAPI_BuilderAlgo::Builder, "Returns the Building tool");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgoAPI_BooleanOperation.hxx
	py::class_<BRepAlgoAPI_BooleanOperation, std::unique_ptr<BRepAlgoAPI_BooleanOperation, Deleter<BRepAlgoAPI_BooleanOperation>>, BRepAlgoAPI_BuilderAlgo> cls_BRepAlgoAPI_BooleanOperation(mod, "BRepAlgoAPI_BooleanOperation", "The abstract class BooleanOperation is the root class of Boolean Operations (see Overview). Boolean Operations algorithm is divided onto two parts: - The first one is computing interference between arguments; - The second one is building the result of operation; The class BooleanOperation provides API level of both parts.");
	cls_BRepAlgoAPI_BooleanOperation.def("Shape1", (const TopoDS_Shape & (BRepAlgoAPI_BooleanOperation::*)() const ) &BRepAlgoAPI_BooleanOperation::Shape1, "Returns the first argument involved in this Boolean operation. Obsolete");
	cls_BRepAlgoAPI_BooleanOperation.def("Shape2", (const TopoDS_Shape & (BRepAlgoAPI_BooleanOperation::*)() const ) &BRepAlgoAPI_BooleanOperation::Shape2, "Returns the second argument involved in this Boolean operation. Obsolete");
	cls_BRepAlgoAPI_BooleanOperation.def("SetTools", (void (BRepAlgoAPI_BooleanOperation::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_BooleanOperation::SetTools, "Sets the tools", py::arg("theLS"));
	cls_BRepAlgoAPI_BooleanOperation.def("Tools", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)() const ) &BRepAlgoAPI_BooleanOperation::Tools, "Gets the tools");
	cls_BRepAlgoAPI_BooleanOperation.def("SetOperation", (void (BRepAlgoAPI_BooleanOperation::*)(const BOPAlgo_Operation)) &BRepAlgoAPI_BooleanOperation::SetOperation, "Sets the type of Boolean operation", py::arg("anOp"));
	cls_BRepAlgoAPI_BooleanOperation.def("Operation", (BOPAlgo_Operation (BRepAlgoAPI_BooleanOperation::*)() const ) &BRepAlgoAPI_BooleanOperation::Operation, "Returns the type of Boolean Operation");
	cls_BRepAlgoAPI_BooleanOperation.def("Build", (void (BRepAlgoAPI_BooleanOperation::*)()) &BRepAlgoAPI_BooleanOperation::Build, "Performs the algorithm Filling interference Data Structure (if it is necessary) Building the result of the operation.");
	cls_BRepAlgoAPI_BooleanOperation.def("BuilderCanWork", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const ) &BRepAlgoAPI_BooleanOperation::BuilderCanWork, "Returns True if there was no errors occured obsolete");
	cls_BRepAlgoAPI_BooleanOperation.def("FuseEdges", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const ) &BRepAlgoAPI_BooleanOperation::FuseEdges, "Returns the flag of edge refining");
	cls_BRepAlgoAPI_BooleanOperation.def("RefineEdges", (void (BRepAlgoAPI_BooleanOperation::*)()) &BRepAlgoAPI_BooleanOperation::RefineEdges, "Fuse C1 edges");
	cls_BRepAlgoAPI_BooleanOperation.def("SectionEdges", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)()) &BRepAlgoAPI_BooleanOperation::SectionEdges, "Returns a list of section edges. The edges represent the result of intersection between arguments of Boolean Operation. They are computed during operation execution.");
	cls_BRepAlgoAPI_BooleanOperation.def("Modified", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BooleanOperation::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("aS"));
	cls_BRepAlgoAPI_BooleanOperation.def("IsDeleted", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BooleanOperation::IsDeleted, "Returns true if the shape S has been deleted. The result shape of the operation does not contain the shape S.", py::arg("aS"));
	cls_BRepAlgoAPI_BooleanOperation.def("Generated", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BooleanOperation::Generated, "Returns the list of shapes generated from the shape <S>. For use in BRepNaming.", py::arg("S"));
	cls_BRepAlgoAPI_BooleanOperation.def("HasModified", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const ) &BRepAlgoAPI_BooleanOperation::HasModified, "Returns true if there is at least one modified shape. For use in BRepNaming.");
	cls_BRepAlgoAPI_BooleanOperation.def("HasGenerated", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const ) &BRepAlgoAPI_BooleanOperation::HasGenerated, "Returns true if there is at least one generated shape. For use in BRepNaming.");
	cls_BRepAlgoAPI_BooleanOperation.def("HasDeleted", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const ) &BRepAlgoAPI_BooleanOperation::HasDeleted, "Returns true if there is at least one deleted shape. For use in BRepNaming.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgoAPI_Check.hxx
	py::class_<BRepAlgoAPI_Check, std::unique_ptr<BRepAlgoAPI_Check, Deleter<BRepAlgoAPI_Check>>, BRepAlgoAPI_Algo> cls_BRepAlgoAPI_Check(mod, "BRepAlgoAPI_Check", "The class Check provides a diagnostic tool for checking single shape or couple of shapes. Single shape is checking on topological validity, small edges and self-interference. For couple of shapes added check on validity for boolean operation of given type.");
	cls_BRepAlgoAPI_Check.def(py::init<>());
	cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &>(), py::arg("theS"));
	cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theS"), py::arg("bTestSE"));
	cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("theS"), py::arg("bTestSE"), py::arg("bTestSI"));
	cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("theS1"), py::arg("theS2"));
	cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation>(), py::arg("theS1"), py::arg("theS2"), py::arg("theOp"));
	cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation, const Standard_Boolean>(), py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"));
	cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation, const Standard_Boolean, const Standard_Boolean>(), py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"), py::arg("bTestSI"));
	cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0) -> void { return self.SetData(a0); }, py::arg("theS"));
	cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.SetData(a0, a1); }, py::arg("theS"), py::arg("bTestSE"));
	cls_BRepAlgoAPI_Check.def("SetData", (void (BRepAlgoAPI_Check::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepAlgoAPI_Check::SetData, "Sets data for check by Init method. The method provides alternative way for checking single shape.", py::arg("theS"), py::arg("bTestSE"), py::arg("bTestSI"));
	cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.SetData(a0, a1); }, py::arg("theS1"), py::arg("theS2"));
	cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const BOPAlgo_Operation a2) -> void { return self.SetData(a0, a1, a2); }, py::arg("theS1"), py::arg("theS2"), py::arg("theOp"));
	cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const BOPAlgo_Operation a2, const Standard_Boolean a3) -> void { return self.SetData(a0, a1, a2, a3); }, py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"));
	cls_BRepAlgoAPI_Check.def("SetData", (void (BRepAlgoAPI_Check::*)(const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation, const Standard_Boolean, const Standard_Boolean)) &BRepAlgoAPI_Check::SetData, "Sets data for check by Init method. The method provides alternative way for checking couple of shapes.", py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"), py::arg("bTestSI"));
	cls_BRepAlgoAPI_Check.def("Perform", (void (BRepAlgoAPI_Check::*)()) &BRepAlgoAPI_Check::Perform, "Performs the check.");
	cls_BRepAlgoAPI_Check.def("IsValid", (Standard_Boolean (BRepAlgoAPI_Check::*)()) &BRepAlgoAPI_Check::IsValid, "Shows whether shape(s) valid or not.");
	cls_BRepAlgoAPI_Check.def("Result", (const BOPAlgo_ListOfCheckResult & (BRepAlgoAPI_Check::*)()) &BRepAlgoAPI_Check::Result, "Returns faulty shapes.");
	cls_BRepAlgoAPI_Check.def("SetFuzzyValue", (void (BRepAlgoAPI_Check::*)(const Standard_Real)) &BRepAlgoAPI_Check::SetFuzzyValue, "Sets the additional tolerance", py::arg("theFuzz"));
	cls_BRepAlgoAPI_Check.def("FuzzyValue", (Standard_Real (BRepAlgoAPI_Check::*)() const ) &BRepAlgoAPI_Check::FuzzyValue, "Returns the additional tolerance");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgoAPI_Common.hxx
	py::class_<BRepAlgoAPI_Common, std::unique_ptr<BRepAlgoAPI_Common, Deleter<BRepAlgoAPI_Common>>, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Common(mod, "BRepAlgoAPI_Common", "The class provides Boolean common operation between arguments and tools (Boolean Intersection).");
	cls_BRepAlgoAPI_Common.def(py::init<>());
	cls_BRepAlgoAPI_Common.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
	cls_BRepAlgoAPI_Common.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
	cls_BRepAlgoAPI_Common.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("PF"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgoAPI_Cut.hxx
	py::class_<BRepAlgoAPI_Cut, std::unique_ptr<BRepAlgoAPI_Cut, Deleter<BRepAlgoAPI_Cut>>, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Cut(mod, "BRepAlgoAPI_Cut", "The class Cut provides Boolean cut operation between arguments and tools (Boolean Subtraction).");
	cls_BRepAlgoAPI_Cut.def(py::init<>());
	cls_BRepAlgoAPI_Cut.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
	cls_BRepAlgoAPI_Cut.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
	cls_BRepAlgoAPI_Cut.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"));
	cls_BRepAlgoAPI_Cut.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"), py::arg("bFWD"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgoAPI_Fuse.hxx
	py::class_<BRepAlgoAPI_Fuse, std::unique_ptr<BRepAlgoAPI_Fuse, Deleter<BRepAlgoAPI_Fuse>>, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Fuse(mod, "BRepAlgoAPI_Fuse", "The class provides Boolean fusion operation between arguments and tools (Boolean Union).");
	cls_BRepAlgoAPI_Fuse.def(py::init<>());
	cls_BRepAlgoAPI_Fuse.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
	cls_BRepAlgoAPI_Fuse.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
	cls_BRepAlgoAPI_Fuse.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgoAPI_Section.hxx
	py::class_<BRepAlgoAPI_Section, std::unique_ptr<BRepAlgoAPI_Section, Deleter<BRepAlgoAPI_Section>>, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Section(mod, "BRepAlgoAPI_Section", "The algorithm is to build a Secton operation between arguments and tools. The result of Section operation consists of vertices and edges. The result of Section operation contains: 1. new vertices that are subjects of V/V, E/E, E/F, F/F interferences 2. vertices that are subjects of V/E, V/F interferences 3. new edges that are subjects of F/F interferences 4. edges that are Common Blocks");
	cls_BRepAlgoAPI_Section.def(py::init<>());
	cls_BRepAlgoAPI_Section.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
	cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
	cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("PerformNow"));
	cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"));
	cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"), py::arg("PerformNow"));
	cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &>(), py::arg("S1"), py::arg("Pl"));
	cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &, const Standard_Boolean>(), py::arg("S1"), py::arg("Pl"), py::arg("PerformNow"));
	cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &>(), py::arg("S1"), py::arg("Sf"));
	cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S1"), py::arg("Sf"), py::arg("PerformNow"));
	cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &>(), py::arg("Sf"), py::arg("S2"));
	cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Sf"), py::arg("S2"), py::arg("PerformNow"));
	cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &>(), py::arg("Sf1"), py::arg("Sf2"));
	cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("Sf1"), py::arg("Sf2"), py::arg("PerformNow"));
	cls_BRepAlgoAPI_Section.def("Init1", (void (BRepAlgoAPI_Section::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Section::Init1, "initialize the argument <S1> - argument Obsolete", py::arg("S1"));
	cls_BRepAlgoAPI_Section.def("Init1", (void (BRepAlgoAPI_Section::*)(const gp_Pln &)) &BRepAlgoAPI_Section::Init1, "initialize the argument <Pl> - argument Obsolete", py::arg("Pl"));
	cls_BRepAlgoAPI_Section.def("Init1", (void (BRepAlgoAPI_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgoAPI_Section::Init1, "initialize the argument <Sf> - argument Obsolete", py::arg("Sf"));
	cls_BRepAlgoAPI_Section.def("Init2", (void (BRepAlgoAPI_Section::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Section::Init2, "initialize the tool <S2> - tool Obsolete", py::arg("S2"));
	cls_BRepAlgoAPI_Section.def("Init2", (void (BRepAlgoAPI_Section::*)(const gp_Pln &)) &BRepAlgoAPI_Section::Init2, "initialize the tool <Pl> - tool Obsolete", py::arg("Pl"));
	cls_BRepAlgoAPI_Section.def("Init2", (void (BRepAlgoAPI_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgoAPI_Section::Init2, "initialize the tool <Sf> - tool Obsolete", py::arg("Sf"));
	cls_BRepAlgoAPI_Section.def("Approximation", (void (BRepAlgoAPI_Section::*)(const Standard_Boolean)) &BRepAlgoAPI_Section::Approximation, "None", py::arg("B"));
	cls_BRepAlgoAPI_Section.def("ComputePCurveOn1", (void (BRepAlgoAPI_Section::*)(const Standard_Boolean)) &BRepAlgoAPI_Section::ComputePCurveOn1, "Indicates whether the P-Curve should be (or not) performed on the argument. By default, no parametric 2D curve (pcurve) is defined for the edges of the result. If ComputePCurve1 equals true, further computations performed to attach an P-Curve in the parametric space of the argument to the constructed edges. Obsolete", py::arg("B"));
	cls_BRepAlgoAPI_Section.def("ComputePCurveOn2", (void (BRepAlgoAPI_Section::*)(const Standard_Boolean)) &BRepAlgoAPI_Section::ComputePCurveOn2, "Indicates whether the P-Curve should be (or not) performed on the tool. By default, no parametric 2D curve (pcurve) is defined for the edges of the result. If ComputePCurve1 equals true, further computations performed to attach an P-Curve in the parametric space of the tool to the constructed edges. Obsolete", py::arg("B"));
	cls_BRepAlgoAPI_Section.def("Build", (void (BRepAlgoAPI_Section::*)()) &BRepAlgoAPI_Section::Build, "Performs the algorithm Filling interference Data Structure (if it is necessary) Building the result of the operation.");
	cls_BRepAlgoAPI_Section.def("HasAncestorFaceOn1", (Standard_Boolean (BRepAlgoAPI_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const ) &BRepAlgoAPI_Section::HasAncestorFaceOn1, "get the face of the first part giving section edge <E>. Returns True on the 3 following conditions : 1/ <E> is an edge returned by the Shape() metwod. 2/ First part of section performed is a shape. 3/ <E> is built on a intersection curve (i.e <E> is not the result of common edges) When False, F remains untouched. Obsolete", py::arg("E"), py::arg("F"));
	cls_BRepAlgoAPI_Section.def("HasAncestorFaceOn2", (Standard_Boolean (BRepAlgoAPI_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const ) &BRepAlgoAPI_Section::HasAncestorFaceOn2, "Identifies the ancestor faces of the intersection edge E resulting from the last computation performed in this framework, that is, the faces of the two original shapes on which the edge E lies: - HasAncestorFaceOn1 gives the ancestor face in the first shape, and - HasAncestorFaceOn2 gives the ancestor face in the second shape. These functions return true if an ancestor face F is found, or false if not. An ancestor face is identifiable for the edge E if the following conditions are satisfied: - the first part on which this algorithm performed its last computation is a shape, that is, it was not given as a surface or a plane at the time of construction of this algorithm or at a later time by the Init1 function, - E is one of the elementary edges built by the last computation of this section algorithm. To use these functions properly, you have to test the returned Boolean value before using the ancestor face: F is significant only if the returned Boolean value equals true. Obsolete", py::arg("E"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgoAPI_Splitter.hxx
	py::class_<BRepAlgoAPI_Splitter, std::unique_ptr<BRepAlgoAPI_Splitter, Deleter<BRepAlgoAPI_Splitter>>, BRepAlgoAPI_BuilderAlgo> cls_BRepAlgoAPI_Splitter(mod, "BRepAlgoAPI_Splitter", "The class contains API level of the **Splitter** algorithm, which allows splitting a group of arbitrary shapes by the other group of arbitrary shapes. The arguments of the operation are divided on two groups: *Objects* - shapes that will be split; *Tools* - shapes by which the *Objects* will be split. The result of the operation contains only the split parts of the shapes from the group of *Objects*. The split parts of the shapes from the group of *Tools* are excluded from the result. The shapes can be split by the other shapes from the same group (in case these shapes are interfering).");
	cls_BRepAlgoAPI_Splitter.def(py::init<>());
	cls_BRepAlgoAPI_Splitter.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("thePF"));
	cls_BRepAlgoAPI_Splitter.def("Build", (void (BRepAlgoAPI_Splitter::*)()) &BRepAlgoAPI_Splitter::Build, "Performs the algorithm. Performs the intersection of the objects with tools and build the result of the operation.");
	cls_BRepAlgoAPI_Splitter.def("SetTools", (void (BRepAlgoAPI_Splitter::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_Splitter::SetTools, "Sets the tools", py::arg("theLS"));
	cls_BRepAlgoAPI_Splitter.def("Tools", (const TopTools_ListOfShape & (BRepAlgoAPI_Splitter::*)() const ) &BRepAlgoAPI_Splitter::Tools, "Gets the tools");


}
