
#ifndef MAME_CPU_ARM_ARMDASM_H
#define MAME_CPU_ARM_ARMDASM_H

#pragma once

class arm_disassembler : public util::disasm_interface
{
public:
	arm_disassembler();
	virtual u32 opcode_alignment() const override;
	virtual offs_t disassemble(std::ostream &stream, offs_t pc, const data_buffer &opcodes, const data_buffer &params) override;

private:
	void WriteImmediateOperand( std::ostream &stream, uint32_t opcode ) const;
	void WriteDataProcessingOperand( std::ostream &stream, uint32_t opcode, int printOp0, int printOp1, int printOp2 ) const;
	void WriteRegisterOperand1( std::ostream &stream, uint32_t opcode ) const;
	void WriteBranchAddress( std::ostream &stream, uint32_t pc, uint32_t opcode ) const;
	void WritePadding(std::ostream &stream, std::streampos start_position) const;

};

#endif
