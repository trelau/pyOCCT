#include <pyOCCT_Common.hpp>

#include <BRepExtrema_SupportType.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <BRepExtrema_SolutionElem.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <BRepExtrema_SeqOfSolution.hxx>
#include <TopoDS_Shape.hxx>
#include <Bnd_Box.hxx>
#include <Extrema_ExtFlag.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <BRepExtrema_DistanceSS.hxx>
#include <Standard_OStream.hxx>
#include <BRepExtrema_DistShapeShape.hxx>
#include <BRepExtrema_ElementFilter.hxx>
#include <BRepExtrema_ExtCC.hxx>
#include <BRepExtrema_ExtCF.hxx>
#include <BRepExtrema_ExtFF.hxx>
#include <BRepExtrema_ExtPC.hxx>
#include <BRepExtrema_ExtPF.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepExtrema_MapOfIntegerPackedMapOfInteger.hxx>
#include <NCollection_BaseVector.hxx>
#include <NCollection_Vector.hxx>
#include <BRepExtrema_TriangleSet.hxx>
#include <BVH_PrimitiveSet3d.hxx>
#include <BVH_Box.hxx>
#include <BVH_Types.hxx>
#include <Standard_Type.hxx>
#include <BRepExtrema_OverlapTool.hxx>
#include <BRepExtrema_Poly.hxx>
#include <BRepExtrema_SelfIntersection.hxx>
#include <BRepExtrema_ShapeProximity.hxx>
#include <Standard_DomainError.hxx>
#include <Standard_SStream.hxx>
#include <BRepExtrema_UnCompatibleShape.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(BRepExtrema, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.Extrema");
	py::module::import("OCCT.BVH");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_SupportType.hxx
	py::enum_<BRepExtrema_SupportType>(mod, "BRepExtrema_SupportType", "None")
		.value("BRepExtrema_IsVertex", BRepExtrema_SupportType::BRepExtrema_IsVertex)
		.value("BRepExtrema_IsOnEdge", BRepExtrema_SupportType::BRepExtrema_IsOnEdge)
		.value("BRepExtrema_IsInFace", BRepExtrema_SupportType::BRepExtrema_IsInFace)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_SolutionElem.hxx
	py::class_<BRepExtrema_SolutionElem, std::unique_ptr<BRepExtrema_SolutionElem, Deleter<BRepExtrema_SolutionElem>>> cls_BRepExtrema_SolutionElem(mod, "BRepExtrema_SolutionElem", "This class is used to store information relative to the minimum distance between two shapes.");
	cls_BRepExtrema_SolutionElem.def(py::init<>());
	cls_BRepExtrema_SolutionElem.def(py::init<const Standard_Real, const gp_Pnt &, const BRepExtrema_SupportType, const TopoDS_Vertex &>(), py::arg("theDist"), py::arg("thePoint"), py::arg("theSolType"), py::arg("theVertex"));
	cls_BRepExtrema_SolutionElem.def(py::init<const Standard_Real, const gp_Pnt &, const BRepExtrema_SupportType, const TopoDS_Edge &, const Standard_Real>(), py::arg("theDist"), py::arg("thePoint"), py::arg("theSolType"), py::arg("theEdge"), py::arg("theParam"));
	cls_BRepExtrema_SolutionElem.def(py::init<const Standard_Real, const gp_Pnt &, const BRepExtrema_SupportType, const TopoDS_Face &, const Standard_Real, const Standard_Real>(), py::arg("theDist"), py::arg("thePoint"), py::arg("theSolType"), py::arg("theFace"), py::arg("theU"), py::arg("theV"));
	cls_BRepExtrema_SolutionElem.def("Dist", (Standard_Real (BRepExtrema_SolutionElem::*)() const ) &BRepExtrema_SolutionElem::Dist, "Returns the value of the minimum distance.");
	cls_BRepExtrema_SolutionElem.def("Point", (const gp_Pnt & (BRepExtrema_SolutionElem::*)() const ) &BRepExtrema_SolutionElem::Point, "Returns the solution point.");
	cls_BRepExtrema_SolutionElem.def("SupportKind", (BRepExtrema_SupportType (BRepExtrema_SolutionElem::*)() const ) &BRepExtrema_SolutionElem::SupportKind, "Returns the Support type: IsVertex => The solution is a vertex. IsOnEdge => The solution belongs to an Edge. IsInFace => The solution is inside a Face.");
	cls_BRepExtrema_SolutionElem.def("Vertex", (const TopoDS_Vertex & (BRepExtrema_SolutionElem::*)() const ) &BRepExtrema_SolutionElem::Vertex, "Returns the vertex if the solution is a Vertex.");
	cls_BRepExtrema_SolutionElem.def("Edge", (const TopoDS_Edge & (BRepExtrema_SolutionElem::*)() const ) &BRepExtrema_SolutionElem::Edge, "Returns the vertex if the solution is an Edge.");
	cls_BRepExtrema_SolutionElem.def("Face", (const TopoDS_Face & (BRepExtrema_SolutionElem::*)() const ) &BRepExtrema_SolutionElem::Face, "Returns the vertex if the solution is an Face.");
	cls_BRepExtrema_SolutionElem.def("EdgeParameter", (void (BRepExtrema_SolutionElem::*)(Standard_Real &) const ) &BRepExtrema_SolutionElem::EdgeParameter, "Returns the parameter value if the solution is on Edge.", py::arg("theParam"));
	cls_BRepExtrema_SolutionElem.def("FaceParameter", (void (BRepExtrema_SolutionElem::*)(Standard_Real &, Standard_Real &) const ) &BRepExtrema_SolutionElem::FaceParameter, "Returns the parameters U and V if the solution is in a Face.", py::arg("theU"), py::arg("theV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_DistanceSS.hxx
	py::class_<BRepExtrema_DistanceSS, std::unique_ptr<BRepExtrema_DistanceSS, Deleter<BRepExtrema_DistanceSS>>> cls_BRepExtrema_DistanceSS(mod, "BRepExtrema_DistanceSS", "This class allows to compute minimum distance between two shapes (face edge vertex) and is used in DistShapeShape class.");
	cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"));
	cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Extrema_ExtFlag>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("F"));
	cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("F"), py::arg("A"));
	cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("aDeflection"));
	cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("aDeflection"), py::arg("F"));
	cls_BRepExtrema_DistanceSS.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"), py::arg("DstRef"), py::arg("aDeflection"), py::arg("F"), py::arg("A"));
	cls_BRepExtrema_DistanceSS.def("IsDone", (Standard_Boolean (BRepExtrema_DistanceSS::*)() const ) &BRepExtrema_DistanceSS::IsDone, "True if the distance has been computed");
	cls_BRepExtrema_DistanceSS.def("DistValue", (Standard_Real (BRepExtrema_DistanceSS::*)() const ) &BRepExtrema_DistanceSS::DistValue, "returns the distance value");
	cls_BRepExtrema_DistanceSS.def("Seq1Value", (const BRepExtrema_SeqOfSolution & (BRepExtrema_DistanceSS::*)() const ) &BRepExtrema_DistanceSS::Seq1Value, "returns the list of solutions on the first shape");
	cls_BRepExtrema_DistanceSS.def("Seq2Value", (const BRepExtrema_SeqOfSolution & (BRepExtrema_DistanceSS::*)() const ) &BRepExtrema_DistanceSS::Seq2Value, "returns the list of solutions on the second shape");
	cls_BRepExtrema_DistanceSS.def("SetFlag", (void (BRepExtrema_DistanceSS::*)(const Extrema_ExtFlag)) &BRepExtrema_DistanceSS::SetFlag, "sets the flag controlling minimum and maximum search", py::arg("F"));
	cls_BRepExtrema_DistanceSS.def("SetAlgo", (void (BRepExtrema_DistanceSS::*)(const Extrema_ExtAlgo)) &BRepExtrema_DistanceSS::SetAlgo, "sets the flag controlling ...", py::arg("A"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_DistShapeShape.hxx
	py::class_<BRepExtrema_DistShapeShape, std::unique_ptr<BRepExtrema_DistShapeShape, Deleter<BRepExtrema_DistShapeShape>>> cls_BRepExtrema_DistShapeShape(mod, "BRepExtrema_DistShapeShape", "This class provides tools to compute minimum distance between two Shapes (Compound,CompSolid, Solid, Shell, Face, Wire, Edge, Vertex).");
	cls_BRepExtrema_DistShapeShape.def(py::init<>());
	cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Shape1"), py::arg("Shape2"));
	cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Extrema_ExtFlag>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("F"));
	cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("F"), py::arg("A"));
	cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("theDeflection"));
	cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real, const Extrema_ExtFlag>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("theDeflection"), py::arg("F"));
	cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("theDeflection"), py::arg("F"), py::arg("A"));
	cls_BRepExtrema_DistShapeShape.def("SetDeflection", (void (BRepExtrema_DistShapeShape::*)(const Standard_Real)) &BRepExtrema_DistShapeShape::SetDeflection, "None", py::arg("theDeflection"));
	cls_BRepExtrema_DistShapeShape.def("LoadS1", (void (BRepExtrema_DistShapeShape::*)(const TopoDS_Shape &)) &BRepExtrema_DistShapeShape::LoadS1, "load first shape into extrema", py::arg("Shape1"));
	cls_BRepExtrema_DistShapeShape.def("LoadS2", (void (BRepExtrema_DistShapeShape::*)(const TopoDS_Shape &)) &BRepExtrema_DistShapeShape::LoadS2, "load second shape into extrema", py::arg("Shape1"));
	cls_BRepExtrema_DistShapeShape.def("Perform", (Standard_Boolean (BRepExtrema_DistShapeShape::*)()) &BRepExtrema_DistShapeShape::Perform, "computation of the minimum distance (value and couple of points). Parameter theDeflection is used to specify a maximum deviation of extreme distances from the minimum one. Returns IsDone status.");
	cls_BRepExtrema_DistShapeShape.def("IsDone", (Standard_Boolean (BRepExtrema_DistShapeShape::*)() const ) &BRepExtrema_DistShapeShape::IsDone, "True if the minimum distance is found.");
	cls_BRepExtrema_DistShapeShape.def("NbSolution", (Standard_Integer (BRepExtrema_DistShapeShape::*)() const ) &BRepExtrema_DistShapeShape::NbSolution, "Returns the number of solutions satisfying the minimum distance.");
	cls_BRepExtrema_DistShapeShape.def("Value", (Standard_Real (BRepExtrema_DistShapeShape::*)() const ) &BRepExtrema_DistShapeShape::Value, "Returns the value of the minimum distance.");
	cls_BRepExtrema_DistShapeShape.def("InnerSolution", (Standard_Boolean (BRepExtrema_DistShapeShape::*)() const ) &BRepExtrema_DistShapeShape::InnerSolution, "True if one of the shapes is a solid and the other shape is completely or partially inside the solid.");
	cls_BRepExtrema_DistShapeShape.def("PointOnShape1", (const gp_Pnt & (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const ) &BRepExtrema_DistShapeShape::PointOnShape1, "Returns the Point corresponding to the <N>th solution on the first Shape", py::arg("N"));
	cls_BRepExtrema_DistShapeShape.def("PointOnShape2", (const gp_Pnt & (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const ) &BRepExtrema_DistShapeShape::PointOnShape2, "Returns the Point corresponding to the <N>th solution on the second Shape", py::arg("N"));
	cls_BRepExtrema_DistShapeShape.def("SupportTypeShape1", (BRepExtrema_SupportType (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const ) &BRepExtrema_DistShapeShape::SupportTypeShape1, "gives the type of the support where the Nth solution on the first shape is situated: IsVertex => the Nth solution on the first shape is a Vertex IsOnEdge => the Nth soluion on the first shape is on a Edge IsInFace => the Nth solution on the first shape is inside a face the corresponding support is obtained by the method SupportOnShape1", py::arg("N"));
	cls_BRepExtrema_DistShapeShape.def("SupportTypeShape2", (BRepExtrema_SupportType (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const ) &BRepExtrema_DistShapeShape::SupportTypeShape2, "gives the type of the support where the Nth solution on the second shape is situated: IsVertex => the Nth solution on the second shape is a Vertex IsOnEdge => the Nth soluion on the secondt shape is on a Edge IsInFace => the Nth solution on the second shape is inside a face the corresponding support is obtained by the method SupportOnShape2", py::arg("N"));
	cls_BRepExtrema_DistShapeShape.def("SupportOnShape1", (TopoDS_Shape (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const ) &BRepExtrema_DistShapeShape::SupportOnShape1, "gives the support where the Nth solution on the first shape is situated. This support can be a Vertex, an Edge or a Face.", py::arg("N"));
	cls_BRepExtrema_DistShapeShape.def("SupportOnShape2", (TopoDS_Shape (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const ) &BRepExtrema_DistShapeShape::SupportOnShape2, "gives the support where the Nth solution on the second shape is situated. This support can be a Vertex, an Edge or a Face.", py::arg("N"));
	cls_BRepExtrema_DistShapeShape.def("ParOnEdgeS1", (void (BRepExtrema_DistShapeShape::*)(const Standard_Integer, Standard_Real &) const ) &BRepExtrema_DistShapeShape::ParOnEdgeS1, "gives the corresponding parameter t if the Nth solution is situated on an Egde of the first shape", py::arg("N"), py::arg("t"));
	cls_BRepExtrema_DistShapeShape.def("ParOnEdgeS2", (void (BRepExtrema_DistShapeShape::*)(const Standard_Integer, Standard_Real &) const ) &BRepExtrema_DistShapeShape::ParOnEdgeS2, "gives the corresponding parameter t if the Nth solution is situated on an Egde of the first shape", py::arg("N"), py::arg("t"));
	cls_BRepExtrema_DistShapeShape.def("ParOnFaceS1", (void (BRepExtrema_DistShapeShape::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &BRepExtrema_DistShapeShape::ParOnFaceS1, "gives the corresponding parameters (U,V) if the Nth solution is situated on an face of the first shape", py::arg("N"), py::arg("u"), py::arg("v"));
	cls_BRepExtrema_DistShapeShape.def("ParOnFaceS2", (void (BRepExtrema_DistShapeShape::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &BRepExtrema_DistShapeShape::ParOnFaceS2, "gives the corresponding parameters (U,V) if the Nth solution is situated on an Face of the second shape", py::arg("N"), py::arg("u"), py::arg("v"));
	// FIXME cls_BRepExtrema_DistShapeShape.def("Dump", (void (BRepExtrema_DistShapeShape::*)(Standard_OStream &) const ) &BRepExtrema_DistShapeShape::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));
	cls_BRepExtrema_DistShapeShape.def("SetFlag", (void (BRepExtrema_DistShapeShape::*)(const Extrema_ExtFlag)) &BRepExtrema_DistShapeShape::SetFlag, "None", py::arg("F"));
	cls_BRepExtrema_DistShapeShape.def("SetAlgo", (void (BRepExtrema_DistShapeShape::*)(const Extrema_ExtAlgo)) &BRepExtrema_DistShapeShape::SetAlgo, "None", py::arg("A"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_ElementFilter.hxx
	py::class_<BRepExtrema_ElementFilter, std::unique_ptr<BRepExtrema_ElementFilter, Deleter<BRepExtrema_ElementFilter>>> cls_BRepExtrema_ElementFilter(mod, "BRepExtrema_ElementFilter", "Filtering tool used to detect if two given mesh elements should be tested for overlapping/intersection or not.");
	cls_BRepExtrema_ElementFilter.def(py::init<>());
	cls_BRepExtrema_ElementFilter.def("PreCheckElements", (BRepExtrema_ElementFilter::FilterResult (BRepExtrema_ElementFilter::*)(const Standard_Integer, const Standard_Integer)) &BRepExtrema_ElementFilter::PreCheckElements, "Checks if two mesh elements should be tested for overlapping/intersection (used for detection correct/incorrect cases of shared edges and vertices).", py::arg(""), py::arg(""));
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_ElementFilter.hxx
	py::enum_<BRepExtrema_ElementFilter::FilterResult>(cls_BRepExtrema_ElementFilter, "FilterResult", "Result of filtering function.")
		.value("NoCheck", BRepExtrema_ElementFilter::FilterResult::NoCheck)
		.value("Overlap", BRepExtrema_ElementFilter::FilterResult::Overlap)
		.value("DoCheck", BRepExtrema_ElementFilter::FilterResult::DoCheck)
		.export_values();

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_ExtCC.hxx
	py::class_<BRepExtrema_ExtCC, std::unique_ptr<BRepExtrema_ExtCC, Deleter<BRepExtrema_ExtCC>>> cls_BRepExtrema_ExtCC(mod, "BRepExtrema_ExtCC", "None");
	cls_BRepExtrema_ExtCC.def(py::init<>());
	cls_BRepExtrema_ExtCC.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"));
	cls_BRepExtrema_ExtCC.def("Initialize", (void (BRepExtrema_ExtCC::*)(const TopoDS_Edge &)) &BRepExtrema_ExtCC::Initialize, "None", py::arg("E2"));
	cls_BRepExtrema_ExtCC.def("Perform", (void (BRepExtrema_ExtCC::*)(const TopoDS_Edge &)) &BRepExtrema_ExtCC::Perform, "An exception is raised if the fields have not been initialized.", py::arg("E1"));
	cls_BRepExtrema_ExtCC.def("IsDone", (Standard_Boolean (BRepExtrema_ExtCC::*)() const ) &BRepExtrema_ExtCC::IsDone, "True if the distances are found.");
	cls_BRepExtrema_ExtCC.def("NbExt", (Standard_Integer (BRepExtrema_ExtCC::*)() const ) &BRepExtrema_ExtCC::NbExt, "Returns the number of extremum distances.");
	cls_BRepExtrema_ExtCC.def("IsParallel", (Standard_Boolean (BRepExtrema_ExtCC::*)() const ) &BRepExtrema_ExtCC::IsParallel, "Returns True if E1 and E2 are parallel.");
	cls_BRepExtrema_ExtCC.def("SquareDistance", (Standard_Real (BRepExtrema_ExtCC::*)(const Standard_Integer) const ) &BRepExtrema_ExtCC::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
	cls_BRepExtrema_ExtCC.def("ParameterOnE1", (Standard_Real (BRepExtrema_ExtCC::*)(const Standard_Integer) const ) &BRepExtrema_ExtCC::ParameterOnE1, "Returns the parameter on the first edge of the <N>th extremum distance.", py::arg("N"));
	cls_BRepExtrema_ExtCC.def("PointOnE1", (gp_Pnt (BRepExtrema_ExtCC::*)(const Standard_Integer) const ) &BRepExtrema_ExtCC::PointOnE1, "Returns the Point of the <N>th extremum distance on the edge E1.", py::arg("N"));
	cls_BRepExtrema_ExtCC.def("ParameterOnE2", (Standard_Real (BRepExtrema_ExtCC::*)(const Standard_Integer) const ) &BRepExtrema_ExtCC::ParameterOnE2, "Returns the parameter on the second edge of the <N>th extremum distance.", py::arg("N"));
	cls_BRepExtrema_ExtCC.def("PointOnE2", (gp_Pnt (BRepExtrema_ExtCC::*)(const Standard_Integer) const ) &BRepExtrema_ExtCC::PointOnE2, "Returns the Point of the <N>th extremum distance on the edge E2.", py::arg("N"));
	cls_BRepExtrema_ExtCC.def("TrimmedSquareDistances", (void (BRepExtrema_ExtCC::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &) const ) &BRepExtrema_ExtCC::TrimmedSquareDistances, "if the edges is a trimmed curve, dist11 is a square distance between the point on E1 of parameter FirstParameter and the point of parameter FirstParameter on E2.", py::arg("dist11"), py::arg("distP12"), py::arg("distP21"), py::arg("distP22"), py::arg("P11"), py::arg("P12"), py::arg("P21"), py::arg("P22"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_ExtCF.hxx
	py::class_<BRepExtrema_ExtCF, std::unique_ptr<BRepExtrema_ExtCF, Deleter<BRepExtrema_ExtCF>>> cls_BRepExtrema_ExtCF(mod, "BRepExtrema_ExtCF", "None");
	cls_BRepExtrema_ExtCF.def(py::init<>());
	cls_BRepExtrema_ExtCF.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));
	cls_BRepExtrema_ExtCF.def("Initialize", (void (BRepExtrema_ExtCF::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepExtrema_ExtCF::Initialize, "None", py::arg("E"), py::arg("F"));
	cls_BRepExtrema_ExtCF.def("Perform", (void (BRepExtrema_ExtCF::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepExtrema_ExtCF::Perform, "An exception is raised if the fields have not been initialized. Be careful: this method uses the Face only for classify not for the fields.", py::arg("E"), py::arg("F"));
	cls_BRepExtrema_ExtCF.def("IsDone", (Standard_Boolean (BRepExtrema_ExtCF::*)() const ) &BRepExtrema_ExtCF::IsDone, "True if the distances are found.");
	cls_BRepExtrema_ExtCF.def("NbExt", (Standard_Integer (BRepExtrema_ExtCF::*)() const ) &BRepExtrema_ExtCF::NbExt, "Returns the number of extremum distances.");
	cls_BRepExtrema_ExtCF.def("SquareDistance", (Standard_Real (BRepExtrema_ExtCF::*)(const Standard_Integer) const ) &BRepExtrema_ExtCF::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
	cls_BRepExtrema_ExtCF.def("IsParallel", (Standard_Boolean (BRepExtrema_ExtCF::*)() const ) &BRepExtrema_ExtCF::IsParallel, "Returns True if the curve is on a parallel surface.");
	cls_BRepExtrema_ExtCF.def("ParameterOnEdge", (Standard_Real (BRepExtrema_ExtCF::*)(const Standard_Integer) const ) &BRepExtrema_ExtCF::ParameterOnEdge, "Returns the parameters on the Edge of the <N>th extremum distance.", py::arg("N"));
	cls_BRepExtrema_ExtCF.def("ParameterOnFace", (void (BRepExtrema_ExtCF::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &BRepExtrema_ExtCF::ParameterOnFace, "Returns the parameters on the Face of the <N>th extremum distance.", py::arg("N"), py::arg("U"), py::arg("V"));
	cls_BRepExtrema_ExtCF.def("PointOnEdge", (gp_Pnt (BRepExtrema_ExtCF::*)(const Standard_Integer) const ) &BRepExtrema_ExtCF::PointOnEdge, "Returns the Point of the <N>th extremum distance.", py::arg("N"));
	cls_BRepExtrema_ExtCF.def("PointOnFace", (gp_Pnt (BRepExtrema_ExtCF::*)(const Standard_Integer) const ) &BRepExtrema_ExtCF::PointOnFace, "Returns the Point of the <N>th extremum distance.", py::arg("N"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_ExtFF.hxx
	py::class_<BRepExtrema_ExtFF, std::unique_ptr<BRepExtrema_ExtFF, Deleter<BRepExtrema_ExtFF>>> cls_BRepExtrema_ExtFF(mod, "BRepExtrema_ExtFF", "None");
	cls_BRepExtrema_ExtFF.def(py::init<>());
	cls_BRepExtrema_ExtFF.def(py::init<const TopoDS_Face &, const TopoDS_Face &>(), py::arg("F1"), py::arg("F2"));
	cls_BRepExtrema_ExtFF.def("Initialize", (void (BRepExtrema_ExtFF::*)(const TopoDS_Face &)) &BRepExtrema_ExtFF::Initialize, "None", py::arg("F2"));
	cls_BRepExtrema_ExtFF.def("Perform", (void (BRepExtrema_ExtFF::*)(const TopoDS_Face &, const TopoDS_Face &)) &BRepExtrema_ExtFF::Perform, "An exception is raised if the fields have not been initialized. Be careful: this method uses the Face F2 only for classify, not for the fields.", py::arg("F1"), py::arg("F2"));
	cls_BRepExtrema_ExtFF.def("IsDone", (Standard_Boolean (BRepExtrema_ExtFF::*)() const ) &BRepExtrema_ExtFF::IsDone, "True if the distances are found.");
	cls_BRepExtrema_ExtFF.def("IsParallel", (Standard_Boolean (BRepExtrema_ExtFF::*)() const ) &BRepExtrema_ExtFF::IsParallel, "Returns True if the surfaces are parallel.");
	cls_BRepExtrema_ExtFF.def("NbExt", (Standard_Integer (BRepExtrema_ExtFF::*)() const ) &BRepExtrema_ExtFF::NbExt, "Returns the number of extremum distances.");
	cls_BRepExtrema_ExtFF.def("SquareDistance", (Standard_Real (BRepExtrema_ExtFF::*)(const Standard_Integer) const ) &BRepExtrema_ExtFF::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
	cls_BRepExtrema_ExtFF.def("ParameterOnFace1", (void (BRepExtrema_ExtFF::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &BRepExtrema_ExtFF::ParameterOnFace1, "Returns the parameters on the Face F1 of the <N>th extremum distance.", py::arg("N"), py::arg("U"), py::arg("V"));
	cls_BRepExtrema_ExtFF.def("ParameterOnFace2", (void (BRepExtrema_ExtFF::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &BRepExtrema_ExtFF::ParameterOnFace2, "Returns the parameters on the Face F2 of the <N>th extremum distance.", py::arg("N"), py::arg("U"), py::arg("V"));
	cls_BRepExtrema_ExtFF.def("PointOnFace1", (gp_Pnt (BRepExtrema_ExtFF::*)(const Standard_Integer) const ) &BRepExtrema_ExtFF::PointOnFace1, "Returns the Point of the <N>th extremum distance.", py::arg("N"));
	cls_BRepExtrema_ExtFF.def("PointOnFace2", (gp_Pnt (BRepExtrema_ExtFF::*)(const Standard_Integer) const ) &BRepExtrema_ExtFF::PointOnFace2, "Returns the Point of the <N>th extremum distance.", py::arg("N"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_ExtPC.hxx
	py::class_<BRepExtrema_ExtPC, std::unique_ptr<BRepExtrema_ExtPC, Deleter<BRepExtrema_ExtPC>>> cls_BRepExtrema_ExtPC(mod, "BRepExtrema_ExtPC", "None");
	cls_BRepExtrema_ExtPC.def(py::init<>());
	cls_BRepExtrema_ExtPC.def(py::init<const TopoDS_Vertex &, const TopoDS_Edge &>(), py::arg("V"), py::arg("E"));
	cls_BRepExtrema_ExtPC.def("Initialize", (void (BRepExtrema_ExtPC::*)(const TopoDS_Edge &)) &BRepExtrema_ExtPC::Initialize, "None", py::arg("E"));
	cls_BRepExtrema_ExtPC.def("Perform", (void (BRepExtrema_ExtPC::*)(const TopoDS_Vertex &)) &BRepExtrema_ExtPC::Perform, "An exception is raised if the fields have not been initialized.", py::arg("V"));
	cls_BRepExtrema_ExtPC.def("IsDone", (Standard_Boolean (BRepExtrema_ExtPC::*)() const ) &BRepExtrema_ExtPC::IsDone, "True if the distances are found.");
	cls_BRepExtrema_ExtPC.def("NbExt", (Standard_Integer (BRepExtrema_ExtPC::*)() const ) &BRepExtrema_ExtPC::NbExt, "Returns the number of extremum distances.");
	cls_BRepExtrema_ExtPC.def("IsMin", (Standard_Boolean (BRepExtrema_ExtPC::*)(const Standard_Integer) const ) &BRepExtrema_ExtPC::IsMin, "Returns True if the <N>th extremum distance is a minimum.", py::arg("N"));
	cls_BRepExtrema_ExtPC.def("SquareDistance", (Standard_Real (BRepExtrema_ExtPC::*)(const Standard_Integer) const ) &BRepExtrema_ExtPC::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
	cls_BRepExtrema_ExtPC.def("Parameter", (Standard_Real (BRepExtrema_ExtPC::*)(const Standard_Integer) const ) &BRepExtrema_ExtPC::Parameter, "Returns the parameter on the edge of the <N>th extremum distance.", py::arg("N"));
	cls_BRepExtrema_ExtPC.def("Point", (gp_Pnt (BRepExtrema_ExtPC::*)(const Standard_Integer) const ) &BRepExtrema_ExtPC::Point, "Returns the Point of the <N>th extremum distance.", py::arg("N"));
	cls_BRepExtrema_ExtPC.def("TrimmedSquareDistances", (void (BRepExtrema_ExtPC::*)(Standard_Real &, Standard_Real &, gp_Pnt &, gp_Pnt &) const ) &BRepExtrema_ExtPC::TrimmedSquareDistances, "if the curve is a trimmed curve, dist1 is a square distance between <P> and the point of parameter FirstParameter <pnt1> and dist2 is a square distance between <P> and the point of parameter LastParameter <pnt2>.", py::arg("dist1"), py::arg("dist2"), py::arg("pnt1"), py::arg("pnt2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_ExtPF.hxx
	py::class_<BRepExtrema_ExtPF, std::unique_ptr<BRepExtrema_ExtPF, Deleter<BRepExtrema_ExtPF>>> cls_BRepExtrema_ExtPF(mod, "BRepExtrema_ExtPF", "None");
	cls_BRepExtrema_ExtPF.def(py::init<>());
	cls_BRepExtrema_ExtPF.def(py::init<const TopoDS_Vertex &, const TopoDS_Face &>(), py::arg("TheVertex"), py::arg("TheFace"));
	cls_BRepExtrema_ExtPF.def(py::init<const TopoDS_Vertex &, const TopoDS_Face &, const Extrema_ExtFlag>(), py::arg("TheVertex"), py::arg("TheFace"), py::arg("TheFlag"));
	cls_BRepExtrema_ExtPF.def(py::init<const TopoDS_Vertex &, const TopoDS_Face &, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("TheVertex"), py::arg("TheFace"), py::arg("TheFlag"), py::arg("TheAlgo"));
	cls_BRepExtrema_ExtPF.def("Initialize", [](BRepExtrema_ExtPF &self, const TopoDS_Face & a0) -> void { return self.Initialize(a0); }, py::arg("TheFace"));
	cls_BRepExtrema_ExtPF.def("Initialize", [](BRepExtrema_ExtPF &self, const TopoDS_Face & a0, const Extrema_ExtFlag a1) -> void { return self.Initialize(a0, a1); }, py::arg("TheFace"), py::arg("TheFlag"));
	cls_BRepExtrema_ExtPF.def("Initialize", (void (BRepExtrema_ExtPF::*)(const TopoDS_Face &, const Extrema_ExtFlag, const Extrema_ExtAlgo)) &BRepExtrema_ExtPF::Initialize, "None", py::arg("TheFace"), py::arg("TheFlag"), py::arg("TheAlgo"));
	cls_BRepExtrema_ExtPF.def("Perform", (void (BRepExtrema_ExtPF::*)(const TopoDS_Vertex &, const TopoDS_Face &)) &BRepExtrema_ExtPF::Perform, "An exception is raised if the fields have not been initialized. Be careful: this method uses the Face only for classify not for the fields.", py::arg("TheVertex"), py::arg("TheFace"));
	cls_BRepExtrema_ExtPF.def("IsDone", (Standard_Boolean (BRepExtrema_ExtPF::*)() const ) &BRepExtrema_ExtPF::IsDone, "True if the distances are found.");
	cls_BRepExtrema_ExtPF.def("NbExt", (Standard_Integer (BRepExtrema_ExtPF::*)() const ) &BRepExtrema_ExtPF::NbExt, "Returns the number of extremum distances.");
	cls_BRepExtrema_ExtPF.def("SquareDistance", (Standard_Real (BRepExtrema_ExtPF::*)(const Standard_Integer) const ) &BRepExtrema_ExtPF::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
	cls_BRepExtrema_ExtPF.def("Parameter", (void (BRepExtrema_ExtPF::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &BRepExtrema_ExtPF::Parameter, "Returns the parameters on the Face of the <N>th extremum distance.", py::arg("N"), py::arg("U"), py::arg("V"));
	cls_BRepExtrema_ExtPF.def("Point", (gp_Pnt (BRepExtrema_ExtPF::*)(const Standard_Integer) const ) &BRepExtrema_ExtPF::Point, "Returns the Point of the <N>th extremum distance.", py::arg("N"));
	cls_BRepExtrema_ExtPF.def("SetFlag", (void (BRepExtrema_ExtPF::*)(const Extrema_ExtFlag)) &BRepExtrema_ExtPF::SetFlag, "None", py::arg("F"));
	cls_BRepExtrema_ExtPF.def("SetAlgo", (void (BRepExtrema_ExtPF::*)(const Extrema_ExtAlgo)) &BRepExtrema_ExtPF::SetAlgo, "None", py::arg("A"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_TriangleSet.hxx
	py::class_<BRepExtrema_TriangleSet, std::unique_ptr<BRepExtrema_TriangleSet, Deleter<BRepExtrema_TriangleSet>>, BVH_PrimitiveSet3d> cls_BRepExtrema_TriangleSet(mod, "BRepExtrema_TriangleSet", "Triangle set corresponding to specific face.");
	cls_BRepExtrema_TriangleSet.def(py::init<>());
	cls_BRepExtrema_TriangleSet.def(py::init<const BRepExtrema_ShapeList &>(), py::arg("theFaces"));
	cls_BRepExtrema_TriangleSet.def("Size", (Standard_Integer (BRepExtrema_TriangleSet::*)() const ) &BRepExtrema_TriangleSet::Size, "Returns total number of triangles.");
	cls_BRepExtrema_TriangleSet.def("Box", (BVH_Box<Standard_Real, 3> (BRepExtrema_TriangleSet::*)(const Standard_Integer) const ) &BRepExtrema_TriangleSet::Box, "Returns AABB of the given triangle.", py::arg("theIndex"));
	cls_BRepExtrema_TriangleSet.def("Center", (Standard_Real (BRepExtrema_TriangleSet::*)(const Standard_Integer, const Standard_Integer) const ) &BRepExtrema_TriangleSet::Center, "Returns centroid position along specified axis.", py::arg("theIndex"), py::arg("theAxis"));
	cls_BRepExtrema_TriangleSet.def("Swap", (void (BRepExtrema_TriangleSet::*)(const Standard_Integer, const Standard_Integer)) &BRepExtrema_TriangleSet::Swap, "Swaps indices of two specified triangles.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BRepExtrema_TriangleSet.def("Clear", (void (BRepExtrema_TriangleSet::*)()) &BRepExtrema_TriangleSet::Clear, "Clears triangle set data.");
	cls_BRepExtrema_TriangleSet.def("Init", (Standard_Boolean (BRepExtrema_TriangleSet::*)(const BRepExtrema_ShapeList &)) &BRepExtrema_TriangleSet::Init, "Initializes triangle set.", py::arg("theFaces"));
	cls_BRepExtrema_TriangleSet.def("GetVertices", (void (BRepExtrema_TriangleSet::*)(const Standard_Integer, BVH_Vec3d &, BVH_Vec3d &, BVH_Vec3d &) const ) &BRepExtrema_TriangleSet::GetVertices, "Returns vertices of the given triangle.", py::arg("theIndex"), py::arg("theVertex1"), py::arg("theVertex2"), py::arg("theVertex3"));
	cls_BRepExtrema_TriangleSet.def("GetFaceID", (Standard_Integer (BRepExtrema_TriangleSet::*)(const Standard_Integer) const ) &BRepExtrema_TriangleSet::GetFaceID, "Returns face ID of the given triangle.", py::arg("theIndex"));
	cls_BRepExtrema_TriangleSet.def_static("get_type_name_", (const char * (*)()) &BRepExtrema_TriangleSet::get_type_name, "None");
	cls_BRepExtrema_TriangleSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepExtrema_TriangleSet::get_type_descriptor, "None");
	cls_BRepExtrema_TriangleSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepExtrema_TriangleSet::*)() const ) &BRepExtrema_TriangleSet::DynamicType, "None");
	cls_BRepExtrema_TriangleSet.def("Box", (BVH_Box<double, 3> (BRepExtrema_TriangleSet::*)() const ) &BRepExtrema_TriangleSet::Box, "Returns AABB of primitive set.");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_OverlapTool.hxx
	py::class_<BRepExtrema_OverlapTool, std::unique_ptr<BRepExtrema_OverlapTool, Deleter<BRepExtrema_OverlapTool>>> cls_BRepExtrema_OverlapTool(mod, "BRepExtrema_OverlapTool", "Tool class for for detection of overlapping of two BVH primitive sets. This tool is not intended to be used independently, and is integrated in other classes, implementing algorithms based on shape tessellation (BRepExtrema_ShapeProximity and BRepExtrema_SelfIntersection).");
	cls_BRepExtrema_OverlapTool.def(py::init<>());
	cls_BRepExtrema_OverlapTool.def(py::init<const opencascade::handle<BRepExtrema_TriangleSet> &, const opencascade::handle<BRepExtrema_TriangleSet> &>(), py::arg("theSet1"), py::arg("theSet2"));
	cls_BRepExtrema_OverlapTool.def("LoadTriangleSets", (void (BRepExtrema_OverlapTool::*)(const opencascade::handle<BRepExtrema_TriangleSet> &, const opencascade::handle<BRepExtrema_TriangleSet> &)) &BRepExtrema_OverlapTool::LoadTriangleSets, "Loads the given element sets into the overlap tool.", py::arg("theSet1"), py::arg("theSet2"));
	cls_BRepExtrema_OverlapTool.def("Perform", [](BRepExtrema_OverlapTool &self) -> void { return self.Perform(); });
	cls_BRepExtrema_OverlapTool.def("Perform", (void (BRepExtrema_OverlapTool::*)(const Standard_Real)) &BRepExtrema_OverlapTool::Perform, "Performs searching of overlapped mesh elements.", py::arg("theTolerance"));
	cls_BRepExtrema_OverlapTool.def("IsDone", (Standard_Boolean (BRepExtrema_OverlapTool::*)() const ) &BRepExtrema_OverlapTool::IsDone, "Is overlap test completed?");
	cls_BRepExtrema_OverlapTool.def("MarkDirty", (void (BRepExtrema_OverlapTool::*)()) &BRepExtrema_OverlapTool::MarkDirty, "Marks test results as outdated.");
	cls_BRepExtrema_OverlapTool.def("OverlapSubShapes1", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_OverlapTool::*)() const ) &BRepExtrema_OverlapTool::OverlapSubShapes1, "Returns set of overlapped sub-shapes of 1st shape (currently only faces are detected).");
	cls_BRepExtrema_OverlapTool.def("OverlapSubShapes2", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_OverlapTool::*)() const ) &BRepExtrema_OverlapTool::OverlapSubShapes2, "Returns set of overlapped sub-shapes of 2nd shape (currently only faces are detected).");
	cls_BRepExtrema_OverlapTool.def("SetElementFilter", (void (BRepExtrema_OverlapTool::*)(BRepExtrema_ElementFilter *)) &BRepExtrema_OverlapTool::SetElementFilter, "Sets filtering tool for preliminary checking pairs of mesh elements.", py::arg("theFilter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_Poly.hxx
	py::class_<BRepExtrema_Poly, std::unique_ptr<BRepExtrema_Poly, Deleter<BRepExtrema_Poly>>> cls_BRepExtrema_Poly(mod, "BRepExtrema_Poly", "None");
	cls_BRepExtrema_Poly.def(py::init<>());
	cls_BRepExtrema_Poly.def_static("Distance_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &, gp_Pnt &, gp_Pnt &, Standard_Real &)) &BRepExtrema_Poly::Distance, "returns Standard_True if OK.", py::arg("S1"), py::arg("S2"), py::arg("P1"), py::arg("P2"), py::arg("dist"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_SelfIntersection.hxx
	py::class_<BRepExtrema_SelfIntersection, std::unique_ptr<BRepExtrema_SelfIntersection, Deleter<BRepExtrema_SelfIntersection>>, BRepExtrema_ElementFilter> cls_BRepExtrema_SelfIntersection(mod, "BRepExtrema_SelfIntersection", "Tool class for detection of self-sections in the given shape. This class is based on BRepExtrema_OverlapTool and thus uses shape tessellation to detect incorrect mesh fragments (pairs of overlapped triangles belonging to different faces). Thus, a result depends critically on the quality of mesh generator (e.g., BREP mesh is not always a good choice, because it can contain gaps between adjacent face triangulations, which may not share vertices on common edge; thus false overlap can be detected). As a result, this tool can be used for relatively fast approximated test which provides sub-set of potentially overlapped faces.");
	cls_BRepExtrema_SelfIntersection.def(py::init<>());
	cls_BRepExtrema_SelfIntersection.def(py::init<const Standard_Real>(), py::arg("theTolerance"));
	cls_BRepExtrema_SelfIntersection.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BRepExtrema_SelfIntersection.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("theShape"), py::arg("theTolerance"));
	cls_BRepExtrema_SelfIntersection.def("Tolerance", (Standard_Real (BRepExtrema_SelfIntersection::*)() const ) &BRepExtrema_SelfIntersection::Tolerance, "Returns tolerance value used for self-intersection test.");
	cls_BRepExtrema_SelfIntersection.def("SetTolerance", (void (BRepExtrema_SelfIntersection::*)(const Standard_Real)) &BRepExtrema_SelfIntersection::SetTolerance, "Sets tolerance value used for self-intersection test.", py::arg("theTolerance"));
	cls_BRepExtrema_SelfIntersection.def("LoadShape", (Standard_Boolean (BRepExtrema_SelfIntersection::*)(const TopoDS_Shape &)) &BRepExtrema_SelfIntersection::LoadShape, "Loads shape for detection of self-intersections.", py::arg("theShape"));
	cls_BRepExtrema_SelfIntersection.def("Perform", (void (BRepExtrema_SelfIntersection::*)()) &BRepExtrema_SelfIntersection::Perform, "Performs detection of self-intersections.");
	cls_BRepExtrema_SelfIntersection.def("IsDone", (Standard_Boolean (BRepExtrema_SelfIntersection::*)() const ) &BRepExtrema_SelfIntersection::IsDone, "True if the detection is completed.");
	cls_BRepExtrema_SelfIntersection.def("OverlapElements", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_SelfIntersection::*)() const ) &BRepExtrema_SelfIntersection::OverlapElements, "Returns set of IDs of overlapped sub-shapes (started from 0).");
	cls_BRepExtrema_SelfIntersection.def("GetSubShape", (const TopoDS_Face & (BRepExtrema_SelfIntersection::*)(const Standard_Integer) const ) &BRepExtrema_SelfIntersection::GetSubShape, "Returns sub-shape from the shape for the given index (started from 0).", py::arg("theID"));
	cls_BRepExtrema_SelfIntersection.def("ElementSet", (const opencascade::handle<BRepExtrema_TriangleSet> & (BRepExtrema_SelfIntersection::*)() const ) &BRepExtrema_SelfIntersection::ElementSet, "Returns set of all the face triangles of the shape.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_ShapeProximity.hxx
	py::class_<BRepExtrema_ShapeProximity, std::unique_ptr<BRepExtrema_ShapeProximity, Deleter<BRepExtrema_ShapeProximity>>> cls_BRepExtrema_ShapeProximity(mod, "BRepExtrema_ShapeProximity", "Tool class for shape proximity detection. For two given shapes and given tolerance (offset from the mesh) the algorithm allows to determine whether or not they are overlapped. The algorithm input consists of any shapes which can be decomposed into individual faces (used as basic shape elements). High performance is achieved through the use of existing triangulation of faces. So poly triangulation (with the desired deflection) should already be built. Note that solution is approximate (and corresponds to the deflection used for triangulation).");
	cls_BRepExtrema_ShapeProximity.def(py::init<>());
	cls_BRepExtrema_ShapeProximity.def(py::init<const Standard_Real>(), py::arg("theTolerance"));
	cls_BRepExtrema_ShapeProximity.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("theShape1"), py::arg("theShape2"));
	cls_BRepExtrema_ShapeProximity.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real>(), py::arg("theShape1"), py::arg("theShape2"), py::arg("theTolerance"));
	cls_BRepExtrema_ShapeProximity.def("Tolerance", (Standard_Real (BRepExtrema_ShapeProximity::*)() const ) &BRepExtrema_ShapeProximity::Tolerance, "Returns tolerance value for overlap test (distance between shapes).");
	cls_BRepExtrema_ShapeProximity.def("SetTolerance", (void (BRepExtrema_ShapeProximity::*)(const Standard_Real)) &BRepExtrema_ShapeProximity::SetTolerance, "Sets tolerance value for overlap test (distance between shapes).", py::arg("theTolerance"));
	cls_BRepExtrema_ShapeProximity.def("LoadShape1", (Standard_Boolean (BRepExtrema_ShapeProximity::*)(const TopoDS_Shape &)) &BRepExtrema_ShapeProximity::LoadShape1, "Loads 1st shape into proximity tool.", py::arg("theShape1"));
	cls_BRepExtrema_ShapeProximity.def("LoadShape2", (Standard_Boolean (BRepExtrema_ShapeProximity::*)(const TopoDS_Shape &)) &BRepExtrema_ShapeProximity::LoadShape2, "Loads 2nd shape into proximity tool.", py::arg("theShape2"));
	cls_BRepExtrema_ShapeProximity.def("Perform", (void (BRepExtrema_ShapeProximity::*)()) &BRepExtrema_ShapeProximity::Perform, "Performs search of overlapped faces.");
	cls_BRepExtrema_ShapeProximity.def("IsDone", (Standard_Boolean (BRepExtrema_ShapeProximity::*)() const ) &BRepExtrema_ShapeProximity::IsDone, "True if the search is completed.");
	cls_BRepExtrema_ShapeProximity.def("OverlapSubShapes1", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_ShapeProximity::*)() const ) &BRepExtrema_ShapeProximity::OverlapSubShapes1, "Returns set of IDs of overlapped faces of 1st shape (started from 0).");
	cls_BRepExtrema_ShapeProximity.def("OverlapSubShapes2", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_ShapeProximity::*)() const ) &BRepExtrema_ShapeProximity::OverlapSubShapes2, "Returns set of IDs of overlapped faces of 2nd shape (started from 0).");
	cls_BRepExtrema_ShapeProximity.def("GetSubShape1", (const TopoDS_Face & (BRepExtrema_ShapeProximity::*)(const Standard_Integer) const ) &BRepExtrema_ShapeProximity::GetSubShape1, "Returns sub-shape from 1st shape with the given index (started from 0).", py::arg("theID"));
	cls_BRepExtrema_ShapeProximity.def("GetSubShape2", (const TopoDS_Face & (BRepExtrema_ShapeProximity::*)(const Standard_Integer) const ) &BRepExtrema_ShapeProximity::GetSubShape2, "Returns sub-shape from 1st shape with the given index (started from 0).", py::arg("theID"));
	cls_BRepExtrema_ShapeProximity.def("ElementSet1", (const opencascade::handle<BRepExtrema_TriangleSet> & (BRepExtrema_ShapeProximity::*)() const ) &BRepExtrema_ShapeProximity::ElementSet1, "Returns set of all the face triangles of the 1st shape.");
	cls_BRepExtrema_ShapeProximity.def("ElementSet2", (const opencascade::handle<BRepExtrema_TriangleSet> & (BRepExtrema_ShapeProximity::*)() const ) &BRepExtrema_ShapeProximity::ElementSet2, "Returns set of all the face triangles of the 2nd shape.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_UnCompatibleShape.hxx
	py::class_<BRepExtrema_UnCompatibleShape, opencascade::handle<BRepExtrema_UnCompatibleShape>, Standard_DomainError> cls_BRepExtrema_UnCompatibleShape(mod, "BRepExtrema_UnCompatibleShape", "None");
	cls_BRepExtrema_UnCompatibleShape.def(py::init<>());
	cls_BRepExtrema_UnCompatibleShape.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_BRepExtrema_UnCompatibleShape.def_static("Raise_", (void (*)(const Standard_CString)) &BRepExtrema_UnCompatibleShape::Raise, "None", py::arg("theMessage"));
	cls_BRepExtrema_UnCompatibleShape.def_static("Raise_", (void (*)(Standard_SStream &)) &BRepExtrema_UnCompatibleShape::Raise, "None", py::arg("theMessage"));
	cls_BRepExtrema_UnCompatibleShape.def_static("NewInstance_", (opencascade::handle<BRepExtrema_UnCompatibleShape> (*)(const Standard_CString)) &BRepExtrema_UnCompatibleShape::NewInstance, "None", py::arg("theMessage"));
	cls_BRepExtrema_UnCompatibleShape.def_static("get_type_name_", (const char * (*)()) &BRepExtrema_UnCompatibleShape::get_type_name, "None");
	cls_BRepExtrema_UnCompatibleShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepExtrema_UnCompatibleShape::get_type_descriptor, "None");
	cls_BRepExtrema_UnCompatibleShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepExtrema_UnCompatibleShape::*)() const ) &BRepExtrema_UnCompatibleShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_SeqOfSolution.hxx
	bind_NCollection_Sequence<BRepExtrema_SolutionElem>(mod, "BRepExtrema_SeqOfSolution");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_MapOfIntegerPackedMapOfInteger.hxx
	bind_NCollection_DataMap<int, TColStd_PackedMapOfInteger, NCollection_DefaultHasher<int> >(mod, "BRepExtrema_MapOfIntegerPackedMapOfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepExtrema_TriangleSet.hxx
	bind_NCollection_Vector<TopoDS_Face>(mod, "BRepExtrema_ShapeList");


}
