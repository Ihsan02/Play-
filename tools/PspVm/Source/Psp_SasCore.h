#ifndef _PSP_SASCORE_H_
#define _PSP_SASCORE_H_

#include "PspModule.h"
#include "Iop_SpuBase.h"

namespace Psp
{
	class CSasCore : public CModule
	{
	public:
									CSasCore(uint8*);
		virtual						~CSasCore();

		void						Invoke(uint32, CMIPS&);
		std::string					GetName() const;

	private:
		struct SPUMEMBLOCK
		{
			uint32		address;
			uint32		size;
		};

		typedef std::list<SPUMEMBLOCK> MemBlockList;

		uint32						Init(uint32, uint32, uint32, uint32, uint32);
		uint32						Core(uint32, uint32);
		uint32						SetVoice(uint32, uint32, uint32, uint32, uint32);
		uint32						SetPitch(uint32, uint32, uint32);
		uint32						SetVolume(uint32, uint32, uint32, uint32, uint32, uint32);
		uint32						SetSimpleADSR(uint32, uint32, uint32, uint32);
		uint32						SetKeyOn(uint32, uint32);
		uint32						SetKeyOff(uint32, uint32);
		uint32						GetPauseFlag(uint32);
		uint32						GetEndFlag(uint32);
		uint32						GetAllEnvelope(uint32, uint32);

		uint32						AllocMemory(uint32);
		void						FreeMemory(uint32);

		Iop::CSpuBase::CHANNEL*		GetSpuChannel(uint32);

		enum SPURAMSIZE
		{
			SPURAMSIZE	= 0x400000,
		};

		Iop::CSpuBase*				m_spu[2];
		uint8*						m_spuRam;
		uint8*						m_ram;
		uint32						m_grain;

		MemBlockList				m_blocks;
	};
}

#endif
